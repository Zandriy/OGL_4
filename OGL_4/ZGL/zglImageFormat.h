/*
* zglImageFormat.h
*
* Created on: Apr 23, 2014
* Author: Andrew Zhabura
*/

#ifndef zglImageFormat_h
#define zglImageFormat_h

#include "zglTypes.h"

namespace ZGL
{

	class zglImageFormat
	{
	public:
		zglImageFormat();
		~zglImageFormat();
		void SetRect(int left, int top, zSize width, zSize height);
		void ResizeRect(zSize width, zSize height);
		zRect Rect() const;
	private:
		zRect m_rect;
	};

} // namespace ZGL

#endif // zglImageFormat