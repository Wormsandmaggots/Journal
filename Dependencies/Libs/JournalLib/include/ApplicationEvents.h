//
// Created by 48782 on 15.07.2023.
//

#ifndef JOURNAL_APPLICATIONEVENTS_H
#define JOURNAL_APPLICATIONEVENTS_H
#include "Events.h"
#include "sstream"

namespace Journal
{
    class JR_API WindowResizeEvent : public Event
    {
    public:
        WindowResizeEvent(int height, int width) : _height(height), _width(width){}

        inline int GetHeight() const { return _height; }
        inline int GetWidth() const { return _width; }

        std::string ToString() const override
        {
            std::stringstream ss;

            ss << "WindowResizeEvent: height: " << _height << " width: " << _width;
            return ss.str();
        }

        EVENT_CLASS_TYPE(WindowResize)

        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    private:
        int _height, _width;
    };

    class JR_API WindowCloseEvent : public Event
    {
    public:
        WindowCloseEvent(){}

        EVENT_CLASS_TYPE(WindowClose)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    class JR_API WindowFocusEvent : public Event
    {
    public:
        WindowFocusEvent(){}

        EVENT_CLASS_TYPE(WindowFocus)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    class JR_API WindowLostFocusEvent : public Event
    {
    public:
        WindowLostFocusEvent(){}

        EVENT_CLASS_TYPE(WindowLostFocus)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    class JR_API WindowMovedEvent : public Event
    {
    public:
        WindowMovedEvent(){}

        EVENT_CLASS_TYPE(WindowMoved)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    class JR_API AppTickEvent : public Event
    {
    public:
        AppTickEvent() = default;

        EVENT_CLASS_TYPE(AppTick)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    class JR_API AppUpdateEvent : public Event
    {
    public:
        AppUpdateEvent() = default;

        EVENT_CLASS_TYPE(AppUpdate)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    class JR_API AppRenderEvent : public Event
    {
    public:
        AppRenderEvent() = default;

        EVENT_CLASS_TYPE(AppRender)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };
}

#endif //JOURNAL_APPLICATIONEVENTS_H
