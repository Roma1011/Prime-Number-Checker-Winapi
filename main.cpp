#if defined(UNICODE) && !defined(_UNICODE)
    #define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
    #define UNICODE
#endif

#include <tchar.h>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include "Global.h"
#include "Prime.cpp"
#include "AllocatorWinProces.cpp"
#include "WndRegistrProc.cpp"
/*  Declare Windows procedure  */
int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpszArguments,int nCmdShow)
{
MSG msg;
BOOL returnValue;
WndRegistrProc(hwndMainWind,hInstance);
hwndMainWind=CreateWindow("FRZ","Prime Checker"
				  ,WS_VISIBLE
				  |WS_OVERLAPPED
				  |WS_SYSMENU
				  |WS_MINIMIZEBOX
				  |WS_BORDER
				  |WS_DLGFRAME
				  |WS_CLIPCHILDREN
				  ,300,300
				  ,300,300
				  ,NULL,NULL,0,NULL);
	while(returnValue=GetMessage(&msg,0,0,0)!=0)
	{
		if(returnValue==-1)
		{
		MessageBox(hwndMainWind
			,TEXT("error Creating aplication")
			,TEXT("Error..")
			,MB_OK|MB_ICONERROR);
		exit(0);
		}
		else
		{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
		}
	}
return 0;
}
