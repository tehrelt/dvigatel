#pragma once

#include "Core.h"
#include "Events/Event.h"

#include "Window.h"
#include "dvigatel/LayerStack.h"
#include "dvigatel/Events/Event.h"
#include "dvigatel/Events/ApplicationEvent.h"

#include "dvigatel/ImGui/ImGuiLayer.h"
#include "dvigatel/Renderer/Shader.h"
#include "dvigatel/Renderer/Buffer.h"

namespace dvg {

	class DVG_API Application {
	public:
		Application();
		virtual ~Application();

		void Run();
		
		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
		
		inline Window& GetWindow() { return *m_Window;  }

		inline static Application& Get() { return *s_Instance;  }
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;

		unsigned int m_VertexArray;
		std::unique_ptr<Shader> m_Shader;
		std::unique_ptr<VertexBuffer> m_VertexBuffer;
		std::unique_ptr<IndexBuffer> m_IndexBuffer;
	private:
		static Application* s_Instance;
	};

	// to be defined in a client
	Application* CreateApplication();
}