///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/panel.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/checkbox.h>
#include <wx/slider.h>
#include <wx/gauge.h>
#include <wx/textctrl.h>
#include <wx/combobox.h>
#include <wx/filepicker.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MainFrameBase
///////////////////////////////////////////////////////////////////////////////
class MainFrameBase : public wxFrame
{
	private:

	protected:
		wxPanel* panel_main;
		wxButton* btn_save;
		wxCheckBox* checkBox_banana;
		wxSlider* slider_banana_pos;
		wxGauge* gauge_banana_pos;
		wxButton* btn_star_color;
		wxTextCtrl* txt_box;
		wxComboBox* comboBox_star;
		wxFilePickerCtrl* file_picker;

		// Virtual event handlers, override them in your derived class
		virtual void MainFrameBase_OnPaint( wxPaintEvent& event ) { event.Skip(); }
		virtual void MainFrameBase_OnUpdateUI( wxUpdateUIEvent& event ) { event.Skip(); }
		virtual void btn_save_Click( wxCommandEvent& event ) { event.Skip(); }
		virtual void checkBox_banana_Check( wxCommandEvent& event ) { event.Skip(); }
		virtual void slider_banana_pos_OnScroll( wxScrollEvent& event ) { event.Skip(); }
		virtual void btn_star_color_Click( wxCommandEvent& event ) { event.Skip(); }
		virtual void comboBox_star_OnCombobox( wxCommandEvent& event ) { event.Skip(); }
		virtual void file_picker_OnFileChanged( wxFileDirPickerEvent& event ) { event.Skip(); }


	public:

		MainFrameBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("GFK lab 3"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,400 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~MainFrameBase();

};

