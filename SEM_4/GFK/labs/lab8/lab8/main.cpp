#include <wx/wx.h>
#include "mainFrame.h"
#include "FreeImage.h"

#define FREEIMAGE_LIB

class MyApp : public wxApp {

public:
	virtual bool OnInit();
	virtual int OnExit() { FreeImage_DeInitialise(); return 0; }
};

IMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
	FreeImage_Initialise();
	wxInitAllImageHandlers();

	MainFrame* mainFrame = new MainFrame();
	mainFrame->Show(true);
	SetTopWindow(mainFrame);

	return true;
}