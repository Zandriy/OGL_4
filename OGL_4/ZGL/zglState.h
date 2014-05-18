/*
* zglState.h
*
* Created on: Apr 23, 2014
* Author: Andrew Zhabura
*/

#ifndef zglState_h
#define zglState_h

#include "zglImageFormat.h"
#include <string>
#include "zglTypes.h"

namespace ZGL
{

	class zglState
	{
	public:
		zglState(zUChar verMajor, zUChar verMinor);
		~zglState();

		void SetWindowID(zWIN_ID win);
		zWIN_ID WindowID() const;
		void SetWindowRect(int left, int top, zSize width, zSize height);
		void ResizeWindowRect(zSize width, zSize height);
		zRect WindowRect() const;
		void SetViewportRect(int left, int top, zSize width, zSize height);
		void ResizeViewportRect(zSize width, zSize height);
		zRect ViewportRect() const;
		void SetTitle(std::string title);
		const char * Title() const;
	private:
		const zUChar m_verMajor;
		const zUChar m_verMinor;
		zWIN_ID m_winId;
		zglImageFormat m_Window;
		zglImageFormat m_Viewport;

		std::string m_WindowTitle;
	};

} // namespace ZGL

#endif // zglState_h