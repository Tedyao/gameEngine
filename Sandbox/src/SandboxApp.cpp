#include <Hazel.h>
#include <stdio.h>

class ExampleLayer : public Hazel::Layer {
public:
	ExampleLayer()
		:Layer("Example") {

	}

	void OnUpdate() override {
		//HZ_INFO("ExampleLayer::OnUpdate");
		if (Hazel::Input::IsKeyPressed(HZ_KEY_TAB)) {
			HZ_INFO("Tab is pressed");
		}

		if (Hazel::Input::IsKeyPressed(HZ_KEY_SPACE)) {
			HZ_INFO("Space is pressed");
		}
	}

	void OnEvent(Hazel::Event& event) {
		//HZ_TRACE(event);
		if (event.GetEventType() == Hazel::EventType::KeyPressed) {
			Hazel::KeyPressedEvent& e = (Hazel::KeyPressedEvent&)event;
			HZ_INFO("{0}", (char)e.GetKeyCode());
		}
	}

	void OnAttach() override {

	}

	void OnDetach() override {

	}

};

class Sandbox : public Hazel::Application {
public:
	Sandbox() {
		PushLayer(new ExampleLayer());
		PushOverlay(new Hazel::ImGuiLayer());
	}

	~Sandbox() {

	}
};

Hazel::Application* Hazel::createApplication() {
	return new Sandbox();
}
