/*
* zglWindow.h
*
* Created on: Apr 24, 2014
* Author: Andrew Zhabura
*/

#ifndef zglWindow_h
#define zglWindow_h

#include "zglTypes.h"

#include "zglProducer.h"

namespace ZGL
{

	class zglWindow
	{	
	public:
		static zglWindow* New(zAPP_ID appID, zWIN_ID parentID);

		virtual void SetWindowRect(int left, int top, zSize width, zSize height) = 0;
		virtual const char * Title() const = 0;
		virtual void Show(bool b) = 0;
		virtual zWIN_ID WinID() const = 0;
		virtual void SetOGLProducer(zglProducer* producer) = 0;
	};

} // namespace ZGL

#endif // zglWindow_h