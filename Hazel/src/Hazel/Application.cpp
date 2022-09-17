#include "hzpch.h"
#include "Application.h"
#include "LayerStack.h"
#include "glad/glad.h"
#include "Input.h"

namespace Hazel {

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)
	Application* Application::s_Instance = nullptr;

	Application::Application() {

		HZ_CORE_ASSERT(!s_Instance, "Application already exists");
		s_Instance = this;
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallBack(BIND_EVENT_FN(OnEvent));
	}

	Application::~Application() {

	}

	void Application::OnEvent(Event& e) {
		EventDispatcher dispatcher(e);

		HZ_CORE_TRACE("{0}", e);

		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowCloseEvent));

		for (auto iter = m_LayerStack.end(); iter != m_LayerStack.begin();) {
			(*--iter)->OnEvent(e);
			if (e.Handled()) {
				break;
			}
		}
	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverlay(Layer* overlay)
	{
		m_LayerStack.PushOverlay(overlay);
		overlay->OnAttach();
	}


	void Application::Run() {
		Event* e = new WindowCloseEvent();
		HZ_CORE_INFO(e->GetName());
		WindowCloseEvent close = WindowCloseEvent();
		HZ_CORE_INFO(close);
		while (m_Running) {
			auto[x, y] = Input::GetMousePosition();
			HZ_CORE_INFO("Mouse Pos: {0}, {1}", x, y);
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			for (Layer* layer : m_LayerStack) {
				layer->OnUpdate();
			}
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