/*
* zglState.cpp
*
* Created on: Apr 23, 2014
* Author: Andrew Zhabura
*/

#include "zglState.h"

namespace ZGL
{

	zglState::zglState(zUChar verMajor, zUChar verMinor)
		: m_verMajor(verMajor)
		, m_verMinor(verMinor)
		, m_winId(NULL)
	{
	}

	zglState::~zglState()
	{
	}

	zWIN_ID zglState::WindowID() const
	{
		return m_winId;
	}

	void zglState::SetWindowID(zWIN_ID win)
	{
		m_winId = win;
	}

	void zglState::SetWindowRect(int left, int top, zSize width, zSize height)
	{
		m_Window.SetRect(left, top, width, height);
	}

	void zglState::ResizeWindowRect(zSize width, zSize height)
	{
		m_Window.ResizeRect(width, height);
	}

	zRect zglState::WindowRect() const
	{
		return m_Window.Rect();
	}

	void zglState::SetViewportRect(int left, int top, zSize width, zSize height)
	{
		m_Viewport.SetRect(left, top, width, height);
	}

	void zglState::ResizeViewportRect(zSize width, zSize height)
	{
		m_Viewport.ResizeRect(width, height);
	}

	zRect zglState::ViewportRect() const
	{
		return m_Viewport.Rect();
	}

	void zglState::SetTitle(std::string title)
	{
		m_WindowTitle = title;
	}

	const char * zglState::Title() const
	{
		return m_WindowTitle.c_str();
	}

} // namespace ZGL