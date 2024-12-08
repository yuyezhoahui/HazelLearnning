#pragma once
#ifdef HZ_PLATFORM_WINDOWS


extern Hazel::Application* Hazel::CreateApplication();

int main(int argc, char** argv)
{

	Hazel::Log::Init();
	HZ_CORE_ERROR("Error");
	HZ_CLIENT_INFO("Info");

	//printf("Hazel Engine");
	auto app = Hazel::CreateApplication();
	app->Run();
	delete app;


}


#endif