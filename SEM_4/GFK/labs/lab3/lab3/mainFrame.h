#pragma once

#include "gui.h"
#include <wx/wxprec.h>
#include <wx/colordlg.h>
#include <wx/dcbuffer.h>
#include <wx/filefn.h> 

class MainFrame : public MainFrameBase
{
private:
	wxBitmap bitmap;
	wxBitmap bitmapBanana;
	wxColor currentColor;

	wxPoint star[5] = {
			wxPoint(-60, -80),
			wxPoint(-35, -35),
			wxPoint(-90, -60),
			wxPoint(-30, -60),
			wxPoint(-80, -35)
	};

private:
	void Draw()
	{
		std::unique_ptr<wxClientDC> clientDC(new wxClientDC(panel_main));
		bitmap = wxBitmap(panel_main->GetSize());
		std::unique_ptr<wxBufferedDC> buffer(new wxBufferedDC(clientDC.get(), bitmap));

		buffer->SetDeviceOrigin(panel_main->GetSize().x / 2, panel_main->GetSize().y / 2);

		buffer->SetBackground(*wxWHITE_BRUSH);
		buffer->Clear();

		double bananaFactor = 0.1 * gauge_banana_pos->GetValue() * sin(M_PI * gauge_banana_pos->GetValue() / 100);

		if (checkBox_banana->IsChecked())
			buffer->DrawBitmap(bitmapBanana, -40 - bananaFactor - bitmapBanana.GetWidth() / 2, 30 - 0.4 * gauge_banana_pos->GetValue() - bitmapBanana.GetWidth() / 2, true);

		buffer->DrawLine(0, 0, 0, 70); // body
		buffer->DrawLine(0, 10, -40 - bananaFactor, 30 - 0.4 * gauge_banana_pos->GetValue()); //right arm
		buffer->DrawLine(0, 10, 40, 30); // left arm
		buffer->DrawLine(0, 70, -30, 100); // right leg
		buffer->DrawLine(0, 70, 30, 100); // left leg

		buffer->DrawCircle(0, -20, 20);

		buffer->DrawEllipse(-12, -29, 9, 6);
		if (checkBox_banana->IsChecked())
		{
			buffer->DrawEllipticArc(-14, -16, 28, 5, 180, 360);
			buffer->DrawEllipse(3, -29, 9, 6);
		} else
		{
			buffer->DrawEllipticArc(-14, -16, 28, 5, 0, 180);
			buffer->DrawEllipse(4, -31, 6, 9);
		}

		wxString text(txt_box->GetValue());
		buffer->DrawText(text, -90, 90);
		wxString textRotated(txt_box->GetValue());
		buffer->SetFont(wxFont(40, wxFONTFAMILY_DECORATIVE, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, "Kalam"));
		buffer->DrawRotatedText(txt_box->GetValue(), 50, 100, 90);

		switch (comboBox_star->GetSelection())
		{
		case 0:
		buffer->SetBrush(wxBrush(currentColor));
		buffer->SetPen(wxPen(currentColor));
		buffer->DrawPolygon(5, star, 0, 0);
		break;

		case 1:
		buffer->SetBrush(*wxLIGHT_GREY_BRUSH);
		buffer->SetPen(*wxLIGHT_GREY_PEN);
		buffer->DrawCircle(-70, -70, 20);
		buffer->SetBrush(*wxWHITE_BRUSH);
		buffer->SetPen(*wxWHITE_PEN);
		buffer->DrawCircle(-80, -80, 20);
		buffer->SetBrush(*wxBLACK_BRUSH);
		buffer->SetPen(*wxBLACK_PEN);
		buffer->DrawCircle(-60, -70, 2);
		buffer->DrawLine(-70, -63, -64, -59);
		break;

		case 2:
		buffer->SetBrush(*wxYELLOW_BRUSH);
		buffer->SetPen(*wxYELLOW_PEN);
		buffer->DrawCircle(-70, -70, 20);
		break;

		default:
		break;
		}
	}

protected:
	virtual void MainFrameBase_OnPaint(wxPaintEvent& event) { Draw(); }

	virtual void MainFrameBase_OnUpdateUI(wxUpdateUIEvent& event) { Draw(); }

	virtual void btn_save_Click(wxCommandEvent& event)
	{
		wxFileDialog saveFileDialog(this, "Choose a file", "", "", "Image Files (*.png;*.bmp;*.jpg)|*.png;*.bmp;*.jpg", wxFD_SAVE | wxFD_OVERWRITE_PROMPT);
		if (saveFileDialog.ShowModal() == wxID_CANCEL) return;

		wxImage _imageSave = bitmap.ConvertToImage();
		_imageSave.AddHandler(new wxJPEGHandler);
		_imageSave.AddHandler(new wxBMPHandler);
		_imageSave.AddHandler(new wxPNGHandler);
		_imageSave.SaveFile(saveFileDialog.GetPath());
	}

	virtual void checkBox_banana_Check(wxCommandEvent& event)
	{
		slider_banana_pos->Enable(checkBox_banana->IsChecked());
	}

	virtual void slider_banana_pos_OnScroll(wxScrollEvent& event)
	{
		gauge_banana_pos->SetValue(event.GetPosition());
		Draw();
	}

	virtual void btn_star_color_Click(wxCommandEvent& event)
	{
		wxColourDialog chooseColourDialog(this, nullptr);
		if (chooseColourDialog.ShowModal() == wxID_CANCEL)
			return;

		currentColor = chooseColourDialog.GetColourData().GetColour();
	}

	virtual void comboBox_star_OnCombobox(wxCommandEvent& event) { event.Skip(); }

	virtual void file_picker_OnFileChanged(wxFileDirPickerEvent& event) { event.Skip(); }

public:

	MainFrame() : MainFrameBase(NULL)
	{
		wxImage imageBanana;
		imageBanana.AddHandler(new wxPNGHandler);
		imageBanana.LoadFile("banana.png", wxBITMAP_TYPE_PNG);
		bitmapBanana = wxBitmap(imageBanana);
	};
};
