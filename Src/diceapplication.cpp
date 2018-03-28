
#include "diceapplication.h"
#include "diceframe.h"
#include "wx/wx.h"


namespace DDRoller
{
    int DiceApplication::Run(int argc, char** argv)
    {

    }

    void DiceApplication::LoadConfig()
    {

    }

    void DiceApplication::CreateDefaultGUI()
    {

    }

    void DiceApplication::IntializeGenerator()
    {

    }

    void DiceApplication::WaitForEvent()
    {

    }

    void DiceApplication::EventLoop()
    {

    }

    bool DiceApplication::OnInit()
    {
        DiceFrame* frame = new DiceFrame( "Charlotte's web is a web of lies.", wxPoint(50, 50), wxSize(800, 600) );
        frame->Show( true );
        return true;
    }
}

