//
// Created by 48782 on 15.07.2023.
//

#ifndef JOURNAL_EVENTS_H
#define JOURNAL_EVENTS_H

#include "Core.h"
#include "string"
#include "functional"

namespace Journal
{
    enum class EventType
    {
        None = 0,
        WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
        AppTick, AppUpdate, AppRender,
        KeyPressed, KeyReleased, KeyTyped,
        MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
    };

    enum EventCategory
    {
        None = 0,
        EventCategoryApplication    = BIT(0),
        EventCategoryInput          = BIT(1),
        EventCategoryKeyboard       = BIT(2),
        EventCategoryMouse          = BIT(3),
        EventCategoryMouseButton    = BIT(4)
    };

#define EVENT_CLASS_CATEGORY(category) int GetCategoryFlags() const override { return category; }

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::type; }\
								EventType GetType() const override {return GetStaticType(); }\
								const char* GetName() const override { return #type; }

    class JR_API Event{
        friend class EventDispatcher;

    public:
        virtual EventType GetType() const = 0;
        virtual const char* GetName() const = 0;
        virtual int GetCategoryFlags() const = 0;
        virtual std::string ToString() const {return GetName();};

        inline bool IsInCategory(EventCategory category) {return GetCategoryFlags() & category;}

    protected:
        bool _handled;

    };

    class EventDispatcher{

        template<typename T>
        using EventFn = std::function<bool(T&)>;
    public:
        EventDispatcher(Event &event) : _event(event) {}

        template<typename T>
        bool Dispatch(EventFn<T> function)
        {
            if(_event.GetType() == T::GetStaticType())
            {
                _event._handled = func(*(T*)&_event);
                return true;
            }

            return false;
        }

    private:
        Event& _event;
    };
}
#endif //JOURNAL_EVENTS_H
