// ChildEnabler.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

int _tmain(int argc, _TCHAR* argv[])
{
    for (::ShowWindow(::GetConsoleWindow(), SW_HIDE); ::IsWindowVisible(::GetConsoleWindow()); ::Sleep(1));
    for (HWND hChild = nullptr, hParent = []{ POINT CursorPos; return GetCursorPos(&CursorPos) ? WindowFromPoint(CursorPos) : nullptr; }();
        hChild = FindWindowExW(hParent, hChild, nullptr, nullptr);
        SetWindowLong(hChild, GWL_STYLE, GetWindowLong(hChild, GWL_STYLE) & ~WS_DISABLED | WS_TABSTOP));
    return 0;
}
