#include "Application.h"

Application& Application::Instance()
{
    static Application instance;
    return instance;
}

bool Application::Init()
{
    auto result = CoInitializeEx(0, COINIT_MULTITHREADED);
    CreateApplicationWindow(hwnd_, windowClass_);
    
    return true;
}

void Application::Run()
{
    ShowWindow(hwnd_, SW_SHOW);
    
    MSG msg = {};
    
    while (true)
    {
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }

        if (msg.message == WM_QUIT)
        {
            break;
        }
    }
}

void Application::Terminate() const
{
    UnregisterClass(windowClass_.lpszClassName, windowClass_.hInstance);
}

Application::Application() : windowClass_(), hwnd_(nullptr), hInstance_(nullptr)
{
}

LRESULT WindowProcedure(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
    if (msg == WM_DESTROY)
    {
        PostQuitMessage(0);
        return 0;
    }

    // if (msg == WM_MOUSEMOVE)
    // {
    //     Input::Instance()->SetWMMouse(static_cast<int>(LOWORD(lparam)), static_cast<int>(HIWORD(lparam)));
    // }

    return DefWindowProc(hwnd, msg, wparam, lparam);
}

void Application::CreateApplicationWindow(HWND& hwnd, WNDCLASSEX& windowClass)
{
    hInstance_ = GetModuleHandle(nullptr);

    windowClass.cbSize = sizeof(WNDCLASSEX);
    windowClass.lpfnWndProc = static_cast<WNDPROC>(WindowProcedure);
    windowClass.lpszClassName = L"MiraiEngine";
    windowClass.hInstance = GetModuleHandle(nullptr);

    RegisterClassEx(&windowClass);

    RECT wrc = { 0, 0, 1600, 800 };

    AdjustWindowRect(&wrc, WS_OVERLAPPEDWINDOW, false);

    hwnd = CreateWindow(windowClass.lpszClassName,
        L"MiraiEngine",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        wrc.right - wrc.left,
        wrc.bottom - wrc.top,
        nullptr,
        nullptr,
        windowClass.hInstance,
        nullptr);
}
