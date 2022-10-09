#pragma once

#include "gui.h"

#include <wx/generic/filedlgg.h>
#include <wx/dcbuffer.h>
#include "FreeImage.h"
#include "CImg.h"

#include <iostream>
#include <string>
#include <cmath>

class MainFrame : public MainFrameBase
{
private:
	bool _erode;
	bool _censorship;
	bool _animation;

	wxImage _imgOrg;
	wxImage _imgCopy;
	wxBitmap _animationFrames[60];

	wxSize _minSize;

private:
	void Censore() {
		// should be applied not on _imgOrg, but for our purposes it's ok
		auto img = wxImageToCImg(_imgOrg);

		int x0 = 450, y0 = 10, dx = 125, dy = 80;

		auto cropped = img.get_crop(x0, y0, x0 + dx, y0 + dy).blur(5);
		img.draw_image(x0, y0, cropped);
		_imgOrg = CImgTowxImage(img);
	}
	void Erode() {
		// should be applied not on _imgOrg, but for our purposes it's ok
		auto img = wxImageToCImg(_imgOrg);
		img.erode(5);
		_imgOrg = CImgTowxImage(img);
	}

	void Animate() {
		gauge_animation->Show();

		const int height = _imgCopy.GetSize().y;
		const int width = _imgCopy.GetSize().x;

		auto copy = wxImageToCImg(_imgCopy);

		float color[3] = { 1, 1, 1 };

		for (int i = 0; i < 60; i++)
		{
			gauge_animation->SetValue(i);

			auto gauss = cimg_library::CImg<float>(width, height, 1, 3);
			auto gauss2 = cimg_library::CImg<float>(width, height, 1, 3);

			gauss.draw_gaussian(
				(width / 2.) + (width * 0.3) * cos(i * M_PI / 60.f),
				(height / 2.) + (height * 0.3) * sin(i * M_PI / 60.f),
				120.0f,
				color,
				1.0f);

			gauss2.draw_gaussian(
				(width / 2.) + (width * 0.3) * cos((i + 60.f) * M_PI / 60.f),
				(height / 2.) + (height * 0.3) * sin((i + 60.f) * M_PI / 60.f),
				120.0f,
				color,
				1.0f);

			gauss += gauss2;

			cimg_library::CImg<float> tmp = copy;
			tmp.mul(gauss);
			auto frame = CImgTowxImage(tmp);

			_animationFrames[59 - i] = wxBitmap(frame);
		}

		gauge_animation->Hide();
	}

	void ProcessExif(const char* path) {
		FREE_IMAGE_FORMAT fif = FreeImage_GetFileType(path, 0);
		FIBITMAP* dib = FreeImage_Load(fif, path);

		unsigned int width = FreeImage_GetWidth(dib);
		unsigned int height = FreeImage_GetHeight(dib);

		txt_exif->Clear();
		txt_exif->AppendText(std::string("Image size: ") + std::to_string(width) + "x" + std::to_string(height) + "\n\n");

		txt_exif->AppendText("EXIF Info:\n");
		if (int count = FreeImage_GetMetadataCount(FIMD_EXIF_MAIN, dib))
		{
			DisplayExif(dib, FIMD_EXIF_MAIN);
		}
	}
	void DisplayExif(FIBITMAP* dib, FREE_IMAGE_MDMODEL model) {
		FITAG* tag = NULL;
		FIMETADATA* mdhandle = NULL;

		mdhandle = FreeImage_FindFirstMetadata(model, dib, &tag);

		if (mdhandle) {

			do {
				const char* tagKey = FreeImage_GetTagKey(tag);
				const char* tagValue = FreeImage_TagToString(model, tag);

				std::string exifStr = std::string(tagKey) + ": " + std::string(tagValue) + "\n";

				txt_exif->AppendText(exifStr);

			} while (FreeImage_FindNextMetadata(mdhandle, &tag));
		}

		FreeImage_FindCloseMetadata(mdhandle);
	}

	cimg_library::CImg<unsigned char> wxImageToCImg(wxImage image) {
		cimg_library::CImg<unsigned char> img(image.GetWidth(), image.GetHeight(), 1, 3);

		for (size_t x = 0; x < image.GetWidth(); x++)
		{
			for (size_t y = 0; y < image.GetHeight(); y++)
			{
				img(x, y, 0, 0) = image.GetRed(x, y);
				img(x, y, 0, 1) = image.GetGreen(x, y);
				img(x, y, 0, 2) = image.GetBlue(x, y);
			}
		}

		return img;
	}
	wxImage CImgTowxImage(cimg_library::CImg<unsigned char> image) {
		wxImage img(image.width(), image.height());

		for (size_t x = 0; x < img.GetWidth(); x++)
		{
			for (size_t y = 0; y < img.GetHeight(); y++)
			{
				img.SetRGB(x, y, image(x, y, 0, 0), image(x, y, 0, 1), image(x, y, 0, 2));
			}
		}

		return img;
	}

	void ProcessImageInit(wxString path)
	{
		auto stdStringPath = path.ToStdString();
		auto charPath = path.data();

		if (!_imgOrg.LoadFile(path))
		{
			wxMessageBox(_("Nie udalo sie zaladowac obrazka"));
			this->Destroy();
			return;
		}
		_imgCopy = _imgOrg.Copy();

		_erode = _censorship = _animation = false;
		checkBox_animation->SetValue(false);

		EnableControls();

		ProcessExif(charPath);

		FrameOnSize(wxSizeEvent());
	}
	void EnableControls() {
		btn_erode->Enable();
		btn_censorship->Enable();
		checkBox_animation->Enable();
	}

	void Repaint()
	{
		static unsigned frame_index = 0;
		static unsigned tick_delay = 0;

		wxClientDC dc1(panel_main);
		wxBufferedDC dc(&dc1);
		dc.Clear();

		if (_imgCopy.IsOk())
		{
			if (_animation)
			{
				dc.DrawBitmap(_animationFrames[frame_index], 0, 0);
				tick_delay = (tick_delay + 1) % 8;
				if (tick_delay >= 7) frame_index = (frame_index + 1) % 60;
				RefreshRect(wxRect(1, 1, 1, 1), false);

				return;
			}

			wxBitmap bitmap(_imgCopy);
			dc.DrawBitmap(bitmap, 0, 0);
		}
	}

public:
	MainFrame() : MainFrameBase(NULL), _minSize(this->GetMinSize()) { /*BtnImportClick(wxCommandEvent());*/ };

	void FrameOnSize(wxSizeEvent& event) override
	{
		if (_imgOrg.IsOk()) {
			int borderSize = 5; // default border size
			int newWidth = this->GetClientSize().GetWidth() - panel_main->GetPosition().x - borderSize;
			int newHeight = this->GetClientSize().GetHeight() - panel_main->GetPosition().y - borderSize;
			_imgCopy = _imgOrg.Scale(newWidth, newHeight);
		}

		event.Skip();
	}
	void FrameOnPaint(wxPaintEvent& event) override { Repaint(); event.Skip(); }
	void FrameOnUpdateUI(wxUpdateUIEvent& event)override { Repaint(); event.Skip(); }

	void BtnImportClick(wxCommandEvent& event) override
	{
		wxFileDialog saveFileDialog(this, "Choose a file", "", "", "Image Files (*.jpg)|*.jpg");
		if (saveFileDialog.ShowModal() == wxID_CANCEL) return;

		auto path = saveFileDialog.GetPath().ToStdString();

		ProcessImageInit(path);
		//ProcessImageInit("D:\\Desktop\\test.jpg");
	}

	void BtnCensorshipClick(wxCommandEvent& event) override
	{
		if (!_censorship) {
			Censore();
			_censorship = !_censorship;
		}

		FrameOnSize(wxSizeEvent());

		event.Skip();
	}
	void BtnErodeClick(wxCommandEvent& event) override
	{
		if (!_erode) {
			Erode();
			_erode = !_erode;
		}

		FrameOnSize(wxSizeEvent());

		event.Skip();
	}
	void CheckBoxAnimationOnCheck(wxCommandEvent& event) override {
		if (_animation = !_animation) {
			btn_censorship->Disable();
			btn_erode->Disable();
			this->SetMinSize(this->GetSize());
			this->SetMaxSize(this->GetSize());

			Animate();
		}
		else {
			this->SetMaxSize(wxSize(-1, -1));
			this->SetMinSize(_minSize);
			EnableControls();
		}

		event.Skip();
	}
};
