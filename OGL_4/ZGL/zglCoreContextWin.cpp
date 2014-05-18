/*
* zglContext.cpp
*
* Created on: Apr 24, 2014
* Author: Andrew Zhabura
*/

#include "zglContext.h"

#include "zglLoaderWin.h"
#include "zglState.h"

#define MAJOR 4
#define MINOR 3

namespace ZGL
{

	class zglCoreContextWin : public zglContext
	{
	public:
		zglCoreContextWin(const zglState& state);
		~zglCoreContextWin();

		virtual bool MakeCurrent(bool b);
		virtual void Show(bool b);
		virtual void UpdateViewport();
		virtual void Swap();

	private:
		bool CreateContext();
		bool CreateCoreContext();
		void GetGLVersion(int* major, int* minor);
		bool LoadGL();

		const zglState& m_state;

		HDC m_hDC;
		HGLRC m_Context;
		HGLRC m_tempContext;

		static bool m_glLoaded;
		static int m_major;
		static int m_minor;
	};

	bool zglCoreContextWin::m_glLoaded = false;
	int zglCoreContextWin::m_major = 0;
	int zglCoreContextWin::m_minor = 0;

	zglCoreContextWin::zglCoreContextWin(const zglState& state)
		: m_state(state)
		, m_hDC(NULL)
		, m_Context(NULL)
		, m_tempContext(NULL)
	{
		CreateContext();
	}

	zglCoreContextWin::~zglCoreContextWin()
	{
	}

	bool zglCoreContextWin::MakeCurrent(bool b)
	{
		if (b)
			return wglMakeCurrent( m_hDC, m_Context );
		else
			return wglMakeCurrent( NULL, NULL );
	}

	void zglCoreContextWin::Show(bool b)
	{
		if (b)
		{
			zRect winRect = m_state.WindowRect();
			MoveWindow(m_state.WindowID(), winRect.left, winRect.top, winRect.width, winRect.height, FALSE);
			ShowWindow(m_state.WindowID(), SW_SHOW); 
			UpdateWindow(m_state.WindowID());
		}
		else
		{
			ShowWindow(m_state.WindowID(), SW_HIDE); 
			UpdateWindow(m_state.WindowID());
		}
	}

	void zglCoreContextWin::UpdateViewport()
	{
		zRect winRect = m_state.WindowRect();
		MoveWindow(m_state.WindowID(), winRect.left, winRect.top, winRect.width, winRect.height, FALSE);
		zRect viewRect = m_state.ViewportRect();
		glViewport(viewRect.left, viewRect.top, viewRect.width, viewRect.height);
	}

	bool zglCoreContextWin::CreateContext()
	{
		if ( m_Context )
			return false;

		// get the device context (DC)
		m_hDC = GetDC( m_state.WindowID() );

		// prepare the pixel format for the DC
		PIXELFORMATDESCRIPTOR pfd;
		ZeroMemory( &pfd, sizeof( pfd ) );
		pfd.nSize = sizeof( pfd );
		pfd.nVersion = 1;
		pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
		pfd.iPixelType = PFD_TYPE_RGBA;
		pfd.cColorBits = 32;
		pfd.cDepthBits = 32;
		pfd.iLayerType = PFD_MAIN_PLANE;
		int pixelFormat = ChoosePixelFormat( m_hDC, &pfd );

		if ( ! pixelFormat )
			return false;

		// Check whether we get hardware accelerated pixel format or not
		ZeroMemory( &pfd, sizeof( pfd ) );
		if ( ! DescribePixelFormat(m_hDC, pixelFormat, sizeof(pfd), &pfd) )
			return false;

		// We got software-accelerated pixel format, but we use it now for 
		// Windows Remote Desktop
		//if ( pfd.dwFlags & PFD_GENERIC_FORMAT )
		//	return false;

		// set the pixel format for the DC
		BOOL bSetPF = SetPixelFormat( m_hDC, pixelFormat, &pfd );
		if ( ! bSetPF )
			return false;

		// create the render context (RC)
		m_tempContext = wglCreateContext( m_hDC );

		if ( !m_tempContext )
			return false;

		return CreateCoreContext();
	}

	bool zglCoreContextWin::CreateCoreContext()
	{
		if ( !m_tempContext )
			return false;

		bool makeCurResult = wglMakeCurrent( m_hDC, m_tempContext );

		bool bCore = GL_LoadCreateWinCoreContext();

		if (!bCore)
			return false;

		GetGLVersion(&m_major, &m_minor);

		if( !makeCurResult || m_major < MAJOR || ( m_major == MAJOR && m_minor < MINOR ) )
		{
			wglMakeCurrent(NULL,NULL); 
			wglDeleteContext(m_tempContext);
			return false;
		}

		int attribs[] =
		{
			WGL_CONTEXT_MAJOR_VERSION_ARB, m_major,
			WGL_CONTEXT_MINOR_VERSION_ARB, m_minor, 
			WGL_CONTEXT_FLAGS_ARB, WGL_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB,
			WGL_CONTEXT_PROFILE_MASK_ARB, WGL_CONTEXT_CORE_PROFILE_BIT_ARB,
			0
		};

		m_Context = wglCreateContextAttribsARB(m_hDC,0, attribs);

		if ( !m_Context )
			return false;

		LoadGL();

		wglMakeCurrent(NULL,NULL); 
		wglDeleteContext(m_tempContext);

		return true;
	}

	void zglCoreContextWin::Swap()
	{
		SwapBuffers(m_hDC);
	}

	bool zglCoreContextWin::LoadGL()
	{
		if (!m_glLoaded)
		{
			bool b12 = GL_1_2_LoadFuncPointers();
			bool b13 = GL_1_3_LoadFuncPointers();
			bool b14 = GL_1_4_LoadFuncPointers();
			bool b15 = GL_1_5_LoadFuncPointers();
			bool b20 = GL_2_0_LoadFuncPointers();
			bool b30 = GL_3_0_LoadFuncPointers();
			bool b31 = GL_3_1_LoadFuncPointers();
			bool b32 = GL_3_2_LoadFuncPointers();
			bool b33 = GL_3_3_LoadFuncPointers();
			bool b40 = GL_4_0_LoadFuncPointers();
			bool b41 = GL_4_1_LoadFuncPointers();
			bool b42 = GL_4_2_LoadFuncPointers();
			bool b43 = GL_4_3_LoadFuncPointers();

			m_glLoaded = b12 && b13 && b14 && b15 && b20 && b30 && b31 && b32 && b33
				&& b40 && b41 && b42 && b43;
		}
		return m_glLoaded;
	}

	void zglCoreContextWin::GetGLVersion(int* major, int* minor)
	{
		// for all versions
		char* ver = (char*)glGetString(GL_VERSION); // ver = "3.2.0"

		*major = ver[0] - '0';
		if( *major >= 3)
		{
			// for GL 3.x
			glGetIntegerv(GL_MAJOR_VERSION, major); // major = 3
			glGetIntegerv(GL_MINOR_VERSION, minor); // minor = 2
		}
		else
		{
			*minor = ver[2] - '0';
		}

		// GLSL
		ver = (char*)glGetString(GL_SHADING_LANGUAGE_VERSION); // ver = "1.50 NVIDIA via Cg compiler"
	}


	zglContext* zglContext::New(const zglState& state)
	{
		if (!state.WindowID())
			return NULL;

		return new zglCoreContextWin(state);
	}

} // namespace ZGL