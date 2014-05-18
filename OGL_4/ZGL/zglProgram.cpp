/*
* zglProgram.cpp
*
* Created on: Apr 30, 2014
* Author: Andrew Zhabura
*/

#include "zglProgram.h"

#include <fstream>

namespace ZGL
{
	zglProgram::zglProgram()
		: m_prgID(0)
	{
	}

	zglProgram::~zglProgram()
	{

	}

	bool zglProgram::LoadShaders(ShaderInfo* shaders)
	{
		m_prgID = glCreateProgram();

		
		glAttachShader( m_prgID, LoadShader("",1) );
		return true;
	}

	GLuint zglProgram::LoadShader(const char* fName, GLenum type)
	{
		GLchar* l_source = nullptr;
		GLuint l_shader = 0;

		std::ifstream l_file(fName, std::ifstream::binary);
		if (l_file.is_open())
		{
			std::streampos l_size = l_file.tellg();
			char* l_source = new char[l_size];
			l_file.seekg(0, std::ios::beg);
			l_file.read(l_source, l_size);
			l_file.close();
		}

		if (!l_source)
			return l_shader;

		l_shader = glCreateShader( type );
		glShaderSource( l_shader, 1, &l_source, NULL );
		delete[] l_source;

		glCompileShader( l_shader );

		GLint compiled;
		glGetShaderiv( l_shader, GL_COMPILE_STATUS, &compiled );
		if ( !compiled ) {
#ifdef _DEBUG
			GLsizei len;
			glGetShaderiv( l_shader, GL_INFO_LOG_LENGTH, &len );

			GLchar* log = new GLchar[len+1];
			glGetShaderInfoLog( l_shader, len, &len, log );
//			std::cerr << "Shader compilation failed: " << log << std::endl;
			delete [] log;
#endif /* DEBUG */

			return 0;
		}

		return l_shader;
	}

	bool zglProgram::ActivateProgram()
	{
		if (!m_prgID)
			return false;
		
		glUseProgram(m_prgID);
		return true;

	}

	static const GLchar*
		ReadShader( const char* filename )
	{
#ifdef WIN32
		FILE* infile;
		fopen_s( &infile, filename, "rb" );
#else
		FILE* infile = fopen( filename, "rb" );
#endif // WIN32

		if ( !infile ) {
#ifdef _DEBUG
//			std::cerr << "Unable to open file '" << filename << "'" << std::endl;
#endif /* DEBUG */
			return NULL;
		}

		fseek( infile, 0, SEEK_END );
		int len = ftell( infile );
		fseek( infile, 0, SEEK_SET );

		GLchar* source = new GLchar[len+1];

		fread( source, 1, len, infile );
		fclose( infile );

		source[len] = 0;

		return const_cast<const GLchar*>(source);
	}

	//----------------------------------------------------------------------------

	GLuint
		LoadShaders( ShaderInfo* shaders )
	{
		if ( shaders == NULL ) { return 0; }

		GLuint program = glCreateProgram();

		ShaderInfo* entry = shaders;
		while ( entry->type != GL_NONE ) {
			GLuint shader = glCreateShader( entry->type );

			entry->shader = shader;

			const GLchar* source = ReadShader( entry->filename );
			if ( source == NULL ) {
				for ( entry = shaders; entry->type != GL_NONE; ++entry ) {
					glDeleteShader( entry->shader );
					entry->shader = 0;
				}

				return 0;
			}

			glShaderSource( shader, 1, &source, NULL );
			delete [] source;

			glCompileShader( shader );

			GLint compiled;
			glGetShaderiv( shader, GL_COMPILE_STATUS, &compiled );
			if ( !compiled ) {
#ifdef _DEBUG
				GLsizei len;
				glGetShaderiv( shader, GL_INFO_LOG_LENGTH, &len );

				GLchar* log = new GLchar[len+1];
				glGetShaderInfoLog( shader, len, &len, log );
//				std::cerr << "Shader compilation failed: " << log << std::endl;
				delete [] log;
#endif /* DEBUG */

				return 0;
			}

			glAttachShader( program, shader );

			++entry;
		}

#ifdef GL_VERSION_4_1
		//     if ( GLEW_VERSION_4_1 ) {
		//         // glProgramParameteri( program, GL_PROGRAM_SEPARABLE, GL_TRUE );
		//     }
#endif /* GL_VERSION_4_1 */

		glLinkProgram( program );

		GLint linked;
		glGetProgramiv( program, GL_LINK_STATUS, &linked );
		if ( !linked ) {
#ifdef _DEBUG
			GLsizei len;
			glGetProgramiv( program, GL_INFO_LOG_LENGTH, &len );

			GLchar* log = new GLchar[len+1];
			glGetProgramInfoLog( program, len, &len, log );
//			std::cerr << "Shader linking failed: " << log << std::endl;
			delete [] log;
#endif /* DEBUG */

			for ( entry = shaders; entry->type != GL_NONE; ++entry ) {
				glDeleteShader( entry->shader );
				entry->shader = 0;
			}

			return 0;
		}

		return program;
	}


} // namespace ZGL