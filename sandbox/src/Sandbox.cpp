#include <dvigatel.h>

class ExampleLayer : public dvg::Layer {
public:
	ExampleLayer() : Layer("example") { }

	void OnUpdate() override {
		if (dvg::Input::IsKeyPressed(DVG_KEY_TAB))
			DVG_TRACE("TAB KEY IS PRESSED");
	}

	void OnEvent(dvg::Event& event) override {
		// DVG_TRACE("{0}", event);
	}
};

class Sandbox : public dvg::Application {
	public:
		Sandbox() {
			PushLayer(new ExampleLayer());
			PushLayer(new dvg::ImGuiLayer());
		}
		~Sandbox(){}
};


dvg::Application* dvg::CreateApplication() {
	return new Sandbox();
}
