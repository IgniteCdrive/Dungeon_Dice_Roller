
#include "diceframe.h"
#include "wx/wx.h"

namespace DDRoller
{
    wxBEGIN_EVENT_TABLE(DiceFrame, wxFrame)
        EVT_MENU(ID_Hello,   DiceFrame::OnHello)
        EVT_MENU(wxID_EXIT,  DiceFrame::OnExit)
        EVT_MENU(wxID_ABOUT, DiceFrame::OnAbout)
        //EVT_SIZE(DiceFrame::OnSize)
    wxEND_EVENT_TABLE()

    enum class ChildIDs
    {
        LeftPanel = 100,
        RightPanel = 200
    };

    enum FrameConsts
    {
        PanelMargin = 30
    };

    DiceFrame::DiceFrame(const wxString& title, const wxPoint& pos, const wxSize& size) :
        wxFrame(NULL, wxID_ANY, title, pos, size)
    {
        wxMenu* menuFile = new wxMenu;
        menuFile->Append(ID_Hello, "&Hello...\tCtrl-H",
                         "Help string shown in status bar for this menu item");
        menuFile->AppendSeparator();
        menuFile->Append(wxID_EXIT);
        wxMenu* menuHelp = new wxMenu;
        menuHelp->Append(wxID_ABOUT);
        wxMenuBar* menuBar = new wxMenuBar;
        menuBar->Append( menuFile, "&File" );
        menuBar->Append( menuHelp, "&Help" );
        this->SetMenuBar( menuBar );
        this->CreateStatusBar();
        this->SetStatusText( "Gay Baby Simulator 2018, Game of the year edition." );

        wxSize ClientArea = this->GetClientSize();
        wxBoxSizer* ButtonPanelSizer = new wxBoxSizer(wxVERTICAL);

        int LeftPanelID = static_cast<int>(ChildIDs::LeftPanel);
        int RightPanelID = static_cast<int>(ChildIDs::RightPanel);
        wxSize LeftPanelSize(100,ClientArea.GetHeight() - (PanelMargin * 2));
        wxSize RightPanelSize(100,ClientArea.GetHeight() - (PanelMargin * 2));
        wxPoint LeftPanelPos(PanelMargin,PanelMargin);
        wxPoint RightPanelPos(ClientArea.GetWidth() - RightPanelSize.GetWidth() - PanelMargin,PanelMargin);
        wxWindow* ButtonPanelLeft = new wxWindow(this,LeftPanelID,LeftPanelPos,LeftPanelSize,wxBORDER_SIMPLE);
        wxWindow* ButtonPanelRight = new wxWindow(this,RightPanelID,RightPanelPos,RightPanelSize,wxBORDER_SIMPLE);
        this->AddChild(ButtonPanelLeft);
        this->AddChild(ButtonPanelRight);
        //wxSizerFlags PanelFlags(1);
        //PanelFlags.CenterVertical().Expand().Left().Proportion(1);
        //ButtonPanelSizer->Add(ButtonPanel,PanelFlags);
        //this->SetSizerAndFit(ButtonPanelSizer);
    }

    void DiceFrame::OnHello(wxCommandEvent& event)
    {
        wxLogMessage("We all float down here!");
    }

    void DiceFrame::OnExit(wxCommandEvent& event)
    {
        Close( true );
    }

    void DiceFrame::OnAbout(wxCommandEvent& event)
    {
        wxMessageBox( "This is offensive to Canadians",
                  "Just A-boot", wxOK | wxICON_INFORMATION );
    }

    void DiceFrame::OnSize(wxSizeEvent& event)
    {
        event.Skip();
        wxSize ClientArea = this->GetClientSize();
        wxSize PanelSize(ClientArea.GetWidth() * 0.1,ClientArea.GetHeight() - (PanelMargin * 2));
        wxWindowList& Children = this->GetChildren();
        for( wxWindow* CurrChild : Children )
        {
            switch(CurrChild->GetId())
            {
                case static_cast<int>( ChildIDs::LeftPanel ):
                {
                    wxPoint LeftPos(PanelMargin,PanelMargin);
                    CurrChild->SetSize(wxRect(LeftPos,PanelSize));
                }
                case static_cast<int>( ChildIDs::RightPanel ):
                {
                    wxPoint RightPos(ClientArea.GetWidth() - PanelSize.GetWidth() - PanelMargin,PanelMargin);
                    CurrChild->SetSize(wxRect(RightPos,PanelSize));
                }
            }
        }
    }
}
