#include "GUIMyFrame1.h"
#include <math.h>
#include "vecmat.h"

GUIMyFrame1::GUIMyFrame1(wxWindow* parent)
	:
	MyFrame1(parent)
{
	m_staticText1->SetLabel(_(L"Jasno\u015B\u0107"));
	m_b_threshold->SetLabel(_(L"Pr\u00F3g 128"));
	this->SetBackgroundColour(wxColor(192, 192, 192));
	m_scrolledWindow->SetScrollbars(25, 25, 52, 40);
	m_scrolledWindow->SetBackgroundColour(wxColor(192, 192, 192));
}

void GUIMyFrame1::m_scrolledWindow_update(wxUpdateUIEvent& event)
{
	Repaint();
}

void GUIMyFrame1::m_s_brightness_scroll(wxScrollEvent& event)
{
	// Tutaj, w reakcji na zmiane polozenia suwaka, wywolywana jest funkcja
	// Brightness(...), ktora zmienia jasnosc. W tym miejscu nic nie
	// zmieniamy. Do uzupelnienia pozostaje funkcja Brightness(...)
	Brightness(m_s_brightness->GetValue() - 100);
	Repaint();
}


void GUIMyFrame1::m_s_contrast_scroll(wxScrollEvent& event)
{
	// Tutaj, w reakcji na zmiane polozenia suwaka, wywolywana jest funkcja
	// Contrast(...), ktora zmienia kontrast. W tym miejscu nic nie
	// zmieniamy. Do uzupelnienia pozostaje funkcja Contrast(...)
	Contrast(m_s_contrast->GetValue() - 100);
	Repaint();
}

void GUIMyFrame1::m_b_grayscale_click(wxCommandEvent& event)
{
	// TO DO: Konwersja do skali szarosci  
	Img_Cpy = Img_Org.ConvertToGreyscale();
}

void GUIMyFrame1::m_b_blur_click(wxCommandEvent& event)
{
	// TO DO: Rozmywanie obrazu (blur)
	Img_Cpy = Img_Org.Blur(5);
}

void GUIMyFrame1::m_b_mirror_click(wxCommandEvent& event)
{
	// TO DO: Odbicie lustrzane
	Img_Cpy = Img_Org.Mirror();
}

void GUIMyFrame1::m_b_replace_click(wxCommandEvent& event)
{
	// TO DO: Zamiana kolorow 
	Img_Cpy = Img_Org.Copy();
	Img_Cpy.Replace(254, 0, 0, 0, 0, 255);
}

void GUIMyFrame1::m_b_rescale_click(wxCommandEvent& event)
{
	// TO DO: Zmiana rozmiarow do 320x240
	Img_Cpy = Img_Org.Copy();
	Img_Cpy.Rescale(320, 240);
}

void GUIMyFrame1::m_b_rotate_click(wxCommandEvent& event)
{
	// TO DO: Obrot o 30 stopni
	Img_Cpy = Img_Org.Rotate(30 * M_PI / 180.0, wxPoint(Img_Org.GetSize().GetWidth() / 2, Img_Org.GetSize().GetHeight() / 2));
}

void GUIMyFrame1::m_b_rotate_hue_click(wxCommandEvent& event)
{
	// TO DO: Przesuniecie Hue o 180 stopni
	Img_Cpy = Img_Org.Copy();
	Img_Cpy.RotateHue(180.0 / 360.0);
}

void GUIMyFrame1::m_b_mask_click(wxCommandEvent& event)
{
	// TO DO: Ustawienie maski obrazu
	Img_Cpy = Img_Org.Copy();
	Img_Cpy.SetMaskFromImage(Img_Mask, 0, 0, 0);
}

void GUIMyFrame1::Brightness(int value)
{
	// TO DO: Zmiana jasnosci obrazu. value moze przyjmowac wartosci od -100 do 100
	Img_Cpy = Img_Org.Copy();
	unsigned char* data = Img_Cpy.GetData();
	size_t size = 3 * Img_Cpy.GetWidth() * Img_Cpy.GetHeight();

	for (size_t i = 0; i < size; i++)
	{
		if (data[i] + value < 0)
			data[i] = 0;
		else if (data[i] + value > 255)
			data[i] = 255;
		else
			data[i] = data[i] + value;
	}
}


void GUIMyFrame1::Contrast(double value)
{
	// TO DO: Zmiana kontrastu obrazu. value moze przyjmowac wartosci od -100 do 100
	Img_Cpy = Img_Org.Copy();
	unsigned char* data = Img_Cpy.GetData();
	size_t size = 3 * Img_Cpy.GetWidth() * Img_Cpy.GetHeight();

	value = value / 100. * 255.;
	value = 259 * (value + 255) / (255 * (259 - value)); // convert to 0 - 129.5


	for (size_t i = 0; i < size; i++)
	{
		int v = value * (data[i] - 128) + 128;

		if (v < 0)
			data[i] = 0;
		else if (v > 255)
			data[i] = 255;
		else
			data[i] = v;
	}
}

// returns gradient in the y direction
int yGradient(const wxImage& image, int x, int y)
{
	return
		+(int)image.GetRed(x - 1, y - 1)
		+ (int)image.GetRed(x - 1, y + 0)
		+ (int)image.GetRed(x - 1, y + 1)
		- (int)image.GetRed(x + 1, y - 1)
		- (int)image.GetRed(x + 1, y + 0)
		- (int)image.GetRed(x + 1, y + 1);
}

// returns gradient in the x direction { -1, -1, -1, 0, 0, 0, 1, 1, 1 };
int xGradient(const wxImage& image, int x, int y)
{
	return
		+(int)image.GetRed(x - 1, y - 1)
		+ (int)image.GetRed(x + 0, y - 1)
		+ (int)image.GetRed(x + 1, y - 1)
		- (int)image.GetRed(x - 1, y + 1)
		- (int)image.GetRed(x + 0, y + 1)
		- (int)image.GetRed(x + 1, y + 1);
}

void GUIMyFrame1::m_b_prewitt_click(wxCommandEvent& event)
{
	// TO DO: Pionowa maska Prewitta
	Img_Cpy = Img_Org.ConvertToGreyscale();
	wxImage Img_Tmp = Img_Cpy.Copy();

	unsigned char* data = Img_Tmp.GetData();
	int width = Img_Tmp.GetWidth();
	int height = Img_Tmp.GetHeight();

	int gx = 0;
	int gy = 0;
	int sum = 0;

	for (size_t y = 1; y < height - 1; y++)
	{
		for (size_t x = 1; x < width - 1; x++)
		{
			gx = xGradient(Img_Cpy, x, y);
			gy = yGradient(Img_Cpy, x, y);

			sum = sqrt(gx * gx + gy * gy);
			sum = sum > 255 ? 255 : sum;
			sum = sum < 0 ? 0 : sum;

			Img_Tmp.SetRGB(x, y, sum, sum, sum);
		}
	}

	Img_Cpy = Img_Tmp;
}

void GUIMyFrame1::m_b_threshold_click(wxCommandEvent& event)
{
	Img_Cpy = Img_Org.Copy();
	unsigned char* data = Img_Cpy.GetData();
	size_t size = 3 * Img_Cpy.GetWidth() * Img_Cpy.GetHeight();

	for (size_t i = 0; i < size; i++)
	{
		data[i] = data[i] > 128 ? 255 : 0;
	}
}


void GUIMyFrame1::Repaint()
{
	wxClientDC dc1(m_scrolledWindow);
	wxBufferedDC dc(&dc1);
	dc.Clear();

	wxBitmap bitmap(Img_Cpy);
	dc.DrawBitmap(bitmap, 0, 0, true);
}
