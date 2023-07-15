//
// Created by 48782 on 15.07.2023.
//

#ifndef JOURNAL_KEYEVENTS_H
#define JOURNAL_KEYEVENTS_H
#include "Events.h"
#include "sstream"

namespace Journal
{
    class JR_API KeyEvent : public Event
    {
    public:
        inline int GetKeyCode() const { return _keyCode; }

        EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)

    protected:
        KeyEvent(int keyCode) : _keyCode(keyCode){}

        int _keyCode;
    };

    class JR_API KeyPressed : public KeyEvent
    {
    public:
        KeyPressed(int keyCode, int repeatCount) : KeyEvent(keyCode), _repeat(repeatCount){}

        inline int GetRepeatCount() const { return _repeat; }
        std::string ToString() const override {
            std::stringstream ss;

            ss << "KeyPressed: " << _keyCode << " Repeat: " << _repeat;

            return ss.str();
        }

        EVENT_CLASS_TYPE(KeyPressed)
    private:
        int _repeat;
    };

    class JR_API KeyReleased : public KeyEvent
    {
    public:
        KeyReleased(int keyCode) : KeyEvent(keyCode){}

        std::string ToString() const override {
            std::stringstream ss;

            ss << "KeyPressed: " << _keyCode;

            return ss.str();
        }

        EVENT_CLASS_TYPE(KeyReleased)
    };
}
#endif //JOURNAL_KEYEVENTS_H
