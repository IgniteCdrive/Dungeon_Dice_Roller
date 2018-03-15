
#ifndef diceframe_h
#define diceframe_h

#include "wx/frame.h"
#include "enums.h"

namespace DDRoller
{
    class DiceFrame : public wxFrame
    {
    protected:
        void OnHello(wxCommandEvent& event);
        void OnExit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);

        wxDECLARE_EVENT_TABLE();
    public:
        DiceFrame() = delete;
        DiceFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
        DiceFrame(const DiceFrame& Other) = delete;
        DiceFrame(DiceFrame&& Other) = default;
        ~DiceFrame() = default;

        DiceFrame& operator=(const DiceFrame& Other) = delete;
        DiceFrame& operator=(DiceFrame&& Other) = default;
    };//DiceFrame
}//DDRoller

#endif // diceframe_h
