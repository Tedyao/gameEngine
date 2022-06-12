#include "hzpch.h"
#include "Application.h"

namespace Hazel {

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)
	Application::Application() {
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallBack(BIND_EVENT_FN(OnEvent));
	}

	Application::~Application() {

	}

	void Application::OnEvent(Event& e) {
		EventDispatcher dispatcher(e);

		HZ_CORE_TRACE("{0}", e);

		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowCloseEvent));
	}


	void Application::Run() {
		Event* e = new WindowCloseEvent();
		HZ_CORE_INFO(e->GetName());
		WindowCloseEvent close = WindowCloseEvent();
		HZ_CORE_INFO(close);
		while (m_Running) {
			m_Window->OnUpdate();
		}
	}
	
	bool Application::OnWindowCloseEvent(WindowCloseEvent& e)
	{
		HZ_CORE_INFO("Handled window close event: {0}", e);
		m_Running = false;
		return true;
	}

}