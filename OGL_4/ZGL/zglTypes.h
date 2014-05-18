/*
* zglTypes.h
*
* Created on: Apr 23, 2014
* Author: Andrew Zhabura
*/

#ifndef zglTypes_h
#define zglTypes_h

#include <windows.h>

namespace ZGL
{	
	typedef HWND		zWIN_ID;
	typedef	HINSTANCE	zAPP_ID;
	typedef unsigned char	zUChar;
	typedef unsigned int	zSize;

	struct zRect
	{
		zRect()
			: left(0)
			, top(0)
			, width(0)
			, height(0)
		{}

		int left;
		int top;
		zSize width;
		zSize height;
	};

} // namespace ZGL

#endif // zglTypes_h