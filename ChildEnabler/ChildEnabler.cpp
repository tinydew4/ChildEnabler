// ChildEnabler.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

int _tmain(int argc, _TCHAR* argv[])
{
    for (HWND hChild = nullptr, hParent = []{ POINT CursorPos; return GetCursorPos(&CursorPos) ? WindowFromPoint(CursorPos) : nullptr; }();
        hChild = FindWindowExW(hParent, hChild, nullptr, nullptr);
        SetWindowLong(hChild, GWL_STYLE, GetWindowLong(hChild, GWL_STYLE) & ~WS_DISABLED | WS_TABSTOP));
    return 0;
}
