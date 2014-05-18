/*
* ProducerEx1.h
*
* Created on: Apr 28, 2014
* Author: Andrew Zhabura
*/

#ifndef zglProducer_h
#define zglProducer_h

namespace ZGL
{
	class zglProducer
	{
	public:
		virtual void InitGL() = 0;
		virtual void Display() = 0;
	};

} // namespace ZGL


#endif // zglProducer_h