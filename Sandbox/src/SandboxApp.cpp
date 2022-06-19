#include <Hazel.h>
#include <stdio.h>

class ExampleLayer : public Hazel::Layer {
public:
	ExampleLayer()
		:Layer("Example") {

	}

	void OnUpdate() override {
		//HZ_INFO("ExampleLayer::OnUpdate");
	}

	void OnEvent(Hazel::Event& event) {
		HZ_TRACE(event);
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
