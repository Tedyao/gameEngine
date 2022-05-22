#pragma once

#include "../Core.h"

#include <string>
#include <functional>

namespace Hazel {

    enum class EventType {
        None = 0,
        WindowClose, WindowResize, WindowFocus, WIndowLostFocus, WindowMoved, 
        AppTick, AppUpdate, AppRender,
        KeyPressed, KeyReleased,
        MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
    };

    enum EventCategory {
        None = 0,
        EventCategoryApplication    = BIT(0),
        EventCategoryInput          = BIT(1),
        EventCategoryKeyboard       = BIT(2),
        EventCategoryMouse          = BIT(3),
        EventCategoryMouseButton    = BIT(4)
    };

    class HAZEL_API Event {
        friend class EventDispatcher;
    public:
        virtual EventType GetEventType() const = 0;
        virtual const char* GetName() const = 0;
        virtual int GetCategoryFlags() const = 0;
        virtual std::string ToString() const { return GetName(); }

        inline bool IsInCategory(EventCategory category)
        {
            return GetCategoryFlags() & category;
        }
    protected:
        bool m_Handled = false;

    };

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() { return category; }
#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type} \
                                virtual EventType GFetEventType() { return GetStaticType(); }\
                                virtual const char* GetName() { return #type; }

    class EventDispatcher {
        template<typename T>
        using EventFn = std::function<bool(T&)>;
    public:
        EventDispatcher(Event& event) 
        :m_Event(event) {

        }

        template<typename T>
        bool Dispatch(EventFn<T> func) {
            if (m_Event.GetEventType() == T::GetStatictType()) {
                m_Event.m_handled = func(*(T*)&m_Event);
                return true;
            }
            return false;
        }
    private:
        Event& m_Event;
    };

}