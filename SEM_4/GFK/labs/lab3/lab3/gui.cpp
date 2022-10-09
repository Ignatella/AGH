///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "gui.h"

///////////////////////////////////////////////////////////////////////////

MainFrameBase::MainFrameBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 500,400 ), wxDefaultSize );

	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxVERTICAL );

	panel_main = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	panel_main->SetBackgroundColour( wxColour( 255, 255, 255 ) );

	bSizer6->Add( panel_main, 1, wxEXPAND | wxALL, 5 );


	bSizer5->Add( bSizer6, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxVERTICAL );

	bSizer7->SetMinSize( wxSize( 150,-1 ) );
	btn_save = new wxButton( this, wxID_ANY, wxT("Save to file"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer7->Add( btn_save, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );

	checkBox_banana = new wxCheckBox( this, wxID_ANY, wxT("Banana"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer7->Add( checkBox_banana, 0, wxALIGN_CENTER|wxALL, 5 );

	slider_banana_pos = new wxSlider( this, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	slider_banana_pos->Enable( false );

	bSizer7->Add( slider_banana_pos, 0, wxALIGN_CENTER|wxALL, 5 );

	gauge_banana_pos = new wxGauge( this, wxID_ANY, 100, wxDefaultPosition, wxDefaultSize, wxGA_HORIZONTAL );
	gauge_banana_pos->SetValue( 0 );
	bSizer7->Add( gauge_banana_pos, 0, wxALIGN_CENTER|wxALL, 5 );

	btn_star_color = new wxButton( this, wxID_ANY, wxT("Star color"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer7->Add( btn_star_color, 0, wxALIGN_CENTER|wxALL, 5 );

	txt_box = new wxTextCtrl( this, wxID_ANY, wxT("text"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer7->Add( txt_box, 0, wxALIGN_CENTER|wxALL, 5 );

	comboBox_star = new wxComboBox( this, wxID_ANY, wxT("123"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	comboBox_star->Append( wxT("star") );
	comboBox_star->Append( wxT("moon") );
	comboBox_star->Append( wxT("sun") );
	comboBox_star->SetSelection( 0 );
	bSizer7->Add( comboBox_star, 0, wxALIGN_CENTER|wxALL, 5 );

	file_picker = new wxFilePickerCtrl( this, wxID_ANY, wxEmptyString, wxT("Select a file"), wxT("*.*"), wxDefaultPosition, wxDefaultSize, 0 );
	file_picker->Hide();

	bSizer7->Add( file_picker, 0, wxALL, 5 );


	bSizer5->Add( bSizer7, 0, wxEXPAND|wxRIGHT, 5 );


	this->SetSizer( bSizer5 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	this->Connect( wxEVT_PAINT, wxPaintEventHandler( MainFrameBase::MainFrameBase_OnPaint ) );
	this->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( MainFrameBase::MainFrameBase_OnUpdateUI ) );
	btn_save->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrameBase::btn_save_Click ), NULL, this );
	checkBox_banana->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MainFrameBase::checkBox_banana_Check ), NULL, this );
	slider_banana_pos->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MainFrameBase::slider_banana_pos_OnScroll ), NULL, this );
	slider_banana_pos->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MainFrameBase::slider_banana_pos_OnScroll ), NULL, this );
	slider_banana_pos->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MainFrameBase::slider_banana_pos_OnScroll ), NULL, this );
	slider_banana_pos->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MainFrameBase::slider_banana_pos_OnScroll ), NULL, this );
	slider_banana_pos->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MainFrameBase::slider_banana_pos_OnScroll ), NULL, this );
	slider_banana_pos->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MainFrameBase::slider_banana_pos_OnScroll ), NULL, this );
	slider_banana_pos->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MainFrameBase::slider_banana_pos_OnScroll ), NULL, this );
	slider_banana_pos->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MainFrameBase::slider_banana_pos_OnScroll ), NULL, this );
	slider_banana_pos->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MainFrameBase::slider_banana_pos_OnScroll ), NULL, this );
	btn_star_color->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrameBase::btn_star_color_Click ), NULL, this );
	comboBox_star->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( MainFrameBase::comboBox_star_OnCombobox ), NULL, this );
	file_picker->Connect( wxEVT_COMMAND_FILEPICKER_CHANGED, wxFileDirPickerEventHandler( MainFrameBase::file_picker_OnFileChanged ), NULL, this );
}

MainFrameBase::~MainFrameBase()
{
	// Disconnect Events
	this->Disconnect( wxEVT_PAINT, wxPaintEventHandler( MainFrameBase::MainFrameBase_OnPaint ) );
	this->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( MainFrameBase::MainFrameBase_OnUpdateUI ) );
	btn_save->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrameBase::btn_save_Click ), NULL, this );
	checkBox_banana->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MainFrameBase::checkBox_banana_Check ), NULL, this );
	slider_banana_pos->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MainFrameBase::slider_banana_pos_OnScroll ), NULL, this );
	slider_banana_pos->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MainFrameBase::slider_banana_pos_OnScroll ), NULL, this );
	slider_banana_pos->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MainFrameBase::slider_banana_pos_OnScroll ), NULL, this );
	slider_banana_pos->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MainFrameBase::slider_banana_pos_OnScroll ), NULL, this );
	slider_banana_pos->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MainFrameBase::slider_banana_pos_OnScroll ), NULL, this );
	slider_banana_pos->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MainFrameBase::slider_banana_pos_OnScroll ), NULL, this );
	slider_banana_pos->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MainFrameBase::slider_banana_pos_OnScroll ), NULL, this );
	slider_banana_pos->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MainFrameBase::slider_banana_pos_OnScroll ), NULL, this );
	slider_banana_pos->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MainFrameBase::slider_banana_pos_OnScroll ), NULL, this );
	btn_star_color->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrameBase::btn_star_color_Click ), NULL, this );
	comboBox_star->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( MainFrameBase::comboBox_star_OnCombobox ), NULL, this );
	file_picker->Disconnect( wxEVT_COMMAND_FILEPICKER_CHANGED, wxFileDirPickerEventHandler( MainFrameBase::file_picker_OnFileChanged ), NULL, this );

}
