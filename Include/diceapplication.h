
#ifndef diceapplication_h
#define diceapplication_h

#include "wx/wx.h"

namespace DDRoller
{
    class DiceApplication : public wxApp
    {
    public:
        DiceApplication() = default;
        DiceApplication(const DiceApplication& Other) = delete;
        DiceApplication(DiceApplication&& Other) = default;
        ~DiceApplication() = default;

        DiceApplication& operator=(const DiceApplication& Other) = delete;
        DiceApplication& operator=(DiceApplication&& Other) = default;

        int Run(int argc, char** argv);
        void LoadConfig();
        void CreateDefaultGUI();
        void IntializeGenerator();

        void WaitForEvent();
        void EventLoop();

        virtual bool OnInit();
    };//DiceApplication
}//DDRoller

#endif // diceapplication_h
