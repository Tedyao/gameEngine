#pragma once

#include "hzpch.h"
#include "Events/Event.h"
#include "Hazel/Core.h"
 
namespace Hazel {

    struct WindowProps {
        std::string Title;
        unsigned int Width;
        unsigned int Height;

        WindowProps(const std::string& title = "Hazel Engine",
            unsigned int width = 1280,
            unsigned int height = 720)
            :Title(title), Width(width), Height(height) {

        }
    };

    class HAZEL_API Window {
    public:
        using EventCallBackFn = std::function<void(Event&)>;

        virtual ~Window() {}

        virtual void OnUpdate() = 0;
        virtual unsigned int GetWidth() const = 0;
        virtual unsigned int GetHeight() const = 0;

        virtual void SetEventCallBack(const EventCallBackFn& callback) = 0;
        virtual void SetVSync(bool enabled) = 0;
        virtual bool IsVSync() const = 0;

        virtual void* GetNativeWindow() const = 0;
        
        static Window* Create(const WindowProps& props = WindowProps());

    
    };
}