/*
* zglImageFormat.cpp
*
* Created on: Apr 23, 2014
* Author: Andrew Zhabura
*/

#include "zglImageFormat.h"

namespace ZGL
{

	zglImageFormat::zglImageFormat()
	{
	}

	zglImageFormat::~zglImageFormat()
	{

	}

	void zglImageFormat::SetRect(int left, int top, zSize width, zSize height)
	{
		m_rect.left = left;
		m_rect.top = top;
		m_rect.width = width;
		m_rect.height = height;
	}

	void zglImageFormat::ResizeRect(zSize width, zSize height)
	{
		m_rect.width = width;
		m_rect.height = height;
	}

	zRect zglImageFormat::Rect() const
	{
		return m_rect;
	}

} // namespace ZGL