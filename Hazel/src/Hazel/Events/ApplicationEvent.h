#pragma once

#include "Event.h"

namespace Hazel {
	class HAZEL_API WindowResizeEvent : public Event {
	public:
		WindowResizeEvent(int weight, int height) 
		:m_Height(height), m_Width(weight) {

		}

		inline int getWindowHeight() const {
			return m_Height;
		}

		inline int getWindowWeight() const {
			return m_Width;
		}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "WindowResizeEvent: Width(" << m_Width << "), Height(" << m_Height << ")";
			return ss.str();
		}

		EVENT_CLASS_CATEGORY(EventCategoryApplication)
		EVENT_CLASS_TYPE(WindowResize)
	private:
		int m_Height, m_Width;
	};

	class HAZEL_API WindowCloseEvent : public Event {
	public:
		WindowCloseEvent() {

		}

		EVENT_CLASS_CATEGORY(EventCategoryApplication)
		EVENT_CLASS_TYPE(WindowClose)
	};

}