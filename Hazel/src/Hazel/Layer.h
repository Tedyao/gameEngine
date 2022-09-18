#pragma once

#include "Core.h"
#include "Events/Event.h"
#include <string>


namespace Hazel {
	class HAZEL_API Layer {
	public:
		Layer(const std::string name = "Layer");
		~Layer();

		virtual void OnAttach();
		virtual void OnDetach();
		virtual void OnUpdate();
		virtual void OnImGuiRender();
		virtual void OnEvent(Event& e);

		inline const std::string GetDebugName() const {

			return m_DebugName;
		}

	private:
		std::string m_DebugName;

	};
}