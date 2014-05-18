/*
* zglWindow.cpp
*
* Created on: Apr 24, 2014
* Author: Andrew Zhabura
*/

#include "zglWindow.h"

#include "zglContext.h"
#include "zglState.h"

#define MAJOR 4
#define MINOR 3

namespace ZGL
{
	/////////////////////////////////////////////////////////////////////////////////

	static const char s_wndObj[] = "winObject";
	static const char s_className[] = "zglOSWin_";
	static const char s_winTitle[] = "Example ";
	static int s_wndCounter = 0;

	LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	/////////////////////////////////////////////////////////////////////////////////

	template <
		class ContextPolicy,
		class StatePolicy
	>
	class zglWindowWin : public zglWindow
	{
	public:
		explicit zglWindowWin(zAPP_ID appID, zWIN_ID parentID)
			: m_context(NULL)
			, m_className(s_className)
			, m_state(MAJOR, MINOR)
			, m_hInstance(NULL)
			, m_hParent(NULL)
		{
			s_wndCounter++;
			m_className += std::to_string(s_wndCounter);

			m_state.SetWindowID(Init(appID, parentID));

			if (m_state.WindowID())
			{
				std::string title(s_winTitle);
				title += std::to_string(s_wndCounter);
				m_state.SetTitle(title);
				SetProp(m_state.WindowID(), s_wndObj, this);
				m_context = ContextPolicy::New(m_state);
			}
		}

		~zglWindowWin()
		{
			if (m_producer)
			{
				delete m_producer;
				delete m_context;
			}
			DestroyWindow(m_state.WindowID());
		}

		virtual void SetWindowRect(int left, int top, zSize width, zSize height)
		{
			m_state.SetWindowRect(left, top, width, height);
			m_state.SetViewportRect(left, top, width, height);
		}

		virtual const char * Title() const
		{
			return m_state.Title();
		}

		virtual zWIN_ID WinID() const
		{
			return m_state.WindowID();
		}

		virtual void SetOGLProducer(zglProducer* producer)
		{
			if (producer && m_context && m_context->MakeCurrent(true))
			{
				m_producer = producer;
				m_producer->InitGL();
			}
		}

		virtual void Show(bool b)
		{
			if (b)
			{
				m_context->UpdateViewport();
			}
			m_context->Show(b);
		}

		LRESULT WindowLoop(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
		{
			static int i = 0;
			switch(message)
			{
			case WM_CREATE:
				break;
			case WM_DESTROY:
				PostQuitMessage(0);
				break;
			case WM_SHOWWINDOW:
			case WM_PAINT:
				{
				int nWidth = LOWORD(lParam);
				int nHight = HIWORD(lParam);

				if (nWidth && nHight)
				{
					m_state.ResizeWindowRect(nWidth, nHight);
					m_state.ResizeViewportRect(nWidth, nHight);
					//m_context->Show(true);
					m_context->UpdateViewport();
				}
				if (m_producer)
				{
					m_producer->Display();
					m_context->Swap();
				}
				}
				break;
			case WM_SIZE:
				{
					int nWidth = LOWORD(lParam);
					int nHight = HIWORD(lParam);

					m_state.ResizeWindowRect(nWidth, nHight);
					m_state.ResizeViewportRect(nWidth, nHight);
				}
				break;
			case WM_KEYUP:
				switch(wParam)
				{
				case VK_SPACE:
						if (m_producer)
						{
							m_context->Show(true);
							m_context->UpdateViewport();
							m_producer->Display();
							m_context->Swap();
						}
						break;
				default:
					//				m_childArr[m_curChild]->keyboard(wParam, 0, 0);
					break;
				}
				break;
// 			case WM_SIZING:
// 				{
// 					// 			if (m_curChild < 0) break;
// 					// 			int nWidth = LOWORD(lParam);
// 					// 			int nHight = HIWORD(lParam);
// 					// 			m_childArr[m_curChild]->Reshape(nWidth, nHight);
// 					// 			m_childArr[m_curChild]->Show();
// 				}
				break;
			default:
				return DefWindowProc(hWnd, message, wParam, lParam);
			}

			return 0;
		}
		
		HWND Init(HINSTANCE appID, HWND parentID)
		{
			if ( !InitWindowClass(appID) )
				return NULL;

			m_hInstance = appID;

			return InitInstance(parentID);
		}

		BOOL InitWindowClass(HINSTANCE hInstance)
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
			wcx.lpszClassName = m_className.c_str();  // name of Window class 
			wcx.hIconSm = (HICON)LoadImage(hInstance, // small class icon 
				MAKEINTRESOURCE(5),
				IMAGE_ICON, 
				GetSystemMetrics(SM_CXSMICON), 
				GetSystemMetrics(SM_CYSMICON), 
				LR_DEFAULTCOLOR); 

			// Register the Window class. 
			return RegisterClassEx(&wcx); 
		}

		HWND InitInstance(HWND hParent)
		{
			// Create the main Window.
			HWND hWnd = CreateWindow( 
				m_className.c_str(),        // name of Window class 
				NULL,       // title-bar string 
				WS_BORDER | WS_CHILD/* | WS_CLIPSIBLINGS | WS_CLIPCHILDREN*/, //  
				0,       // default horizontal position 
				0,       // default vertical position 
				1,       // default width 
				1,       // default height 
				hParent,         // no owner Window 
				(HMENU) NULL,        // use class menu 
				m_hInstance,           // handle to application instance 
				(LPVOID) NULL);      // no Window-creation data 

			m_hParent = hParent;

			return hWnd; 
		}
	private:
		zglWindowWin();

		ContextPolicy *m_context;
		StatePolicy m_state;

		zglProducer *m_producer;

		std::string m_className;
		HINSTANCE m_hInstance;
		HWND m_hParent;
	};

	/////////////////////////////////////////////////////////////////////////////////

	typedef zglWindowWin<zglContext, zglState> ZGL_WIN;

	zglWindow* zglWindow::New(zAPP_ID appID, zWIN_ID parentID)
	{
		zglWindow* wnd = new ZGL_WIN(appID, parentID);

		return wnd;
	}

	LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		ZGL_WIN* wnd = (ZGL_WIN*)GetProp(hWnd, s_wndObj);
		if (wnd)
			return wnd->WindowLoop(hWnd, message, wParam, lParam);
		return DefWindowProc(hWnd, message, wParam, lParam);
	}

} // namespace ZGL
