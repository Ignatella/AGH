///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/intl.h>
#include <wx/panel.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/valtext.h>
#include <wx/sizer.h>
#include <wx/scrolbar.h>
#include <wx/radiobut.h>
#include <wx/choice.h>
#include <wx/button.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MyFrame1
///////////////////////////////////////////////////////////////////////////////
class MyFrame1 : public wxFrame
{
	private:

	protected:
		wxStaticText* m_staticText2;
		wxTextCtrl* WxEdit_x0;
		wxStaticText* m_staticText3;
		wxTextCtrl* WxEdit_y0;
		wxStaticText* m_staticText7;
		wxTextCtrl* WxEdit_x1;
		wxStaticText* m_staticText8;
		wxTextCtrl* WxEdit_y1;
		wxStaticText* m_staticText9;
		wxStaticText* m_staticText10;
		wxScrollBar* WxScrollBar_alpha;
		wxRadioButton* WxRB_Middle;
		wxRadioButton* WxRB_Center;
		wxStaticText* m_staticText81;
		wxStaticText* m_staticText91;
		wxTextCtrl* WxEdit_dX;
		wxStaticText* m_staticText101;
		wxTextCtrl* WxEdit_dY;
		wxStaticText* m_staticText12;
		wxTextCtrl* WxEdit_x_start;
		wxStaticText* m_staticText13;
		wxTextCtrl* WxEdit_x_stop;
		wxStaticText* m_staticText14;
		wxStaticText* Ly_min;
		wxStaticText* m_staticText16;
		wxStaticText* Ly_max;
		wxChoice* WxChoice;
		wxButton* m_button1;
		wxButton* m_button2;
		wxButton* m_button3;

		// Virtual event handlers, override them in your derived class
		virtual void MainFormClose( wxCloseEvent& event ) { event.Skip(); }
		virtual void WxPanel_LeftDown( wxMouseEvent& event ) { event.Skip(); }
		virtual void WxPanel_LeftUp( wxMouseEvent& event ) { event.Skip(); }
		virtual void WxPanel_Motion( wxMouseEvent& event ) { event.Skip(); }
		virtual void WxPanel_MouseWheel( wxMouseEvent& event ) { event.Skip(); }
		virtual void WxPanel_Repaint( wxUpdateUIEvent& event ) { event.Skip(); }
		virtual void WxEdit_x0_Update( wxCommandEvent& event ) { event.Skip(); }
		virtual void WxEdit_y0_Update( wxCommandEvent& event ) { event.Skip(); }
		virtual void WxEdit_x1_Update( wxCommandEvent& event ) { event.Skip(); }
		virtual void WxEdit_y1_Update( wxCommandEvent& event ) { event.Skip(); }
		virtual void WxScrollBar_alpha_Update( wxScrollEvent& event ) { event.Skip(); }
		virtual void WxRB_Middle_Click( wxCommandEvent& event ) { event.Skip(); }
		virtual void WxRB_Center_Click( wxCommandEvent& event ) { event.Skip(); }
		virtual void WxEdit_dX_Update( wxCommandEvent& event ) { event.Skip(); }
		virtual void WxEdit_dY_Update( wxCommandEvent& event ) { event.Skip(); }
		virtual void WxEdit_x_start_Update( wxCommandEvent& event ) { event.Skip(); }
		virtual void WxEdit_x_stop_Update( wxCommandEvent& event ) { event.Skip(); }
		virtual void WxChoice_Selected( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_button1_click( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_button2_click( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_button3_click( wxCommandEvent& event ) { event.Skip(); }


	public:
		wxPanel* WxPanel;
		wxStaticText* m_staticText1;
		wxStaticText* WxStaticText_alpha;
		wxStaticText* m_staticText11;

		MyFrame1( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("GFK Lab 03"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 777,497 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~MyFrame1();

};

