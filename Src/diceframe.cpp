
#include "diceframe.h"
#include "wx/wx.h"

namespace DDRoller
{
    wxBEGIN_EVENT_TABLE(DiceFrame, wxFrame)
        EVT_MENU(ID_Hello,   DiceFrame::OnHello)
        EVT_MENU(wxID_EXIT,  DiceFrame::OnExit)
        EVT_MENU(wxID_ABOUT, DiceFrame::OnAbout)
    wxEND_EVENT_TABLE()


    DiceFrame::DiceFrame(const wxString& title, const wxPoint& pos, const wxSize& size) :
        wxFrame(NULL, wxID_ANY, title, pos, size)
    {
        wxMenu *menuFile = new wxMenu;
        menuFile->Append(ID_Hello, "&Hello...\tCtrl-H",
                         "Help string shown in status bar for this menu item");
        menuFile->AppendSeparator();
        menuFile->Append(wxID_EXIT);
        wxMenu *menuHelp = new wxMenu;
        menuHelp->Append(wxID_ABOUT);
        wxMenuBar *menuBar = new wxMenuBar;
        menuBar->Append( menuFile, "&File" );
        menuBar->Append( menuHelp, "&Help" );
        SetMenuBar( menuBar );
        CreateStatusBar();
        SetStatusText( "Welcome to wxWidgets!" );
    }

    void DiceFrame::OnHello(wxCommandEvent& event)
    {
        wxLogMessage("Hello world from wxWidgets!");
    }

    void DiceFrame::OnExit(wxCommandEvent& event)
    {
        Close( true );
    }

    void DiceFrame::OnAbout(wxCommandEvent& event)
    {
        wxMessageBox( "This is a wxWidgets' Hello world sample",
                  "About Hello World", wxOK | wxICON_INFORMATION );
    }
}
