#pragma once

#include <GLFW/glfw3.h>
#include "Hazel/Window.h"
#include "Hazel/Core.h"

#include "glad/glad.h"
#include "Hazel/Renderer/GraphicsContext.h"

namespace Hazel {
    class WindowsWindow : public Window {
    public:
        WindowsWindow(const WindowProps& props);
        virtual ~WindowsWindow();

        void OnUpdate() override;

        inline unsigned int GetWidth() const override {
            return m_Data.Width;
        }

        inline unsigned int GetHeight() const override {
            return m_Data.Height;
        }

        void SetVSync(bool enabled) override;
        bool IsVSync() const override;

        virtual void* GetNativeWindow() const override;

        void SetEventCallBack(const EventCallBackFn& callback);

    private:
        virtual void Init(const WindowProps& props);
        virtual void ShutDown();

    private:
        GLFWwindow* m_Window;
        GraphicsContext* m_Context;

        struct WindowData {
            std::string Title;
            unsigned int Width, Height;
            bool VSync;
            EventCallBackFn EventCallback;

        };

        WindowData m_Data;
    };

}