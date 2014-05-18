/*
* WinParent.cpp
*
* Created on: Dec 31, 2013
* Author: Andrew Zhabura
*/

#include "winParent.h"
#include <algorithm>

#include "ZGL/zglWindow.h"
#include "Examples/ProducerEx01.h"

#define EXAMPLES_QTY 1
#define CUR_EXAMPLE EXAMPLES_QTY-1

LRESULT CALLBACK MainWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);


WinParent* WinParent::Instance()
{
	static WinParent* s_this = NULL;
	if (!s_this)
		s_this = new WinParent;

	return s_this;
}

WinParent::WinParent()
	: m_ClassName("MainWindow")
	, m_WindowTitle("Main Window Title")
	, m_hwnd(NULL)
	, m_curChild(-1)
{
}

void deleteOGL (ZGL::zglWindow* win)
{
	delete win;
}

WinParent::~WinParent()
{
	delete [] m_ClassName;
	delete [] m_WindowTitle;

	for_each (m_childArr.begin(), m_childArr.end(), deleteOGL);
}

BOOL WinParent::Init(HINSTANCE hInstance, int nCmdShow)
{
	// Save the application-instance handle. 
	m_hInstance = hInstance;

	return ( InitApplication() && InitInstance(nCmdShow) );
}

int WinParent::InitMainLoop()
{
	MSG msg; 

	BOOL fGotMessage;
	while ((fGotMessage = GetMessage(&msg, (HWND) NULL, 0, 0)) != 0 && fGotMessage != -1) 
	{ 
		TranslateMessage(&msg); 
		DispatchMessage(&msg); 
	} 
	return msg.wParam; 
}

BOOL WinParent::InitApplication()
{
	WNDCLASSEX wcx; 

	// Fill in the Window class structure with parameters 
	// that describe the main Window. 

	wcx.cbSize = sizeof(wcx);          // size of structure 
	wcx.style = CS_HREDRAW | 
		CS_VREDRAW;                    // redraw if size changes 
	wcx.lpfnWndProc = MainWndProc;     // points to Window procedure 
	wcx.cbClsExtra = 0;                // no extra class memory 
	wcx.cbWndExtra = 0;                // no extra Window memory 
	wcx.hInstance = m_hInstance;         // handle to instance 
	wcx.hIcon = LoadIcon(NULL, 
		IDI_APPLICATION);              // predefined app. icon 
	wcx.hCursor = LoadCursor(NULL, 
		IDC_ARROW);                    // predefined arrow 
	wcx.hbrBackground = (HBRUSH)GetStockObject( 
		WHITE_BRUSH);                  // white background brush 
	wcx.lpszMenuName =  NULL;    // name of menu resource 
	wcx.lpszClassName = m_ClassName;  // name of Window class 
	wcx.hIconSm = (HICON)LoadImage(m_hInstance, // small class icon 
		MAKEINTRESOURCE(5),
		IMAGE_ICON, 
		GetSystemMetrics(SM_CXSMICON), 
		GetSystemMetrics(SM_CYSMICON), 
		LR_DEFAULTCOLOR); 

	// Register the Window class. 
	return RegisterClassEx(&wcx); 
}

BOOL WinParent::InitInstance(int nCmdShow)
{
	// Create the main Window.
	m_hwnd = CreateWindow( 
		m_ClassName,        // name of Window class 
		m_WindowTitle,       // title-bar string 
		WS_OVERLAPPEDWINDOW, // top-level Window 
		CW_USEDEFAULT,       // default horizontal position 
		CW_USEDEFAULT,       // default vertical position 
		CW_USEDEFAULT,       // default width 
		CW_USEDEFAULT,       // default height 
		(HWND) NULL,         // no owner Window 
		(HMENU) NULL,        // use class menu 
		m_hInstance,           // handle to application instance 
		(LPVOID) NULL);      // no Window-creation data 

	if (!m_hwnd) 
		return FALSE;

	RECT mr;
	GetWindowRect(m_hwnd, &mr);
	RECT r;
	GetClientRect(m_hwnd, &r);

	int bound = ((mr.right - mr.left) - (r.right - r.left)) / 2;
	int header = (mr.bottom - mr.top) - (r.bottom - r.top) - bound;
	MoveWindow(m_hwnd, mr.left, mr.top, 512 + 2 * bound, 512 + header + bound, FALSE);

	// Show the Window and send a WM_PAINT message to the Window 
	// procedure. 
	ShowWindow(m_hwnd, nCmdShow); 

	GetClientRect(m_hwnd, &r);

	m_curChild = InitChilds(nCmdShow);
	SetWindowText(m_hwnd, m_childArr[m_curChild]->Title());
	m_childArr[m_curChild]->SetWindowRect(r.left, r.top, r.right - r.left, r.bottom - r.top);
	m_childArr[m_curChild]->Show(true);

	return TRUE; 
}

int WinParent::InitChilds(int nCmdShow)
{
	ZGL::zglWindow * child = ZGL::zglWindow::New(m_hInstance, m_hwnd);
	child->SetOGLProducer(new ProducerEx01);
	InitChild(child);
// 	child = ZGL::zglWindow::New(m_hInstance, m_hwnd);
// 	child->SetOGLProducer(new ProducerEx01);
// 	InitChild(child);

	if (m_childArr.size() != EXAMPLES_QTY)
		exit(1);

	return CUR_EXAMPLE;
}

void WinParent::InitChild(ZGL::zglWindow * child)
{
	RECT r;
	GetClientRect(m_hwnd, &r);

	child->SetWindowRect(r.left, r.top, r.right - r.left, r.bottom - r.top);
	m_childArr.push_back(child);
}

LRESULT WinParent::MainWindowLoop(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch(message)
	{
	case WM_CREATE:
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_SIZE:
		if (m_childArr.size() && m_hwnd == hWnd)
		{
			return SendMessage(m_childArr[m_curChild]->WinID(), WM_PAINT, wParam, lParam);
		}
//	case WM_SIZING:
 	case WM_PAINT:
		if (m_childArr.size())
		{
			if (m_childArr[m_curChild]->WinID() == hWnd)
			{
				SendMessage(m_childArr[m_curChild]->WinID(), message, wParam, lParam);
			}
		}
	case WM_KEYUP:
		switch(wParam)
		{
		case VK_ESCAPE:
			exit(EXIT_SUCCESS);
			break;
		case VK_F2:
			{
// 				int nWidth = m_childArr[m_curChild]->getWidth();
// 				int nHight = m_childArr[m_curChild]->getHeight();
// 				m_childArr[m_curChild]->Hide();
// 				m_curChild--;
// 				if (m_curChild < 0)
// 					m_curChild = EXAMPLES_QTY-1;
// 				SetWindowText(m_hwnd, m_childArr[m_curChild]->getTitle());
// 				m_childArr[m_curChild]->Reshape(nWidth, nHight);
// 				m_childArr[m_curChild]->Show();
			}
			break;
		case VK_F3:
			{
// 				int nWidth = m_childArr[m_curChild]->getWidth();
// 				int nHight = m_childArr[m_curChild]->getHeight();
// 				m_childArr[m_curChild]->Hide();
// 				m_curChild++;
// 				if (m_curChild >= EXAMPLES_QTY)
// 					m_curChild = 0;
// 				SetWindowText(m_hwnd, m_childArr[m_curChild]->getTitle());
// 				m_childArr[m_curChild]->Reshape(nWidth, nHight);
// 				m_childArr[m_curChild]->Show();
			}
			break;
		default:
			if (m_childArr.size())
			{
				return SendMessage(m_childArr[m_curChild]->WinID(), message, wParam, lParam);
			}
		}
		break;
// 	case WM_SIZING:
// 		{
// 			if (m_curChild < 0) break;
// 			int nWidth = LOWORD(lParam);
// 			int nHight = HIWORD(lParam);
// 			m_childArr[m_curChild]->Reshape(nWidth, nHight);
// 			m_childArr[m_curChild]->Show();
/*		}*/
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}

	return 0;
}

LRESULT CALLBACK MainWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	return WinParent::Instance()->MainWindowLoop(hWnd, message, wParam, lParam);
}