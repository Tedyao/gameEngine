#pragma once
#ifdef HZ_PLATFORM_WINDOWS
extern Hazel::Application* Hazel::createApplication();

int main(int argc, char** argv) {
	Hazel::Log::Init();
	HZ_CORE_ERROR("ERROR from core macro.");
	int a = 10;
	HZ_ERROR("ERROR FORM CLIENT MACRO, VAR={0}", a);
	auto app = Hazel::createApplication();
	app->Run();
}
#endif
