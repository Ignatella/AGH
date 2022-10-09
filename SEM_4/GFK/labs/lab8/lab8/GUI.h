///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/button.h>
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/checkbox.h>
#include <wx/gauge.h>
#include <wx/textctrl.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MainFrameBase
///////////////////////////////////////////////////////////////////////////////
class MainFrameBase : public wxFrame
{
private:

protected:
	wxButton* btn_import;
	wxButton* btn_censorship;
	wxButton* btn_erode;
	wxCheckBox* checkBox_animation;
	wxGauge* gauge_animation;
	wxTextCtrl* txt_exif;
	wxPanel* panel_main;

	// Virtual event handlers, override them in your derived class
	virtual void FrameOnPaint(wxPaintEvent& event) { event.Skip(); }
	virtual void FrameOnSize(wxSizeEvent& event) { event.Skip(); }
	virtual void FrameOnUpdateUI(wxUpdateUIEvent& event) { event.Skip(); }
	virtual void BtnImportClick(wxCommandEvent& event) { event.Skip(); }
	virtual void BtnCensorshipClick(wxCommandEvent& event) { event.Skip(); }
	virtual void BtnErodeClick(wxCommandEvent& event) { event.Skip(); }
	virtual void CheckBoxAnimationOnCheck(wxCommandEvent& event) { event.Skip(); }


public:

	MainFrameBase(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("GFK lab 8"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(1075, 580), long style = wxDEFAULT_FRAME_STYLE | wxTAB_TRAVERSAL);

	~MainFrameBase();

};

