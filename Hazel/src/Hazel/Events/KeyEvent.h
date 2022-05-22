#pragma once

#include "Event.h"
#include "../Core.h"
#include <sstream>

namespace Hazel {
    class HAZEL_API KeyEvent: public Event {
    public:
        inline int GetKeyCode() const {
            return m_KeyCode;
        }
        EVENT_CLASS_CATEGORY(EventCategory::EventCategoryKeyboard);
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

        std::string ToString() {
            std::stringstream ss;
            ss << "KeyPressedEvent: " << m_KeyCode << " (" << m_RepeatedCount << " repeats)";
            return ss.str();
        }

    private:
        int m_RepeatedCount;
    };

}