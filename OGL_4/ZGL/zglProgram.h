/*
* zglProgram.h
*
* Created on: Apr 30, 2014
* Author: Andrew Zhabura
*/

#ifndef zglProgram_h
#define zglProgram_h
 
#include "ZGL/zglLoaderWin.h"

namespace ZGL
{

	struct ShaderInfo {
		GLenum       type;

		const char*  filename;
		GLuint       shader;
	};

	class zglProgram
	{
	public:
		zglProgram();
		~zglProgram();

		bool LoadShaders(ShaderInfo* shaders);
		bool ActivateProgram();
	private:
		GLuint LoadShader(const char* fName, GLenum type);

		GLuint m_prgID;
	};

} // namespace ZGL

#endif // zglProgram_h