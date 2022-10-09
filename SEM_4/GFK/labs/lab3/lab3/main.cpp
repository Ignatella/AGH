#include <wx/wxprec.h>
#include "mainFrame.h"

class MyApp : public wxApp
{
public:
	virtual bool OnInit();
};

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
	MainFrame* fr = new MainFrame();
	fr->Show(true);
	return true;
}
