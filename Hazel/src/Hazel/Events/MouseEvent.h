#pragma once
#include "Event.h"

namespace Hazel {
    class HAZEL_API MouseMovedEvent: public Event {

    public:
        MouseMovedEvent(double x, double y) 
        :m_MouseX(x), m_MouseY(y) {

        }
        
        std::string ToString() const override {
            std::stringstream ss;
            ss << "MouseMovedEvent: MouseX(" << GetMouseX() << "), MouseY(" << GetMouseY() << ")";
            return ss.str();
        }

        inline double GetMouseX() const {
            return m_MouseX;
        }

        inline double GetMouseY() const {
            return m_MouseY;
        }
        EVENT_CLASS_TYPE(MouseMoved)
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
    private:
        double m_MouseX, m_MouseY;
    };

    class HAZEL_API MouseScrolledEvent: public Event {
    public:
        MouseScrolledEvent(float offsetX, float offsetY)
        :m_offsetX(offsetX), m_offsetY(offsetY) {

        }

        inline float GetOffsetX() const {
            return m_offsetX;
        }

        inline float GetOffsetY() const {
            return m_offsetY;
        }

        EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse)
        EVENT_CLASS_TYPE(MouseScrolled)

        std::string ToString() const override {
            std::stringstream ss;
            ss << "MouseScrolledEvent: x(" << m_offsetX << "), y(" << m_offsetY << ")";
            return ss.str();
        }

    private:
        float m_offsetX, m_offsetY;
    };

    class HAZEL_API MouseButtonEvent: public Event {
    public:
        inline int GetMouseButton() const {
            return m_MouseButton;
        }
        EVENT_CLASS_CATEGORY(EventCategoryInput|EventCategoryMouse)

    protected:
        MouseButtonEvent(int MouseButton)
        :m_MouseButton(MouseButton) {

        }
        int m_MouseButton;

    };

    class HAZEL_API MousePressedEvent: public MouseButtonEvent {
    public:
        MousePressedEvent(int MouseButton) 
        :MouseButtonEvent(MouseButton) {

        }

        std::string ToString() const override {
            std::stringstream ss;
            ss << "MouseButtonPressedEvent: " << m_MouseButton << "  Pressed";
            return ss.str();
        }
        EVENT_CLASS_TYPE(MouseButtonPressed)
    };

    class HAZEL_API MouseReleasedEvent: public MouseButtonEvent {
    public:
        MouseReleasedEvent(int MouseButton)
            :MouseButtonEvent(MouseButton) {

        }

        std::string ToString() const override {
            std::stringstream ss;
            ss << "MouseButtonReleasedEvent: " << m_MouseButton << "  Released";
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseButtonReleased)

    };

}