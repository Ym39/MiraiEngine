#pragma once
#include <windows.h>

class Application
{
public:
    static Application& Instance();
    
    bool Init();
    void Run();
    void Terminate() const;

    Application(const Application&) = delete;
    void operator=(const Application&) = delete;
    
    Application(Application&&) = delete;
    Application& operator=(Application&&) = delete;

private:
    Application();
    ~Application() = default;
    
    void CreateApplicationWindow(HWND& hwnd, WNDCLASSEX& windowClass);
    
private:
    WNDCLASSEX windowClass_;
    HWND hwnd_;
    HINSTANCE hInstance_;
};
