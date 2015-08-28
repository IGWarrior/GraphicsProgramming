//***********************************************************************
//	File: 			Main.cpp
//
//	System:			Project Title
//	Program Title:	Window Template
//	Program Author: Marcelo L. Garza
//	Email:			marcelo.garza.GProgrammer@gmail.com or
//					mgarza66@islander.tamucc.edu
//	Status: 		Version 1.0, Release Alpha
//	Language:		C++
//
//	(c)	Copyright
//
//	Address:		CompanyName, CompanyDivision
//					Physical Address,
//					City,State,Zip
//
//	Description:	CPP file for WindowTemplate
//					This is a basic window template, for any project
//					that needs a starting point using a window.
//
//	Limitations:	Program Limitations
//
//	Date: 			Insert Date
//***********************************************************************
#include <windows.h>

const char gWindow[] = "WindowClass";

//Function: Windows Callback Procedure
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch(msg)
    {
        case WM_CLOSE:
            DestroyWindow(hwnd);
        break;
        case WM_DESTROY:
            PostQuitMessage(0);
        break;
        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}

// Function: Main, Entry point into program
int WINAPI WinMain(	HINSTANCE hInstance, 
					HINSTANCE hPrevInstance,
					LPSTR lpCmdLine, 
					int nCmdShow)
{
    WNDCLASSEX wc;
    HWND hwnd;
    MSG Msg;

    //Step 1: Register Window Class
    wc.cbSize        = sizeof(WNDCLASSEX);
    wc.style         = 0;
    wc.lpfnWndProc   = WndProc;
    wc.cbClsExtra    = 0;
    wc.cbWndExtra    = 0;
    wc.hInstance     = hInstance;
    wc.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
    wc.lpszMenuName  = NULL;
    wc.lpszClassName = gWindow;
    wc.hIconSm       = LoadIcon(NULL, IDI_APPLICATION);

	//Note: If failed to register will display an error.
    if(!RegisterClassEx(&wc))
    {
        MessageBox(NULL, "Window Registration Failed!", "Error!",
            MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    // Note: Create the Window
    hwnd = CreateWindowEx(
        0,							/* Extended for variations possible */
        gWindow,					/* Classname */
        "WindowTitle",				/* Title Text */
        WS_OVERLAPPEDWINDOW,		/* Default Window */
        CW_USEDEFAULT, 				/* Windows default screen position */
		CW_USEDEFAULT, 				
		640, 						/* Height */
		480,						/* Width */
        HWND_DESKTOP, 				/* Indicator: Child-Window of Desktop */
		NULL, 						/* No Menu */
		hInstance, 					/* Program Instance Handler */
		NULL						/* No Window Creation data */
		);

    if(hwnd == NULL)
    {
        MessageBox(NULL, "Window Creation Failed!", "Error!",
            MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    // Note: Message Loop
    while(GetMessage(&Msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }
    return Msg.wParam;
}