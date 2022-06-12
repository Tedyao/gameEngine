#pragma once

#include "Event.h"

namespace Hazel {
    class HAZEL_API KeyEvent: public Event {
    public:
        inline int GetKeyCode() const {
            return m_KeyCode;
        }
        EVENT_CLASS_CATEGORY(EventCategoryKeyboard)
   
    protected:
        KeyEvent(int keyCode)
        :m_KeyCode(keyCode) {

        }
        int m_KeyCode;
    };

    class HAZEL_API KeyPressedEvent: public KeyEvent {
    public:
        KeyPressedEvent(int keyCode, int repeatedCount)
        :KeyEvent(keyCode), m_RepeatedCount(repeatedCount) {

        }

        inline int getRepeatedCount() const {
            return m_RepeatedCount;
        }

        std::string ToString() const override {
            std::stringstream ss;
            ss << "KeyPressedEvent: " << m_KeyCode << " (" << m_RepeatedCount << " repeats)";
            return ss.str();
        }

        EVENT_CLASS_TYPE(KeyPressed)


    private:
        int m_RepeatedCount;
    };

    class HAZEL_API KeyReleasedEvent : public KeyEvent {
    public:
        KeyReleasedEvent(int keyCode)
            :KeyEvent(keyCode) {

        }

        std::string ToString() {
            std::stringstream ss;
            ss << "KeyPressedReleased: " << m_KeyCode;
            return ss.str();
        }

        EVENT_CLASS_TYPE(KeyReleased)
    };

}