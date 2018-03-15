
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
        DiceFrame* frame = new DiceFrame( "Hello World", wxPoint(50, 50), wxSize(450, 340) );
        frame->Show( true );
        return true;
    }
}

