/*
* OGLWindow.cpp
*
* Created on: Dec 31, 2013
* Author: Andrew Zhabura
*/

#include "OGLWindow.h"
#include "WinParent.h"

#include "ZGL/zglContext.h"

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

OGLWindow::OGLWindow(const char* name, const char* title)
	: m_ClassName(name)
	, m_WindowTitle(title)
	, m_context(NULL)
{
}

OGLWindow::~OGLWindow(void)
{
	delete [] m_ClassName;
	delete [] m_WindowTitle;
	delete m_context;
}

HWND OGLWindow::Init(HINSTANCE hInstance, HWND hParent, int x, int y, int w, int h)
{
	if ( !InitWindowClass(hInstance) )
		return NULL;

	return InitInstance(hInstance, hParent, x, y, w, h);
}

BOOL OGLWindow::InitWindowClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcx; 

	// Fill in the Window class structure with parameters 
	// that describe the main Window. 

	wcx.cbSize = sizeof(wcx);          // size of structure 
	wcx.style = CS_PARENTDC;          // use parent DC 
	wcx.lpfnWndProc = WndProc;     // points to Window procedure 
	wcx.cbClsExtra = 0;                // no extra class memory 
	wcx.cbWndExtra = 0;                // no extra Window memory 
	wcx.hInstance = hInstance;         // handle to instance 
	wcx.hIcon = LoadIcon(NULL, 
		IDI_APPLICATION);              // predefined app. icon 
	wcx.hCursor = LoadCursor(NULL, 
		IDC_ARROW);                    // predefined arrow 
	wcx.hbrBackground = (HBRUSH)GetStockObject( 
		BLACK_BRUSH);                  // white background brush 
	wcx.lpszMenuName =  NULL;    // name of menu resource 
	wcx.lpszClassName = m_ClassName;  // name of Window class 
	wcx.hIconSm = (HICON)LoadImage(hInstance, // small class icon 
		MAKEINTRESOURCE(5),
		IMAGE_ICON, 
		GetSystemMetrics(SM_CXSMICON), 
		GetSystemMetrics(SM_CYSMICON), 
		LR_DEFAULTCOLOR); 

	// Register the Window class. 
	return RegisterClassEx(&wcx); 
}

HWND OGLWindow::InitInstance(HINSTANCE hInstance, HWND hParent, int x, int y, int w, int h)
{
	// Create the main Window.
	HWND hWnd = CreateWindow( 
		m_ClassName,        // name of Window class 
		m_WindowTitle,       // title-bar string 
		WS_BORDER | WS_CHILD/* | WS_CLIPSIBLINGS | WS_CLIPCHILDREN*/, //  
		0,       // default horizontal position 
		0,       // default vertical position 
		1,       // default width 
		1,       // default height 
		hParent,         // no owner Window 
		(HMENU) NULL,        // use class menu 
		hInstance,           // handle to application instance 
		(LPVOID) NULL);      // no Window-creation data 

//	m_context = ZGL::zglContext::New(hWnd);

	m_width = w;
	m_height = h;

// 	MoveWindow(hWnd, x, y, w, h, FALSE);
// 	ShowWindow(hWnd, SW_HIDE); 

//	m_context->SetViewport(x, y, w, h);
	m_context->Show(false);
	m_context->MakeCurrent(true);

	return hWnd; 
}

void OGLWindow::Show()
{
	m_context->Show(true);
	Display();
}

void OGLWindow::Hide()
{
	m_context->Show(false);
}

void OGLWindow::Reshape(int width, int height)
{
	m_width = width;
	m_height = height;
}


void OGLWindow::keyboard( unsigned char key, int x, int y ) 
{
	switch(key)
	{
	case VK_UP:
		break;
	case VK_DOWN:
		break;
	case VK_LEFT:
		break;
	case VK_RIGHT:
		break;
	case VK_INSERT:
		break;
	case VK_SPACE:
		Display();
		break;
	default:
		break;
	}
}


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	return TRUE;//WinParent::Instance()->MainWindowLoop(hWnd, message, wParam, lParam);
}