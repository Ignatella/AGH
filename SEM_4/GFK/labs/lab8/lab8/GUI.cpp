///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "gui.h"

///////////////////////////////////////////////////////////////////////////

MainFrameBase::MainFrameBase(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : wxFrame(parent, id, title, pos, size, style)
{
	this->SetSizeHints(wxSize(500, 300), wxDefaultSize);

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer(wxHORIZONTAL);

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer(wxVERTICAL);

	bSizer2->SetMinSize(wxSize(250, -1));
	btn_import = new wxButton(this, wxID_ANY, wxT("Import"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer2->Add(btn_import, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 5);

	btn_censorship = new wxButton(this, wxID_ANY, wxT("Censorship"), wxDefaultPosition, wxDefaultSize, 0);
	btn_censorship->Enable(false);

	bSizer2->Add(btn_censorship, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 5);

	btn_erode = new wxButton(this, wxID_ANY, wxT("Erode"), wxDefaultPosition, wxDefaultSize, 0);
	btn_erode->Enable(false);

	bSizer2->Add(btn_erode, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 5);

	checkBox_animation = new wxCheckBox(this, wxID_ANY, wxT("Animate!"), wxDefaultPosition, wxDefaultSize, 0);
	checkBox_animation->Enable(false);

	bSizer2->Add(checkBox_animation, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 5);

	gauge_animation = new wxGauge(this, wxID_ANY, 59, wxDefaultPosition, wxDefaultSize, wxGA_HORIZONTAL);
	gauge_animation->SetValue(0);
	gauge_animation->Hide();

	bSizer2->Add(gauge_animation, 0, wxALIGN_CENTER_HORIZONTAL | wxALL | wxRESERVE_SPACE_EVEN_IF_HIDDEN, 5);

	txt_exif = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_BESTWRAP | wxTE_CHARWRAP | wxTE_MULTILINE | wxTE_NO_VSCROLL | wxTE_READONLY | wxTE_WORDWRAP);
	bSizer2->Add(txt_exif, 1, wxALL | wxEXPAND, 5);


	bSizer1->Add(bSizer2, 0, wxEXPAND, 5);

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer(wxVERTICAL);

	panel_main = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	panel_main->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_3DDKSHADOW));

	bSizer3->Add(panel_main, 1, wxALL | wxEXPAND, 5);


	bSizer1->Add(bSizer3, 1, wxEXPAND, 5);


	this->SetSizer(bSizer1);
	this->Layout();

	this->Centre(wxBOTH);

	// Connect Events
	this->Connect(wxEVT_PAINT, wxPaintEventHandler(MainFrameBase::FrameOnPaint));
	this->Connect(wxEVT_SIZE, wxSizeEventHandler(MainFrameBase::FrameOnSize));
	this->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(MainFrameBase::FrameOnUpdateUI));
	btn_import->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrameBase::BtnImportClick), NULL, this);
	btn_censorship->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrameBase::BtnCensorshipClick), NULL, this);
	btn_erode->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrameBase::BtnErodeClick), NULL, this);
	checkBox_animation->Connect(wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler(MainFrameBase::CheckBoxAnimationOnCheck), NULL, this);
}

MainFrameBase::~MainFrameBase()
{
	// Disconnect Events
	this->Disconnect(wxEVT_PAINT, wxPaintEventHandler(MainFrameBase::FrameOnPaint));
	this->Disconnect(wxEVT_SIZE, wxSizeEventHandler(MainFrameBase::FrameOnSize));
	this->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(MainFrameBase::FrameOnUpdateUI));
	btn_import->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrameBase::BtnImportClick), NULL, this);
	btn_censorship->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrameBase::BtnCensorshipClick), NULL, this);
	btn_erode->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrameBase::BtnErodeClick), NULL, this);
	checkBox_animation->Disconnect(wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler(MainFrameBase::CheckBoxAnimationOnCheck), NULL, this);

}
