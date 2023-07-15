//
// Created by 48782 on 15.07.2023.
//

#ifndef JOURNAL_MOUSEEVENTS_H
#define JOURNAL_MOUSEEVENTS_H
#include "Events.h"
#include "sstream"

namespace Journal
{
    class JR_API MouseMovedEvent : public Event
    {
    public:
        MouseMovedEvent(float x, float y) : _x(x), _y(y){}

        inline float GetX() const { return _x; }
        inline float GetY() const { return _y; }

        std::string ToString() const override{
            std::stringstream ss;

            ss << "MouseMovedEvent: " << _x << " " << _y;
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseMoved)

        EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse)

    private:
        float _x,_y;
    };

    class JR_API MouseScrolledEvent : public Event
    {
    public:
        MouseScrolledEvent(float xOffset, float yOffset) : _xOffset(xOffset), _yOffset(yOffset){}

        inline float GetXOffset() const { return _xOffset; }
        inline float GetYOffset() const { return _yOffset; }

        std::string ToString() const override{
            std::stringstream ss;

            ss << "MouseScrolledEvent: " << _xOffset << " " << _yOffset;
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseScrolled)

        EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse)

    private:
        float _xOffset, _yOffset;
    };

    class JR_API MouseButtonEvent : public Event
    {
    public:
        inline int GetKeyCode() const { return _keyCode; }

        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

    protected:
        MouseButtonEvent(int keyCode) : _keyCode(keyCode){}

        int _keyCode;
    };

    class JR_API MouseButtonPressed : public MouseButtonEvent
    {
    public:
        MouseButtonPressed(int keyCode) : MouseButtonEvent(keyCode){}

        std::string ToString() const override
        {
            std::stringstream ss;

            ss << "MouseButtonPressed: " << _keyCode;
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseButtonPressed)
    };

    class JR_API MouseButtonReleased : public MouseButtonEvent
    {
    public:
        MouseButtonReleased(int keyCode) : MouseButtonEvent(keyCode){}

        std::string ToString() const override
        {
            std::stringstream ss;

            ss << "MouseButtonReleased: " << _keyCode;
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseButtonReleased)
    };
}
#endif //JOURNAL_MOUSEEVENTS_H
