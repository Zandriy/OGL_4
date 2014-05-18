/*
* zglContext.h
*
* Created on: Apr 24, 2014
* Author: Andrew Zhabura
*/

#ifndef __zglContext_h__
#define __zglContext_h__

#include "zglTypes.h"
//#include "zglState.h"

namespace ZGL
{
	class zglState;

	class zglContext
	{
	public:
		static zglContext* New(const zglState& state);

		virtual bool MakeCurrent(bool b) = 0;
		virtual void Show(bool b) = 0;
		virtual void UpdateViewport() = 0;
		virtual void Swap() = 0;
	};

} // namespace ZGL

#endif //  __zglContext_h__