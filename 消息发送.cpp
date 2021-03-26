#include<stdio.h>
#include<windows.h>
#include<stdlib.h>


int main()
{
	HWND hwnd2 = FindWindow(L"TXGuiFoundation", L".");
	if (hwnd2 == NULL)return 0;

	TCHAR text[256] = TEXT("123");
	for (int j = 0; j < 20; j++) {
		for (int i = 0; i < lstrlen(text); i++)
		{
			SendMessage(hwnd2, WM_IME_CHAR, text[i], 0);
		}

		Sleep(30);
		SendMessage(hwnd2, WM_KEYDOWN, VK_RETURN, 0);
		//等待500毫秒后向qq窗口发送回车，前提是你qq设置了回车发送消息
		Sleep(50);
	}

}
