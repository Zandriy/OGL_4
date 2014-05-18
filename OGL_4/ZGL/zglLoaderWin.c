/*
* zglLoaderWin.cpp
*
* Created on: Dec 31, 2013
* Author: Andrew Zhabura
*/

#include "zglLoaderWin.h"

/////////////////////////////// WGL ////////////////////////////////

PFNWGLCREATECONTEXTATTRIBSARBPROC		pwglCreateContextAttribsARB = 0;

int GL_LoadCreateWinCoreContext()
{
	wglCreateContextAttribsARB	= (PFNWGLCREATECONTEXTATTRIBSARBPROC)wglGetProcAddress("wglCreateContextAttribsARB");

	return wglCreateContextAttribsARB ? 1 : 0;
}

/////////////////////////////// GL_VERSION_1_2 ////////////////////////////////

PFNGLDRAWRANGEELEMENTSPROC		pglDrawRangeElements = 0;
PFNGLTEXIMAGE3DPROC				pglTexImage3D = 0;
PFNGLTEXSUBIMAGE3DPROC			pglTexSubImage3D = 0;
PFNGLCOPYTEXSUBIMAGE3DPROC		pglCopyTexSubImage3D = 0;

int GL_1_2_LoadFuncPointers()
{
	glDrawRangeElements	= (PFNGLDRAWRANGEELEMENTSPROC)wglGetProcAddress("glDrawRangeElements");
	glTexImage3D		= (PFNGLTEXIMAGE3DPROC)wglGetProcAddress("glTexImage3D");
	glTexSubImage3D		= (PFNGLTEXSUBIMAGE3DPROC)wglGetProcAddress("glTexSubImage3D");
	glCopyTexSubImage3D	= (PFNGLCOPYTEXSUBIMAGE3DPROC)wglGetProcAddress("glCopyTexSubImage3D");

	return (glDrawRangeElements && glTexImage3D && glTexSubImage3D && glCopyTexSubImage3D) ? 1 : 0;
}


/////////////////////////////// GL_VERSION_1_3 ////////////////////////////////

PFNGLACTIVETEXTUREPROC				pglActiveTexture = 0;
PFNGLSAMPLECOVERAGEPROC				pglSampleCoverage = 0;
PFNGLCOMPRESSEDTEXIMAGE3DPROC		pglCompressedTexImage3D = 0;
PFNGLCOMPRESSEDTEXIMAGE2DPROC		pglCompressedTexImage2D = 0;
PFNGLCOMPRESSEDTEXIMAGE1DPROC		pglCompressedTexImage1D = 0;
PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC		pglCompressedTexSubImage3D = 0;
PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC		pglCompressedTexSubImage2D = 0;
PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC		pglCompressedTexSubImage1D = 0;
PFNGLGETCOMPRESSEDTEXIMAGEPROC		pglGetCompressedTexImage = 0;


int GL_1_3_LoadFuncPointers()
{
	glActiveTexture				 = (PFNGLACTIVETEXTUREPROC)wglGetProcAddress("glActiveTexture");
	glSampleCoverage			 = (PFNGLSAMPLECOVERAGEPROC)wglGetProcAddress("glSampleCoverage");
	glCompressedTexImage3D		 = (PFNGLCOMPRESSEDTEXIMAGE3DPROC)wglGetProcAddress("glCompressedTexImage3D");
	glCompressedTexImage2D		 = (PFNGLCOMPRESSEDTEXIMAGE2DPROC)wglGetProcAddress("glCompressedTexImage2D");
	glCompressedTexImage1D		 = (PFNGLCOMPRESSEDTEXIMAGE1DPROC)wglGetProcAddress("glCompressedTexImage1D");
	glCompressedTexSubImage3D	 = (PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC)wglGetProcAddress("glCompressedTexSubImage3D");
	glCompressedTexSubImage2D	 = (PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC)wglGetProcAddress("glCompressedTexSubImage2D");
	glCompressedTexSubImage1D	 = (PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC)wglGetProcAddress("glCompressedTexSubImage1D");
	glGetCompressedTexImage		 = (PFNGLGETCOMPRESSEDTEXIMAGEPROC)wglGetProcAddress("glGetCompressedTexImage");

	return (glActiveTexture && glSampleCoverage && glCompressedTexImage3D && glCompressedTexImage2D && 	glCompressedTexImage1D
		&& glCompressedTexSubImage3D && glCompressedTexSubImage2D && glCompressedTexSubImage1D && glGetCompressedTexImage) ? 1 : 0;
}

/////////////////////////////// GL_VERSION_1_4 ////////////////////////////////

PFNGLBLENDFUNCSEPARATEPROC		pglBlendFuncSeparate = 0;
PFNGLMULTIDRAWARRAYSPROC			pglMultiDrawArrays = 0;
PFNGLMULTIDRAWELEMENTSPROC		pglMultiDrawElements = 0;
PFNGLPOINTPARAMETERFPROC			pglPointParameterf = 0;
PFNGLPOINTPARAMETERFVPROC		pglPointParameterfv = 0;
PFNGLPOINTPARAMETERIPROC			pglPointParameteri = 0;
PFNGLPOINTPARAMETERIVPROC		pglPointParameteriv = 0;
PFNGLBLENDCOLORPROC				pglBlendColor = 0;
PFNGLBLENDEQUATIONPROC			pglBlendEquation = 0;

int GL_1_4_LoadFuncPointers()

{
	glBlendFuncSeparate	= (PFNGLBLENDFUNCSEPARATEPROC)wglGetProcAddress("glBlendFuncSeparate");
	glMultiDrawArrays	= (PFNGLMULTIDRAWARRAYSPROC)wglGetProcAddress("glMultiDrawArrays");
	glMultiDrawElements	= (PFNGLMULTIDRAWELEMENTSPROC)wglGetProcAddress("glMultiDrawElements");
	glPointParameterf	= (PFNGLPOINTPARAMETERFPROC)wglGetProcAddress("glPointParameterf");
	glPointParameterfv	= (PFNGLPOINTPARAMETERFVPROC)wglGetProcAddress("glPointParameterfv");
	glPointParameteri	= (PFNGLPOINTPARAMETERIPROC)wglGetProcAddress("glPointParameteri");
	glPointParameteriv	= (PFNGLPOINTPARAMETERIVPROC)wglGetProcAddress("glPointParameteriv");
	glBlendColor		= (PFNGLBLENDCOLORPROC)wglGetProcAddress("glBlendColor");
	glBlendEquation		= (PFNGLBLENDEQUATIONPROC)wglGetProcAddress("glBlendEquation");

	return (glBlendFuncSeparate && glMultiDrawArrays && glMultiDrawElements /*&& glPointParameter*/ && glPointParameterfv && 
		glPointParameteri && glPointParameteriv && glBlendColor && glBlendEquation) ? 1 : 0;
}


/////////////////////////////// GL_VERSION_1_5 ////////////////////////////////

PFNGLGENQUERIESPROC				pglGenQueries = 0;
PFNGLDELETEQUERIESPROC			pglDeleteQueries = 0;
PFNGLISQUERYPROC					pglIsQuery = 0;
PFNGLBEGINQUERYPROC				pglBeginQuery = 0;
PFNGLENDQUERYPROC				pglEndQuery = 0;
PFNGLGETQUERYIVPROC				pglGetQueryiv = 0;
PFNGLGETQUERYOBJECTIVPROC		pglGetQueryObjectiv = 0;
PFNGLGETQUERYOBJECTUIVPROC		pglGetQueryObjectuiv = 0;
PFNGLBINDBUFFERPROC				pglBindBuffer = 0;
PFNGLDELETEBUFFERSPROC			pglDeleteBuffers = 0;
PFNGLGENBUFFERSPROC				pglGenBuffers = 0;
PFNGLISBUFFERPROC				pglIsBuffer = 0;
PFNGLBUFFERDATAPROC				pglBufferData = 0;
PFNGLBUFFERSUBDATAPROC			pglBufferSubData = 0;
PFNGLGETBUFFERSUBDATAPROC		pglGetBufferSubData = 0;
PFNGLMAPBUFFERPROC				pglMapBuffer = 0;
PFNGLUNMAPBUFFERPROC				pglUnmapBuffer = 0;
PFNGLGETBUFFERPARAMETERIVPROC	pglGetBufferParameteriv = 0;
PFNGLGETBUFFERPOINTERVPROC		pglGetBufferPointerv = 0;

int GL_1_5_LoadFuncPointers()
{
	glGenQueries = (PFNGLGENQUERIESPROC)wglGetProcAddress("glGenQueries");
	glDeleteQueries = (PFNGLDELETEQUERIESPROC)wglGetProcAddress("glDeleteQueries");
	glIsQuery = (PFNGLISQUERYPROC)wglGetProcAddress("glIsQuery");
	glBeginQuery = (PFNGLBEGINQUERYPROC)wglGetProcAddress("glBeginQuery");
	glEndQuery = (PFNGLENDQUERYPROC)wglGetProcAddress("glEndQuery");
	glGetQueryiv = (PFNGLGETQUERYIVPROC)wglGetProcAddress("glGetQueryiv");
	glGetQueryObjectiv = (PFNGLGETQUERYOBJECTIVPROC)wglGetProcAddress("glGetQueryObjectiv");
	glGetQueryObjectuiv = (PFNGLGETQUERYOBJECTUIVPROC)wglGetProcAddress("glGetQueryObjectuiv");
	glBindBuffer = (PFNGLBINDBUFFERPROC)wglGetProcAddress("glBindBuffer");
	glDeleteBuffers = (PFNGLDELETEBUFFERSPROC)wglGetProcAddress("glDeleteBuffers");
	glGenBuffers = (PFNGLGENBUFFERSPROC)wglGetProcAddress("glGenBuffers");
	glIsBuffer = (PFNGLISBUFFERPROC)wglGetProcAddress("glIsBuffer");
	glBufferData = (PFNGLBUFFERDATAPROC)wglGetProcAddress("glBufferData");
	glBufferSubData = (PFNGLBUFFERSUBDATAPROC)wglGetProcAddress("glBufferSubData");
	glGetBufferSubData = (PFNGLGETBUFFERSUBDATAPROC)wglGetProcAddress("glGetBufferSubData");
	glMapBuffer = (PFNGLMAPBUFFERPROC)wglGetProcAddress("glMapBuffer");
	glUnmapBuffer = (PFNGLUNMAPBUFFERPROC)wglGetProcAddress("glUnmapBuffer");
	glGetBufferParameteriv = (PFNGLGETBUFFERPARAMETERIVPROC)wglGetProcAddress("glGetBufferParameteriv");
	glGetBufferPointerv = (PFNGLGETBUFFERPOINTERVPROC)wglGetProcAddress("glGetBufferPointerv");

	return (glGenQueries && glDeleteQueries && glIsQuery && glBeginQuery && glEndQuery && glGetQueryiv
		&& glGetQueryObjectiv && glGetQueryObjectuiv && glBindBuffer && glDeleteBuffers && glGenBuffers
		&& glIsBuffer && glBufferData && glBufferSubData && glGetBufferSubData && glMapBuffer && glUnmapBuffer
		&& glGetBufferParameteriv && glGetBufferPointerv) ? 1 : 0;
}

/////////////////////////////// GL_VERSION_2_0 ////////////////////////////////

PFNGLBLENDEQUATIONSEPARATEPROC			pglBlendEquationSeparate = 0;
PFNGLDRAWBUFFERSPROC					pglDrawBuffers = 0;
PFNGLSTENCILOPSEPARATEPROC				pglStencilOpSeparate = 0;
PFNGLSTENCILFUNCSEPARATEPROC			pglStencilFuncSeparate = 0;
PFNGLSTENCILMASKSEPARATEPROC			pglStencilMaskSeparate = 0;
PFNGLATTACHSHADERPROC					pglAttachShader = 0;
PFNGLBINDATTRIBLOCATIONPROC				pglBindAttribLocation = 0;
PFNGLCOMPILESHADERPROC					pglCompileShader = 0;
PFNGLCREATEPROGRAMPROC					pglCreateProgram = 0;
PFNGLCREATESHADERPROC					pglCreateShader = 0;
PFNGLDELETEPROGRAMPROC					pglDeleteProgram = 0;
PFNGLDELETESHADERPROC					pglDeleteShader = 0;
PFNGLDETACHSHADERPROC					pglDetachShader = 0;
PFNGLDISABLEVERTEXATTRIBARRAYPROC		pglDisableVertexAttribArray = 0;
PFNGLENABLEVERTEXATTRIBARRAYPROC		pglEnableVertexAttribArray = 0;
PFNGLGETACTIVEATTRIBPROC				pglGetActiveAttrib = 0;
PFNGLGETACTIVEUNIFORMPROC				pglGetActiveUniform = 0;
PFNGLGETATTACHEDSHADERSPROC				pglGetAttachedShaders = 0;
PFNGLGETATTRIBLOCATIONPROC				pglGetAttribLocation = 0;
PFNGLGETPROGRAMIVPROC					pglGetProgramiv = 0;
PFNGLGETPROGRAMINFOLOGPROC				pglGetProgramInfoLog = 0;
PFNGLGETSHADERIVPROC					pglGetShaderiv = 0;
PFNGLGETSHADERINFOLOGPROC				pglGetShaderInfoLog = 0;
PFNGLGETSHADERSOURCEPROC				pglGetShaderSource = 0;
PFNGLGETUNIFORMLOCATIONPROC				pglGetUniformLocation = 0;
PFNGLGETUNIFORMFVPROC					pglGetUniformfv = 0;
PFNGLGETUNIFORMIVPROC					pglGetUniformiv = 0;
PFNGLGETVERTEXATTRIBDVPROC				pglGetVertexAttribdv = 0;
PFNGLGETVERTEXATTRIBFVPROC				pglGetVertexAttribfv = 0;
PFNGLGETVERTEXATTRIBIVPROC				pglGetVertexAttribiv = 0;
PFNGLGETVERTEXATTRIBPOINTERVPROC		pglGetVertexAttribPointerv = 0;
PFNGLISPROGRAMPROC						pglIsProgram = 0;
PFNGLISSHADERPROC						pglIsShader = 0;
PFNGLLINKPROGRAMPROC					pglLinkProgram = 0;
PFNGLSHADERSOURCEPROC					pglShaderSource = 0;
PFNGLUSEPROGRAMPROC						pglUseProgram = 0;
PFNGLUNIFORM1FPROC						pglUniform1f = 0;
PFNGLUNIFORM2FPROC						pglUniform2f = 0;
PFNGLUNIFORM3FPROC						pglUniform3f = 0;
PFNGLUNIFORM4FPROC						pglUniform4f = 0;
PFNGLUNIFORM1IPROC						pglUniform1i = 0;
PFNGLUNIFORM2IPROC						pglUniform2i = 0;
PFNGLUNIFORM3IPROC						pglUniform3i = 0;
PFNGLUNIFORM4IPROC						pglUniform4i = 0;
PFNGLUNIFORM1FVPROC						pglUniform1fv = 0;
PFNGLUNIFORM2FVPROC						pglUniform2fv = 0;
PFNGLUNIFORM3FVPROC						pglUniform3fv = 0;
PFNGLUNIFORM4FVPROC						pglUniform4fv = 0;
PFNGLUNIFORM1IVPROC						pglUniform1iv = 0;
PFNGLUNIFORM2IVPROC						pglUniform2iv = 0;
PFNGLUNIFORM3IVPROC						pglUniform3iv = 0;
PFNGLUNIFORM4IVPROC						pglUniform4iv = 0;
PFNGLUNIFORMMATRIX2FVPROC				pglUniformMatrix2fv = 0;
PFNGLUNIFORMMATRIX3FVPROC				pglUniformMatrix3fv = 0;
PFNGLUNIFORMMATRIX4FVPROC				pglUniformMatrix4fv = 0;
PFNGLVALIDATEPROGRAMPROC				pglValidateProgram = 0;
PFNGLVERTEXATTRIB1DPROC					pglVertexAttrib1d = 0;
PFNGLVERTEXATTRIB1DVPROC				pglVertexAttrib1dv = 0;
PFNGLVERTEXATTRIB1FPROC					pglVertexAttrib1f = 0;
PFNGLVERTEXATTRIB1FVPROC				pglVertexAttrib1fv = 0;
PFNGLVERTEXATTRIB1SPROC					pglVertexAttrib1s = 0;
PFNGLVERTEXATTRIB1SVPROC				pglVertexAttrib1sv = 0;
PFNGLVERTEXATTRIB2DPROC					pglVertexAttrib2d = 0;
PFNGLVERTEXATTRIB2DVPROC				pglVertexAttrib2dv = 0;
PFNGLVERTEXATTRIB2FPROC					pglVertexAttrib2f = 0;
PFNGLVERTEXATTRIB2FVPROC				pglVertexAttrib2fv = 0;
PFNGLVERTEXATTRIB2SPROC					pglVertexAttrib2s = 0;
PFNGLVERTEXATTRIB2SVPROC				pglVertexAttrib2sv = 0;
PFNGLVERTEXATTRIB3DPROC					pglVertexAttrib3d = 0;
PFNGLVERTEXATTRIB3DVPROC				pglVertexAttrib3dv = 0;
PFNGLVERTEXATTRIB3FPROC					pglVertexAttrib3f = 0;
PFNGLVERTEXATTRIB3FVPROC				pglVertexAttrib3fv = 0;
PFNGLVERTEXATTRIB3SPROC					pglVertexAttrib3s = 0;
PFNGLVERTEXATTRIB3SVPROC				pglVertexAttrib3sv = 0;
PFNGLVERTEXATTRIB4NBVPROC				pglVertexAttrib4Nbv = 0;
PFNGLVERTEXATTRIB4NIVPROC				pglVertexAttrib4Niv = 0;
PFNGLVERTEXATTRIB4NSVPROC				pglVertexAttrib4Nsv = 0;
PFNGLVERTEXATTRIB4NUBPROC				pglVertexAttrib4Nub = 0;
PFNGLVERTEXATTRIB4NUBVPROC				pglVertexAttrib4Nubv = 0;
PFNGLVERTEXATTRIB4NUIVPROC				pglVertexAttrib4Nuiv = 0;
PFNGLVERTEXATTRIB4NUSVPROC				pglVertexAttrib4Nusv = 0;
PFNGLVERTEXATTRIB4BVPROC				pglVertexAttrib4bv = 0;
PFNGLVERTEXATTRIB4DPROC					pglVertexAttrib4d = 0;
PFNGLVERTEXATTRIB4DVPROC				pglVertexAttrib4dv = 0;
PFNGLVERTEXATTRIB4FPROC					pglVertexAttrib4f = 0;
PFNGLVERTEXATTRIB4FVPROC				pglVertexAttrib4fv = 0;
PFNGLVERTEXATTRIB4IVPROC				pglVertexAttrib4iv = 0;
PFNGLVERTEXATTRIB4SPROC					pglVertexAttrib4s = 0;
PFNGLVERTEXATTRIB4SVPROC				pglVertexAttrib4sv = 0;
PFNGLVERTEXATTRIB4UBVPROC				pglVertexAttrib4ubv = 0;
PFNGLVERTEXATTRIB4UIVPROC				pglVertexAttrib4uiv = 0;
PFNGLVERTEXATTRIB4USVPROC				pglVertexAttrib4usv = 0;
PFNGLVERTEXATTRIBPOINTERPROC			pglVertexAttribPointer = 0;

int GL_2_0_LoadFuncPointers()
{
	glBlendEquationSeparate = (PFNGLBLENDEQUATIONSEPARATEPROC)wglGetProcAddress("glBlendEquationSeparate");
	glDrawBuffers = (PFNGLDRAWBUFFERSPROC)wglGetProcAddress("glDrawBuffers");
	glStencilOpSeparate = (PFNGLSTENCILOPSEPARATEPROC)wglGetProcAddress("glStencilOpSeparate");
	glStencilFuncSeparate = (PFNGLSTENCILFUNCSEPARATEPROC)wglGetProcAddress("glStencilFuncSeparate");
	glStencilMaskSeparate = (PFNGLSTENCILMASKSEPARATEPROC)wglGetProcAddress("glStencilMaskSeparate");
	glAttachShader = (PFNGLATTACHSHADERPROC)wglGetProcAddress("glAttachShader");
	glBindAttribLocation = (PFNGLBINDATTRIBLOCATIONPROC)wglGetProcAddress("glBindAttribLocation");
	glCompileShader = (PFNGLCOMPILESHADERPROC)wglGetProcAddress("glCompileShader");
	glCreateProgram = (PFNGLCREATEPROGRAMPROC)wglGetProcAddress("glCreateProgram");
	glCreateShader = (PFNGLCREATESHADERPROC)wglGetProcAddress("glCreateShader");
	glDeleteProgram = (PFNGLDELETEPROGRAMPROC)wglGetProcAddress("glDeleteProgram");
	glDeleteShader = (PFNGLDELETESHADERPROC)wglGetProcAddress("glDeleteShader");
	glDetachShader = (PFNGLDETACHSHADERPROC)wglGetProcAddress("glDetachShader");
	glDisableVertexAttribArray = (PFNGLDISABLEVERTEXATTRIBARRAYPROC)wglGetProcAddress("glDisableVertexAttribArray");
	glEnableVertexAttribArray = (PFNGLENABLEVERTEXATTRIBARRAYPROC)wglGetProcAddress("glEnableVertexAttribArray");
	glGetActiveAttrib = (PFNGLGETACTIVEATTRIBPROC)wglGetProcAddress("glGetActiveAttrib");
	glGetActiveUniform = (PFNGLGETACTIVEUNIFORMPROC)wglGetProcAddress("glGetActiveUniform");
	glGetAttachedShaders = (PFNGLGETATTACHEDSHADERSPROC)wglGetProcAddress("glGetAttachedShaders");
	glGetAttribLocation = (PFNGLGETATTRIBLOCATIONPROC)wglGetProcAddress("glGetAttribLocation");
	glGetProgramiv = (PFNGLGETPROGRAMIVPROC)wglGetProcAddress("glGetProgramiv");
	glGetProgramInfoLog = (PFNGLGETPROGRAMINFOLOGPROC)wglGetProcAddress("glGetProgramInfoLog");
	glGetShaderiv = (PFNGLGETSHADERIVPROC)wglGetProcAddress("glGetShaderiv");
	glGetShaderInfoLog = (PFNGLGETSHADERINFOLOGPROC)wglGetProcAddress("glGetShaderInfoLog");
	glGetShaderSource = (PFNGLGETSHADERSOURCEPROC)wglGetProcAddress("glGetShaderSource");
	glGetUniformLocation = (PFNGLGETUNIFORMLOCATIONPROC)wglGetProcAddress("glGetUniformLocation");
	glGetUniformfv = (PFNGLGETUNIFORMFVPROC)wglGetProcAddress("glGetUniformfv");
	glGetUniformiv = (PFNGLGETUNIFORMIVPROC)wglGetProcAddress("glGetUniformiv");
	glGetVertexAttribdv = (PFNGLGETVERTEXATTRIBDVPROC)wglGetProcAddress("glGetVertexAttribdv");
	glGetVertexAttribfv = (PFNGLGETVERTEXATTRIBFVPROC)wglGetProcAddress("glGetVertexAttribfv");
	glGetVertexAttribiv = (PFNGLGETVERTEXATTRIBIVPROC)wglGetProcAddress("glGetVertexAttribiv");
	glGetVertexAttribPointerv = (PFNGLGETVERTEXATTRIBPOINTERVPROC)wglGetProcAddress("glGetVertexAttribPointerv");
	glIsProgram = (PFNGLISPROGRAMPROC)wglGetProcAddress("glIsProgram");
	glIsShader = (PFNGLISSHADERPROC)wglGetProcAddress("glIsShader");
	glLinkProgram = (PFNGLLINKPROGRAMPROC)wglGetProcAddress("glLinkProgram");
	glShaderSource = (PFNGLSHADERSOURCEPROC)wglGetProcAddress("glShaderSource");
	glUseProgram = (PFNGLUSEPROGRAMPROC)wglGetProcAddress("glUseProgram");
	glUniform1f = (PFNGLUNIFORM1FPROC)wglGetProcAddress("glUniform1f");
	glUniform2f = (PFNGLUNIFORM2FPROC)wglGetProcAddress("glUniform2f");
	glUniform3f = (PFNGLUNIFORM3FPROC)wglGetProcAddress("glUniform3f");
	glUniform4f = (PFNGLUNIFORM4FPROC)wglGetProcAddress("glUniform4f");
	glUniform1i = (PFNGLUNIFORM1IPROC)wglGetProcAddress("glUniform1i");
	glUniform2i = (PFNGLUNIFORM2IPROC)wglGetProcAddress("glUniform2i");
	glUniform3i = (PFNGLUNIFORM3IPROC)wglGetProcAddress("glUniform3i");
	glUniform4i = (PFNGLUNIFORM4IPROC)wglGetProcAddress("glUniform4i");
	glUniform1fv = (PFNGLUNIFORM1FVPROC)wglGetProcAddress("glUniform1fv");
	glUniform2fv = (PFNGLUNIFORM2FVPROC)wglGetProcAddress("glUniform2fv");
	glUniform3fv = (PFNGLUNIFORM3FVPROC)wglGetProcAddress("glUniform3fv");
	glUniform4fv = (PFNGLUNIFORM4FVPROC)wglGetProcAddress("glUniform4fv");
	glUniform1iv = (PFNGLUNIFORM1IVPROC)wglGetProcAddress("glUniform1iv");
	glUniform2iv = (PFNGLUNIFORM2IVPROC)wglGetProcAddress("glUniform2iv");
	glUniform3iv = (PFNGLUNIFORM3IVPROC)wglGetProcAddress("glUniform3iv");
	glUniform4iv = (PFNGLUNIFORM4IVPROC)wglGetProcAddress("glUniform4iv");
	glUniformMatrix2fv = (PFNGLUNIFORMMATRIX2FVPROC)wglGetProcAddress("glUniformMatrix2fv");
	glUniformMatrix3fv = (PFNGLUNIFORMMATRIX3FVPROC)wglGetProcAddress("glUniformMatrix3fv");
	glUniformMatrix4fv = (PFNGLUNIFORMMATRIX4FVPROC)wglGetProcAddress("glUniformMatrix4fv");
	glValidateProgram = (PFNGLVALIDATEPROGRAMPROC)wglGetProcAddress("glValidateProgram");
	glVertexAttrib1d = (PFNGLVERTEXATTRIB1DPROC)wglGetProcAddress("glVertexAttrib1d");
	glVertexAttrib1dv = (PFNGLVERTEXATTRIB1DVPROC)wglGetProcAddress("glVertexAttrib1dv");
	glVertexAttrib1f = (PFNGLVERTEXATTRIB1FPROC)wglGetProcAddress("glVertexAttrib1f");
	glVertexAttrib1fv = (PFNGLVERTEXATTRIB1FVPROC)wglGetProcAddress("glVertexAttrib1fv");
	glVertexAttrib1s = (PFNGLVERTEXATTRIB1SPROC)wglGetProcAddress("glVertexAttrib1s");
	glVertexAttrib1sv = (PFNGLVERTEXATTRIB1SVPROC)wglGetProcAddress("glVertexAttrib1sv");
	glVertexAttrib2d = (PFNGLVERTEXATTRIB2DPROC)wglGetProcAddress("glVertexAttrib2d");
	glVertexAttrib2dv = (PFNGLVERTEXATTRIB2DVPROC)wglGetProcAddress("glVertexAttrib2dv");
	glVertexAttrib2f = (PFNGLVERTEXATTRIB2FPROC)wglGetProcAddress("glVertexAttrib2f");
	glVertexAttrib2fv = (PFNGLVERTEXATTRIB2FVPROC)wglGetProcAddress("glVertexAttrib2fv");
	glVertexAttrib2s = (PFNGLVERTEXATTRIB2SPROC)wglGetProcAddress("glVertexAttrib2s");
	glVertexAttrib2sv = (PFNGLVERTEXATTRIB2SVPROC)wglGetProcAddress("glVertexAttrib2sv");
	glVertexAttrib3d = (PFNGLVERTEXATTRIB3DPROC)wglGetProcAddress("glVertexAttrib3d");
	glVertexAttrib3dv = (PFNGLVERTEXATTRIB3DVPROC)wglGetProcAddress("glVertexAttrib3dv");
	glVertexAttrib3f = (PFNGLVERTEXATTRIB3FPROC)wglGetProcAddress("glVertexAttrib3f");
	glVertexAttrib3fv = (PFNGLVERTEXATTRIB3FVPROC)wglGetProcAddress("glVertexAttrib3fv");
	glVertexAttrib3s = (PFNGLVERTEXATTRIB3SPROC)wglGetProcAddress("glVertexAttrib3s");
	glVertexAttrib3sv = (PFNGLVERTEXATTRIB3SVPROC)wglGetProcAddress("glVertexAttrib3sv");
	glVertexAttrib4Nbv = (PFNGLVERTEXATTRIB4NBVPROC)wglGetProcAddress("glVertexAttrib4Nbv");
	glVertexAttrib4Niv = (PFNGLVERTEXATTRIB4NIVPROC)wglGetProcAddress("glVertexAttrib4Niv");
	glVertexAttrib4Nsv = (PFNGLVERTEXATTRIB4NSVPROC)wglGetProcAddress("glVertexAttrib4Nsv");
	glVertexAttrib4Nub = (PFNGLVERTEXATTRIB4NUBPROC)wglGetProcAddress("glVertexAttrib4Nub");
	glVertexAttrib4Nubv = (PFNGLVERTEXATTRIB4NUBVPROC)wglGetProcAddress("glVertexAttrib4Nubv");
	glVertexAttrib4Nuiv = (PFNGLVERTEXATTRIB4NUIVPROC)wglGetProcAddress("glVertexAttrib4Nuiv");
	glVertexAttrib4Nusv = (PFNGLVERTEXATTRIB4NUSVPROC)wglGetProcAddress("glVertexAttrib4Nusv");
	glVertexAttrib4bv = (PFNGLVERTEXATTRIB4BVPROC)wglGetProcAddress("glVertexAttrib4bv");
	glVertexAttrib4d = (PFNGLVERTEXATTRIB4DPROC)wglGetProcAddress("glVertexAttrib4d");
	glVertexAttrib4dv = (PFNGLVERTEXATTRIB4DVPROC)wglGetProcAddress("glVertexAttrib4dv");
	glVertexAttrib4f = (PFNGLVERTEXATTRIB4FPROC)wglGetProcAddress("glVertexAttrib4f");
	glVertexAttrib4fv = (PFNGLVERTEXATTRIB4FVPROC)wglGetProcAddress("glVertexAttrib4fv");
	glVertexAttrib4iv = (PFNGLVERTEXATTRIB4IVPROC)wglGetProcAddress("glVertexAttrib4iv");
	glVertexAttrib4s = (PFNGLVERTEXATTRIB4SPROC)wglGetProcAddress("glVertexAttrib4s");
	glVertexAttrib4sv = (PFNGLVERTEXATTRIB4SVPROC)wglGetProcAddress("glVertexAttrib4sv");
	glVertexAttrib4ubv = (PFNGLVERTEXATTRIB4UBVPROC)wglGetProcAddress("glVertexAttrib4ubv");
	glVertexAttrib4uiv = (PFNGLVERTEXATTRIB4UIVPROC)wglGetProcAddress("glVertexAttrib4uiv");
	glVertexAttrib4usv = (PFNGLVERTEXATTRIB4USVPROC)wglGetProcAddress("glVertexAttrib4usv");
	glVertexAttribPointer = (PFNGLVERTEXATTRIBPOINTERPROC)wglGetProcAddress("glVertexAttribPointer");

	return ( glBlendEquationSeparate &&	glDrawBuffers && glStencilOpSeparate &&	glStencilFuncSeparate && glStencilMaskSeparate
		&&	glAttachShader && glBindAttribLocation && glCompileShader && glCreateProgram &&	glCreateShader && glDeleteProgram
		&&	glDeleteShader && glDetachShader && glDisableVertexAttribArray && glEnableVertexAttribArray && glGetActiveAttrib
		&& glGetActiveUniform && glGetAttachedShaders && glGetAttribLocation && glGetProgramiv && glGetProgramInfoLog
		&& glGetShaderiv && glGetShaderInfoLog && glGetShaderSource && glGetUniformLocation && glGetUniformfv && glGetUniformiv
		&& glGetVertexAttribdv && glGetVertexAttribfv && glGetVertexAttribiv && glGetVertexAttribPointerv && glIsProgram
		&& glIsShader && glLinkProgram && glShaderSource && glUseProgram && glUniform1f && glUniform2f && glUniform3f
		&& glUniform4f && glUniform1i && glUniform2i && glUniform3i && glUniform4i && glUniform1fv && glUniform2fv
		&& glUniform3fv && glUniform4fv && glUniform1iv && glUniform2iv && glUniform3iv && glUniform4iv && glUniformMatrix2fv
		&& glUniformMatrix3fv && glUniformMatrix4fv && glValidateProgram && glVertexAttrib1d && glVertexAttrib1dv
		&& glVertexAttrib1f && glVertexAttrib1fv && glVertexAttrib1s && glVertexAttrib1sv && glVertexAttrib2d
		&& glVertexAttrib2dv && glVertexAttrib2f && glVertexAttrib2fv && glVertexAttrib2s && glVertexAttrib2sv
		&& glVertexAttrib3d && glVertexAttrib3dv && glVertexAttrib3f && glVertexAttrib3fv && glVertexAttrib3s
		&& glVertexAttrib3sv && glVertexAttrib4Nbv && glVertexAttrib4Niv && glVertexAttrib4Nsv && glVertexAttrib4Nub
		&& glVertexAttrib4Nubv && glVertexAttrib4Nuiv && glVertexAttrib4Nusv && glVertexAttrib4bv && glVertexAttrib4d
		&& glVertexAttrib4dv && glVertexAttrib4f && glVertexAttrib4fv && glVertexAttrib4iv && glVertexAttrib4s
		&& glVertexAttrib4sv && glVertexAttrib4ubv && glVertexAttrib4uiv && glVertexAttrib4usv && glVertexAttribPointer)
		? 1 : 0;
}

/////////////////////////////// GL_VERSION_3_0 ////////////////////////////////

PFNGLCOLORMASKIPROC							pglColorMaski = 0;
PFNGLGETBOOLEANI_VPROC						pglGetBooleani_v = 0;
PFNGLGETINTEGERI_VPROC						pglGetIntegeri_v = 0;
PFNGLENABLEIPROC								pglEnablei = 0;
PFNGLDISABLEIPROC							pglDisablei = 0;
PFNGLISENABLEDIPROC							pglIsEnabledi = 0;
PFNGLBEGINTRANSFORMFEEDBACKPROC				pglBeginTransformFeedback = 0;
PFNGLENDTRANSFORMFEEDBACKPROC				pglEndTransformFeedback = 0;
PFNGLBINDBUFFERRANGEPROC						pglBindBufferRange = 0;
PFNGLBINDBUFFERBASEPROC						pglBindBufferBase = 0;
PFNGLTRANSFORMFEEDBACKVARYINGSPROC			pglTransformFeedbackVaryings = 0;
PFNGLGETTRANSFORMFEEDBACKVARYINGPROC			pglGetTransformFeedbackVarying = 0;
PFNGLCLAMPCOLORPROC							pglClampColor = 0;
PFNGLBEGINCONDITIONALRENDERPROC				pglBeginConditionalRender = 0;
PFNGLENDCONDITIONALRENDERPROC				pglEndConditionalRender = 0;
PFNGLVERTEXATTRIBIPOINTERPROC				pglVertexAttribIPointer = 0;
PFNGLGETVERTEXATTRIBIIVPROC					pglGetVertexAttribIiv = 0;
PFNGLGETVERTEXATTRIBIUIVPROC					pglGetVertexAttribIuiv = 0;
PFNGLVERTEXATTRIBI1IPROC						pglVertexAttribI1i = 0;
PFNGLVERTEXATTRIBI2IPROC						pglVertexAttribI2i = 0;
PFNGLVERTEXATTRIBI3IPROC						pglVertexAttribI3i = 0;
PFNGLVERTEXATTRIBI4IPROC						pglVertexAttribI4i = 0;
PFNGLVERTEXATTRIBI1UIPROC					pglVertexAttribI1ui = 0;
PFNGLVERTEXATTRIBI2UIPROC					pglVertexAttribI2ui = 0;
PFNGLVERTEXATTRIBI3UIPROC					pglVertexAttribI3ui = 0;
PFNGLVERTEXATTRIBI4UIPROC					pglVertexAttribI4ui = 0;
PFNGLVERTEXATTRIBI1IVPROC					pglVertexAttribI1iv = 0;
PFNGLVERTEXATTRIBI2IVPROC					pglVertexAttribI2iv = 0;
PFNGLVERTEXATTRIBI3IVPROC					pglVertexAttribI3iv = 0;
PFNGLVERTEXATTRIBI4IVPROC					pglVertexAttribI4iv = 0;
PFNGLVERTEXATTRIBI1UIVPROC					pglVertexAttribI1uiv = 0;
PFNGLVERTEXATTRIBI2UIVPROC					pglVertexAttribI2uiv = 0;
PFNGLVERTEXATTRIBI3UIVPROC					pglVertexAttribI3uiv = 0;
PFNGLVERTEXATTRIBI4UIVPROC					pglVertexAttribI4uiv = 0;
PFNGLVERTEXATTRIBI4BVPROC					pglVertexAttribI4bv = 0;
PFNGLVERTEXATTRIBI4SVPROC					pglVertexAttribI4sv = 0;
PFNGLVERTEXATTRIBI4UBVPROC					pglVertexAttribI4ubv = 0;
PFNGLVERTEXATTRIBI4USVPROC					pglVertexAttribI4usv = 0;
PFNGLGETUNIFORMUIVPROC						pglGetUniformuiv = 0;
PFNGLBINDFRAGDATALOCATIONPROC				pglBindFragDataLocation = 0;
PFNGLGETFRAGDATALOCATIONPROC					pglGetFragDataLocation = 0;
PFNGLUNIFORM1UIPROC							pglUniform1ui = 0;
PFNGLUNIFORM2UIPROC							pglUniform2ui = 0;
PFNGLUNIFORM3UIPROC							pglUniform3ui = 0;
PFNGLUNIFORM4UIPROC							pglUniform4ui = 0;
PFNGLUNIFORM1UIVPROC							pglUniform1uiv = 0;
PFNGLUNIFORM2UIVPROC							pglUniform2uiv = 0;
PFNGLUNIFORM3UIVPROC							pglUniform3uiv = 0;
PFNGLUNIFORM4UIVPROC							pglUniform4uiv = 0;
PFNGLTEXPARAMETERIIVPROC						pglTexParameterIiv = 0;
PFNGLTEXPARAMETERIUIVPROC					pglTexParameterIuiv = 0;
PFNGLGETTEXPARAMETERIIVPROC					pglGetTexParameterIiv = 0;
PFNGLGETTEXPARAMETERIUIVPROC					pglGetTexParameterIuiv = 0;
PFNGLCLEARBUFFERIVPROC						pglClearBufferiv = 0;
PFNGLCLEARBUFFERUIVPROC						pglClearBufferuiv = 0;
PFNGLCLEARBUFFERFVPROC						pglClearBufferfv = 0;
PFNGLCLEARBUFFERFIPROC						pglClearBufferfi = 0;
PFNGLGETSTRINGIPROC							pglGetStringi = 0;
PFNGLISRENDERBUFFERPROC						pglIsRenderbuffer = 0;
PFNGLBINDRENDERBUFFERPROC					pglBindRenderbuffer = 0;
PFNGLDELETERENDERBUFFERSPROC					pglDeleteRenderbuffers = 0;
PFNGLGENRENDERBUFFERSPROC					pglGenRenderbuffers = 0;
PFNGLRENDERBUFFERSTORAGEPROC					pglRenderbufferStorage = 0;
PFNGLGETRENDERBUFFERPARAMETERIVPROC			pglGetRenderbufferParameteriv = 0;
PFNGLISFRAMEBUFFERPROC						pglIsFramebuffer = 0;
PFNGLBINDFRAMEBUFFERPROC						pglBindFramebuffer = 0;
PFNGLDELETEFRAMEBUFFERSPROC					pglDeleteFramebuffers = 0;
PFNGLGENFRAMEBUFFERSPROC						pglGenFramebuffers = 0;
PFNGLCHECKFRAMEBUFFERSTATUSPROC				pglCheckFramebufferStatus = 0;
PFNGLFRAMEBUFFERTEXTURE1DPROC				pglFramebufferTexture1D = 0;
PFNGLFRAMEBUFFERTEXTURE2DPROC				pglFramebufferTexture2D = 0;
PFNGLFRAMEBUFFERTEXTURE3DPROC				pglFramebufferTexture3D = 0;
PFNGLFRAMEBUFFERRENDERBUFFERPROC				pglFramebufferRenderbuffer = 0;
PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC	pglGetFramebufferAttachmentParameteriv = 0;
PFNGLGENERATEMIPMAPPROC						pglGenerateMipmap = 0;
PFNGLBLITFRAMEBUFFERPROC						pglBlitFramebuffer = 0;
PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC		pglRenderbufferStorageMultisample = 0;
PFNGLFRAMEBUFFERTEXTURELAYERPROC				pglFramebufferTextureLayer = 0;
PFNGLMAPBUFFERRANGEPROC						pglMapBufferRange = 0;
PFNGLFLUSHMAPPEDBUFFERRANGEPROC				pglFlushMappedBufferRange = 0;
PFNGLBINDVERTEXARRAYPROC						pglBindVertexArray = 0;
PFNGLDELETEVERTEXARRAYSPROC					pglDeleteVertexArrays = 0;
PFNGLGENVERTEXARRAYSPROC						pglGenVertexArrays = 0;
PFNGLISVERTEXARRAYPROC						pglIsVertexArray = 0;

int GL_3_0_LoadFuncPointers()
{
	glColorMaski = (PFNGLCOLORMASKIPROC)wglGetProcAddress("glColorMaski");
	glGetBooleani_v = (PFNGLGETBOOLEANI_VPROC)wglGetProcAddress("glGetBooleani_v");
	glGetIntegeri_v = (PFNGLGETINTEGERI_VPROC)wglGetProcAddress("glGetIntegeri_v");
	glEnablei = (PFNGLENABLEIPROC)wglGetProcAddress("glEnablei");
	glDisablei = (PFNGLDISABLEIPROC)wglGetProcAddress("glDisablei");
	glIsEnabledi = (PFNGLISENABLEDIPROC)wglGetProcAddress("glIsEnabledi");
	glBeginTransformFeedback = (PFNGLBEGINTRANSFORMFEEDBACKPROC)wglGetProcAddress("glBeginTransformFeedback");
	glEndTransformFeedback = (PFNGLENDTRANSFORMFEEDBACKPROC)wglGetProcAddress("glEndTransformFeedback");
	glBindBufferRange = (PFNGLBINDBUFFERRANGEPROC)wglGetProcAddress("glBindBufferRange");
	glBindBufferBase = (PFNGLBINDBUFFERBASEPROC)wglGetProcAddress("glBindBufferBase");
	glTransformFeedbackVaryings = (PFNGLTRANSFORMFEEDBACKVARYINGSPROC)wglGetProcAddress("glTransformFeedbackVaryings");
	glGetTransformFeedbackVarying = (PFNGLGETTRANSFORMFEEDBACKVARYINGPROC)wglGetProcAddress("glGetTransformFeedbackVarying");
	glClampColor = (PFNGLCLAMPCOLORPROC)wglGetProcAddress("glClampColor");
	glBeginConditionalRender = (PFNGLBEGINCONDITIONALRENDERPROC)wglGetProcAddress("glBeginConditionalRender");
	glEndConditionalRender = (PFNGLENDCONDITIONALRENDERPROC)wglGetProcAddress("glEndConditionalRender");
	glVertexAttribIPointer = (PFNGLVERTEXATTRIBIPOINTERPROC)wglGetProcAddress("glVertexAttribIPointer");
	glGetVertexAttribIiv = (PFNGLGETVERTEXATTRIBIIVPROC)wglGetProcAddress("glGetVertexAttribIiv");
	glGetVertexAttribIuiv = (PFNGLGETVERTEXATTRIBIUIVPROC)wglGetProcAddress("glGetVertexAttribIuiv");
	glVertexAttribI1i = (PFNGLVERTEXATTRIBI1IPROC)wglGetProcAddress("glVertexAttribI1i");
	glVertexAttribI2i = (PFNGLVERTEXATTRIBI2IPROC)wglGetProcAddress("glVertexAttribI2i");
	glVertexAttribI3i = (PFNGLVERTEXATTRIBI3IPROC)wglGetProcAddress("glVertexAttribI3i");
	glVertexAttribI4i = (PFNGLVERTEXATTRIBI4IPROC)wglGetProcAddress("glVertexAttribI4i");
	glVertexAttribI1ui = (PFNGLVERTEXATTRIBI1UIPROC)wglGetProcAddress("glVertexAttribI1ui");
	glVertexAttribI2ui = (PFNGLVERTEXATTRIBI2UIPROC)wglGetProcAddress("glVertexAttribI2ui");
	glVertexAttribI3ui = (PFNGLVERTEXATTRIBI3UIPROC)wglGetProcAddress("glVertexAttribI3ui");
	glVertexAttribI4ui = (PFNGLVERTEXATTRIBI4UIPROC)wglGetProcAddress("glVertexAttribI4ui");
	glVertexAttribI1iv = (PFNGLVERTEXATTRIBI1IVPROC)wglGetProcAddress("glVertexAttribI1iv");
	glVertexAttribI2iv = (PFNGLVERTEXATTRIBI2IVPROC)wglGetProcAddress("glVertexAttribI2iv");
	glVertexAttribI3iv = (PFNGLVERTEXATTRIBI3IVPROC)wglGetProcAddress("glVertexAttribI3iv");
	glVertexAttribI4iv = (PFNGLVERTEXATTRIBI4IVPROC)wglGetProcAddress("glVertexAttribI4iv");
	glVertexAttribI1uiv = (PFNGLVERTEXATTRIBI1UIVPROC)wglGetProcAddress("glVertexAttribI1uiv");
	glVertexAttribI2uiv = (PFNGLVERTEXATTRIBI2UIVPROC)wglGetProcAddress("glVertexAttribI2uiv");
	glVertexAttribI3uiv = (PFNGLVERTEXATTRIBI3UIVPROC)wglGetProcAddress("glVertexAttribI3uiv");
	glVertexAttribI4uiv = (PFNGLVERTEXATTRIBI4UIVPROC)wglGetProcAddress("glVertexAttribI4uiv");
	glVertexAttribI4bv = (PFNGLVERTEXATTRIBI4BVPROC)wglGetProcAddress("glVertexAttribI4bv");
	glVertexAttribI4sv = (PFNGLVERTEXATTRIBI4SVPROC)wglGetProcAddress("glVertexAttribI4sv");
	glVertexAttribI4ubv = (PFNGLVERTEXATTRIBI4UBVPROC)wglGetProcAddress("glVertexAttribI4ubv");
	glVertexAttribI4usv = (PFNGLVERTEXATTRIBI4USVPROC)wglGetProcAddress("glVertexAttribI4usv");
	glGetUniformuiv = (PFNGLGETUNIFORMUIVPROC)wglGetProcAddress("glGetUniformuiv");
	glBindFragDataLocation = (PFNGLBINDFRAGDATALOCATIONPROC)wglGetProcAddress("glBindFragDataLocation");
	glGetFragDataLocation = (PFNGLGETFRAGDATALOCATIONPROC)wglGetProcAddress("glGetFragDataLocation");
	glUniform1ui = (PFNGLUNIFORM1UIPROC)wglGetProcAddress("glUniform1ui");
	glUniform2ui = (PFNGLUNIFORM2UIPROC)wglGetProcAddress("glUniform2ui");
	glUniform3ui = (PFNGLUNIFORM3UIPROC)wglGetProcAddress("glUniform3ui");
	glUniform4ui = (PFNGLUNIFORM4UIPROC)wglGetProcAddress("glUniform4ui");
	glUniform1uiv = (PFNGLUNIFORM1UIVPROC)wglGetProcAddress("glUniform1uiv");
	glUniform2uiv = (PFNGLUNIFORM2UIVPROC)wglGetProcAddress("glUniform2uiv");
	glUniform3uiv = (PFNGLUNIFORM3UIVPROC)wglGetProcAddress("glUniform3uiv");
	glUniform4uiv = (PFNGLUNIFORM4UIVPROC)wglGetProcAddress("glUniform4uiv");
	glTexParameterIiv = (PFNGLTEXPARAMETERIIVPROC)wglGetProcAddress("glTexParameterIiv");
	glTexParameterIuiv = (PFNGLTEXPARAMETERIUIVPROC)wglGetProcAddress("glTexParameterIuiv");
	glGetTexParameterIiv = (PFNGLGETTEXPARAMETERIIVPROC)wglGetProcAddress("glGetTexParameterIiv");
	glGetTexParameterIuiv = (PFNGLGETTEXPARAMETERIUIVPROC)wglGetProcAddress("glGetTexParameterIuiv");
	glClearBufferiv = (PFNGLCLEARBUFFERIVPROC)wglGetProcAddress("glClearBufferiv");
	glClearBufferuiv = (PFNGLCLEARBUFFERUIVPROC)wglGetProcAddress("glClearBufferuiv");
	glClearBufferfv = (PFNGLCLEARBUFFERFVPROC)wglGetProcAddress("glClearBufferfv");
	glClearBufferfi = (PFNGLCLEARBUFFERFIPROC)wglGetProcAddress("glClearBufferfi");
	glGetStringi = (PFNGLGETSTRINGIPROC)wglGetProcAddress("glGetStringi");
	glIsRenderbuffer = (PFNGLISRENDERBUFFERPROC)wglGetProcAddress("glIsRenderbuffer");
	glBindRenderbuffer = (PFNGLBINDRENDERBUFFERPROC)wglGetProcAddress("glBindRenderbuffer");
	glDeleteRenderbuffers = (PFNGLDELETERENDERBUFFERSPROC)wglGetProcAddress("glDeleteRenderbuffers");
	glGenRenderbuffers = (PFNGLGENRENDERBUFFERSPROC)wglGetProcAddress("glGenRenderbuffers");
	glRenderbufferStorage = (PFNGLRENDERBUFFERSTORAGEPROC)wglGetProcAddress("glRenderbufferStorage");
	glGetRenderbufferParameteriv = (PFNGLGETRENDERBUFFERPARAMETERIVPROC)wglGetProcAddress("glGetRenderbufferParameteriv");
	glIsFramebuffer = (PFNGLISFRAMEBUFFERPROC)wglGetProcAddress("glIsFramebuffer");
	glBindFramebuffer = (PFNGLBINDFRAMEBUFFERPROC)wglGetProcAddress("glBindFramebuffer");
	glDeleteFramebuffers = (PFNGLDELETEFRAMEBUFFERSPROC)wglGetProcAddress("glDeleteFramebuffers");
	glGenFramebuffers = (PFNGLGENFRAMEBUFFERSPROC)wglGetProcAddress("glGenFramebuffers");
	glCheckFramebufferStatus = (PFNGLCHECKFRAMEBUFFERSTATUSPROC)wglGetProcAddress("glCheckFramebufferStatus");
	glFramebufferTexture1D = (PFNGLFRAMEBUFFERTEXTURE1DPROC)wglGetProcAddress("glFramebufferTexture1D");
	glFramebufferTexture2D = (PFNGLFRAMEBUFFERTEXTURE2DPROC)wglGetProcAddress("glFramebufferTexture2D");
	glFramebufferTexture3D = (PFNGLFRAMEBUFFERTEXTURE3DPROC)wglGetProcAddress("glFramebufferTexture3D");
	glFramebufferRenderbuffer = (PFNGLFRAMEBUFFERRENDERBUFFERPROC)wglGetProcAddress("glFramebufferRenderbuffer");
	glGetFramebufferAttachmentParameteriv = (PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC)wglGetProcAddress("glGetFramebufferAttachmentParameteriv");
	glGenerateMipmap = (PFNGLGENERATEMIPMAPPROC)wglGetProcAddress("glGenerateMipmap");
	glBlitFramebuffer = (PFNGLBLITFRAMEBUFFERPROC)wglGetProcAddress("glBlitFramebuffer");
	glRenderbufferStorageMultisample = (PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC)wglGetProcAddress("glRenderbufferStorageMultisample");
	glFramebufferTextureLayer = (PFNGLFRAMEBUFFERTEXTURELAYERPROC)wglGetProcAddress("glFramebufferTextureLayer");
	glMapBufferRange = (PFNGLMAPBUFFERRANGEPROC)wglGetProcAddress("glMapBufferRange");
	glFlushMappedBufferRange = (PFNGLFLUSHMAPPEDBUFFERRANGEPROC)wglGetProcAddress("glFlushMappedBufferRange");
	glBindVertexArray = (PFNGLBINDVERTEXARRAYPROC)wglGetProcAddress("glBindVertexArray");
	glDeleteVertexArrays = (PFNGLDELETEVERTEXARRAYSPROC)wglGetProcAddress("glDeleteVertexArrays");
	glGenVertexArrays = (PFNGLGENVERTEXARRAYSPROC)wglGetProcAddress("glGenVertexArrays");
	glIsVertexArray = (PFNGLISVERTEXARRAYPROC)wglGetProcAddress("glIsVertexArray");

	return (glColorMaski && glGetBooleani_v && glGetIntegeri_v && glEnablei && glDisablei && glIsEnabledi && glBeginTransformFeedback
		&& glEndTransformFeedback && glBindBufferRange && glBindBufferBase && glTransformFeedbackVaryings && glGetTransformFeedbackVarying
		&& glClampColor && glBeginConditionalRender && glEndConditionalRender && glVertexAttribIPointer && glGetVertexAttribIiv
		&& glGetVertexAttribIuiv && glVertexAttribI1i && glVertexAttribI2i && glVertexAttribI3i && glVertexAttribI4i && glVertexAttribI1ui
		&& glVertexAttribI2ui && glVertexAttribI3ui && glVertexAttribI4ui && glVertexAttribI1iv && glVertexAttribI2iv && glVertexAttribI3iv
		&& glVertexAttribI4iv && glVertexAttribI1uiv && glVertexAttribI2uiv && glVertexAttribI3uiv && glVertexAttribI4uiv && glVertexAttribI4bv
		&& glVertexAttribI4sv && glVertexAttribI4ubv && glVertexAttribI4usv && glGetUniformuiv && glBindFragDataLocation && glGetFragDataLocation
		&& glUniform1ui && glUniform2ui && glUniform3ui && glUniform4ui && glUniform1uiv && glUniform2uiv && glUniform3uiv && glUniform4uiv
		&& glTexParameterIiv && glTexParameterIuiv && glGetTexParameterIiv && glGetTexParameterIuiv && glClearBufferiv && glClearBufferuiv
		&& glClearBufferfv && glClearBufferfi && glGetStringi && glIsRenderbuffer && glBindRenderbuffer && glDeleteRenderbuffers && glGenRenderbuffers
		&& glRenderbufferStorage && glGetRenderbufferParameteriv && glIsFramebuffer && glBindFramebuffer && glDeleteFramebuffers && glGenFramebuffers
		&& glCheckFramebufferStatus && glFramebufferTexture1D && glFramebufferTexture2D && glFramebufferTexture3D && glFramebufferRenderbuffer
		&& glGetFramebufferAttachmentParameteriv && glGenerateMipmap && glBlitFramebuffer && glRenderbufferStorageMultisample && glFramebufferTextureLayer
		&& glMapBufferRange && glFlushMappedBufferRange && glBindVertexArray && glDeleteVertexArrays && glGenVertexArrays && glIsVertexArray) ? 1 : 0;
}

/////////////////////////////// GL_VERSION_3_1 ////////////////////////////////

PFNGLDRAWARRAYSINSTANCEDPROC					pglDrawArraysInstanced = 0;
PFNGLDRAWELEMENTSINSTANCEDPROC				pglDrawElementsInstanced = 0;
PFNGLTEXBUFFERPROC							pglTexBuffer = 0;
PFNGLPRIMITIVERESTARTINDEXPROC				pglPrimitiveRestartIndex = 0;
PFNGLCOPYBUFFERSUBDATAPROC					pglCopyBufferSubData = 0;
PFNGLGETUNIFORMINDICESPROC					pglGetUniformIndices = 0;
PFNGLGETACTIVEUNIFORMSIVPROC					pglGetActiveUniformsiv = 0;
PFNGLGETACTIVEUNIFORMNAMEPROC				pglGetActiveUniformName = 0;
PFNGLGETUNIFORMBLOCKINDEXPROC				pglGetUniformBlockIndex = 0;
PFNGLGETACTIVEUNIFORMBLOCKIVPROC				pglGetActiveUniformBlockiv = 0;
PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC			pglGetActiveUniformBlockName = 0;
PFNGLUNIFORMBLOCKBINDINGPROC					pglUniformBlockBinding = 0;

int GL_3_1_LoadFuncPointers()
{
	glDrawArraysInstanced = (PFNGLDRAWARRAYSINSTANCEDPROC)wglGetProcAddress("glDrawArraysInstanced");
	glDrawElementsInstanced = (PFNGLDRAWELEMENTSINSTANCEDPROC)wglGetProcAddress("glDrawElementsInstanced");
	glTexBuffer = (PFNGLTEXBUFFERPROC)wglGetProcAddress("glTexBuffer");
	glPrimitiveRestartIndex = (PFNGLPRIMITIVERESTARTINDEXPROC)wglGetProcAddress("glPrimitiveRestartIndex");
	glCopyBufferSubData = (PFNGLCOPYBUFFERSUBDATAPROC)wglGetProcAddress("glCopyBufferSubData");
	glGetUniformIndices = (PFNGLGETUNIFORMINDICESPROC)wglGetProcAddress("glGetUniformIndices");
	glGetActiveUniformsiv = (PFNGLGETACTIVEUNIFORMSIVPROC)wglGetProcAddress("glGetActiveUniformsiv");
	glGetActiveUniformName = (PFNGLGETACTIVEUNIFORMNAMEPROC)wglGetProcAddress("glGetActiveUniformName");
	glGetUniformBlockIndex = (PFNGLGETUNIFORMBLOCKINDEXPROC)wglGetProcAddress("glGetUniformBlockIndex");
	glGetActiveUniformBlockiv = (PFNGLGETACTIVEUNIFORMBLOCKIVPROC)wglGetProcAddress("glGetActiveUniformBlockiv");
	glGetActiveUniformBlockName = (PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC)wglGetProcAddress("glGetActiveUniformBlockName");
	glUniformBlockBinding = (PFNGLUNIFORMBLOCKBINDINGPROC)wglGetProcAddress("glUniformBlockBinding");

	return (glDrawArraysInstanced && glDrawElementsInstanced && glTexBuffer && glPrimitiveRestartIndex && glCopyBufferSubData
		&& glGetUniformIndices && glGetActiveUniformsiv && glGetActiveUniformName && glGetUniformBlockIndex
		&& glGetActiveUniformBlockiv && glGetActiveUniformBlockName && glUniformBlockBinding) ? 1 : 0;
}

/////////////////////////////// GL_VERSION_3_2 ////////////////////////////////

PFNGLDRAWELEMENTSBASEVERTEXPROC				pglDrawElementsBaseVertex = 0;
PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC			pglDrawRangeElementsBaseVertex = 0;
PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC		pglDrawElementsInstancedBaseVertex = 0;
PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC			pglMultiDrawElementsBaseVertex = 0;
PFNGLPROVOKINGVERTEXPROC						pglProvokingVertex = 0;
PFNGLFENCESYNCPROC							pglFenceSync = 0;
PFNGLISSYNCPROC								pglIsSync = 0;
PFNGLDELETESYNCPROC							pglDeleteSync = 0;
PFNGLCLIENTWAITSYNCPROC						pglClientWaitSync = 0;
PFNGLWAITSYNCPROC							pglWaitSync = 0;
PFNGLGETINTEGER64VPROC						pglGetInteger64v = 0;
PFNGLGETSYNCIVPROC							pglGetSynciv = 0;
PFNGLGETINTEGER64I_VPROC						pglGetInteger64i_v = 0;
PFNGLGETBUFFERPARAMETERI64VPROC				pglGetBufferParameteri64v = 0;
PFNGLFRAMEBUFFERTEXTUREPROC					pglFramebufferTexture = 0;
PFNGLTEXIMAGE2DMULTISAMPLEPROC				pglTexImage2DMultisample = 0;
PFNGLTEXIMAGE3DMULTISAMPLEPROC				pglTexImage3DMultisample = 0;
PFNGLGETMULTISAMPLEFVPROC					pglGetMultisamplefv = 0;
PFNGLSAMPLEMASKIPROC							pglSampleMaski = 0;

int GL_3_2_LoadFuncPointers()
{
	glDrawElementsBaseVertex = (PFNGLDRAWELEMENTSBASEVERTEXPROC)wglGetProcAddress("glDrawElementsBaseVertex");
	glDrawRangeElementsBaseVertex = (PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC)wglGetProcAddress("glDrawRangeElementsBaseVertex");
	glDrawElementsInstancedBaseVertex = (PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC)wglGetProcAddress("glDrawElementsInstancedBaseVertex");
	glMultiDrawElementsBaseVertex = (PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC)wglGetProcAddress("glMultiDrawElementsBaseVertex");
	glProvokingVertex = (PFNGLPROVOKINGVERTEXPROC)wglGetProcAddress("glProvokingVertex");
	glFenceSync = (PFNGLFENCESYNCPROC)wglGetProcAddress("glFenceSync");
	glIsSync = (PFNGLISSYNCPROC)wglGetProcAddress("glIsSync");
	glDeleteSync = (PFNGLDELETESYNCPROC)wglGetProcAddress("glDeleteSync");
	glClientWaitSync = (PFNGLCLIENTWAITSYNCPROC)wglGetProcAddress("glClientWaitSync");
	glWaitSync = (PFNGLWAITSYNCPROC)wglGetProcAddress("glWaitSync");
	glGetInteger64v = (PFNGLGETINTEGER64VPROC)wglGetProcAddress("glGetInteger64v");
	glGetSynciv = (PFNGLGETSYNCIVPROC)wglGetProcAddress("glGetSynciv");
	glGetInteger64i_v = (PFNGLGETINTEGER64I_VPROC)wglGetProcAddress("glGetInteger64i_v");
	glGetBufferParameteri64v = (PFNGLGETBUFFERPARAMETERI64VPROC)wglGetProcAddress("glGetBufferParameteri64v");
	glFramebufferTexture = (PFNGLFRAMEBUFFERTEXTUREPROC)wglGetProcAddress("glFramebufferTexture");
	glTexImage2DMultisample = (PFNGLTEXIMAGE2DMULTISAMPLEPROC)wglGetProcAddress("glTexImage2DMultisample");
	glTexImage3DMultisample = (PFNGLTEXIMAGE3DMULTISAMPLEPROC)wglGetProcAddress("glTexImage3DMultisample");
	glGetMultisamplefv = (PFNGLGETMULTISAMPLEFVPROC)wglGetProcAddress("glGetMultisamplefv");
	glSampleMaski = (PFNGLSAMPLEMASKIPROC)wglGetProcAddress("glSampleMaski");

	return (glDrawElementsBaseVertex && glDrawRangeElementsBaseVertex && glDrawElementsInstancedBaseVertex && glMultiDrawElementsBaseVertex && 
		glProvokingVertex && glFenceSync && glIsSync && glDeleteSync && glClientWaitSync && glWaitSync && glGetInteger64v && 
		glGetSynciv && glGetInteger64i_v && glGetBufferParameteri64v && glFramebufferTexture && glTexImage2DMultisample && 
		glTexImage3DMultisample && glGetMultisamplefv && glSampleMaski) ? 1 : 0;
}

/////////////////////////////// GL_VERSION_3_3 ////////////////////////////////

PFNGLBINDFRAGDATALOCATIONINDEXEDPROC		pglBindFragDataLocationIndexed = 0;
PFNGLGETFRAGDATAINDEXPROC				pglGetFragDataIndex = 0;
PFNGLGENSAMPLERSPROC						pglGenSamplers = 0;
PFNGLDELETESAMPLERSPROC					pglDeleteSamplers = 0;
PFNGLISSAMPLERPROC						pglIsSampler = 0;
PFNGLBINDSAMPLERPROC						pglBindSampler = 0;
PFNGLSAMPLERPARAMETERIPROC				pglSamplerParameteri = 0;
PFNGLSAMPLERPARAMETERIVPROC				pglSamplerParameteriv = 0;
PFNGLSAMPLERPARAMETERFPROC				pglSamplerParameterf = 0;
PFNGLSAMPLERPARAMETERFVPROC				pglSamplerParameterfv = 0;
PFNGLSAMPLERPARAMETERIIVPROC				pglSamplerParameterIiv = 0;
PFNGLSAMPLERPARAMETERIUIVPROC			pglSamplerParameterIuiv = 0;
PFNGLGETSAMPLERPARAMETERIVPROC			pglGetSamplerParameteriv = 0;
PFNGLGETSAMPLERPARAMETERIIVPROC			pglGetSamplerParameterIiv = 0;
PFNGLGETSAMPLERPARAMETERFVPROC			pglGetSamplerParameterfv = 0;
PFNGLGETSAMPLERPARAMETERIUIVPROC			pglGetSamplerParameterIuiv = 0;
PFNGLQUERYCOUNTERPROC					pglQueryCounter = 0;
PFNGLGETQUERYOBJECTI64VPROC				pglGetQueryObjecti64v = 0;
PFNGLGETQUERYOBJECTUI64VPROC				pglGetQueryObjectui64v = 0;
PFNGLVERTEXATTRIBDIVISORPROC				pglVertexAttribDivisor = 0;
PFNGLVERTEXATTRIBP1UIPROC				pglVertexAttribP1ui = 0;
PFNGLVERTEXATTRIBP1UIVPROC				pglVertexAttribP1uiv = 0;
PFNGLVERTEXATTRIBP2UIPROC				pglVertexAttribP2ui = 0;
PFNGLVERTEXATTRIBP2UIVPROC				pglVertexAttribP2uiv = 0;
PFNGLVERTEXATTRIBP3UIPROC				pglVertexAttribP3ui = 0;
PFNGLVERTEXATTRIBP3UIVPROC				pglVertexAttribP3uiv = 0;
PFNGLVERTEXATTRIBP4UIPROC				pglVertexAttribP4ui = 0;
PFNGLVERTEXATTRIBP4UIVPROC				pglVertexAttribP4uiv = 0;

int GL_3_3_LoadFuncPointers()
{
	glBindFragDataLocationIndexed = (PFNGLBINDFRAGDATALOCATIONINDEXEDPROC)wglGetProcAddress("glBindFragDataLocationIndexed");
	glGetFragDataIndex = (PFNGLGETFRAGDATAINDEXPROC)wglGetProcAddress("glGetFragDataIndex");
	glGenSamplers = (PFNGLGENSAMPLERSPROC)wglGetProcAddress("glGenSamplers");
	glDeleteSamplers = (PFNGLDELETESAMPLERSPROC)wglGetProcAddress("glDeleteSamplers");
	glIsSampler = (PFNGLISSAMPLERPROC)wglGetProcAddress("glIsSampler");
	glBindSampler = (PFNGLBINDSAMPLERPROC)wglGetProcAddress("glBindSampler");
	glSamplerParameteri = (PFNGLSAMPLERPARAMETERIPROC)wglGetProcAddress("glSamplerParameteri");
	glSamplerParameteriv = (PFNGLSAMPLERPARAMETERIVPROC)wglGetProcAddress("glSamplerParameteriv");
	glSamplerParameterf = (PFNGLSAMPLERPARAMETERFPROC)wglGetProcAddress("glSamplerParameterf");
	glSamplerParameterfv = (PFNGLSAMPLERPARAMETERFVPROC)wglGetProcAddress("glSamplerParameterfv");
	glSamplerParameterIiv = (PFNGLSAMPLERPARAMETERIIVPROC)wglGetProcAddress("glSamplerParameterIiv");
	glSamplerParameterIuiv = (PFNGLSAMPLERPARAMETERIUIVPROC)wglGetProcAddress("glSamplerParameterIuiv");
	glGetSamplerParameteriv = (PFNGLGETSAMPLERPARAMETERIVPROC)wglGetProcAddress("glGetSamplerParameteriv");
	glGetSamplerParameterIiv = (PFNGLGETSAMPLERPARAMETERIIVPROC)wglGetProcAddress("glGetSamplerParameterIiv");
	glGetSamplerParameterfv = (PFNGLGETSAMPLERPARAMETERFVPROC)wglGetProcAddress("glGetSamplerParameterfv");
	glGetSamplerParameterIuiv = (PFNGLGETSAMPLERPARAMETERIUIVPROC)wglGetProcAddress("glGetSamplerParameterIuiv");
	glQueryCounter  = (PFNGLQUERYCOUNTERPROC)wglGetProcAddress("glQueryCounter");
	glGetQueryObjecti64v = (PFNGLGETQUERYOBJECTI64VPROC)wglGetProcAddress("glGetQueryObjecti64v");
	glGetQueryObjectui64v = (PFNGLGETQUERYOBJECTUI64VPROC)wglGetProcAddress("glGetQueryObjectui64v");
	glVertexAttribDivisor = (PFNGLVERTEXATTRIBDIVISORPROC)wglGetProcAddress("glVertexAttribDivisor");
	glVertexAttribP1ui = (PFNGLVERTEXATTRIBP1UIPROC)wglGetProcAddress("glVertexAttribP1ui");
	glVertexAttribP1uiv = (PFNGLVERTEXATTRIBP1UIVPROC)wglGetProcAddress("glVertexAttribP1uiv");
	glVertexAttribP2ui = (PFNGLVERTEXATTRIBP2UIPROC)wglGetProcAddress("glVertexAttribP2ui");
	glVertexAttribP2uiv = (PFNGLVERTEXATTRIBP2UIVPROC)wglGetProcAddress("glVertexAttribP2uiv");
	glVertexAttribP3ui = (PFNGLVERTEXATTRIBP3UIPROC)wglGetProcAddress("glVertexAttribP3ui");
	glVertexAttribP3uiv = (PFNGLVERTEXATTRIBP3UIVPROC)wglGetProcAddress("glVertexAttribP3uiv");
	glVertexAttribP4ui = (PFNGLVERTEXATTRIBP4UIPROC)wglGetProcAddress("glVertexAttribP4ui");
	glVertexAttribP4uiv = (PFNGLVERTEXATTRIBP4UIVPROC)wglGetProcAddress("glVertexAttribP4uiv");

	return (glBindFragDataLocationIndexed && glGetFragDataIndex && glGenSamplers && glDeleteSamplers && glIsSampler && 
		glBindSampler && glSamplerParameteri && glSamplerParameteriv && glSamplerParameterf && 
		glSamplerParameterfv && glSamplerParameterIiv && glSamplerParameterIuiv && glGetSamplerParameteriv && 
		glGetSamplerParameterIiv && glGetSamplerParameterfv && glGetSamplerParameterIuiv && glQueryCounter  && 
		glGetQueryObjecti64v && glGetQueryObjectui64v && glVertexAttribDivisor && glVertexAttribP1ui && 
		glVertexAttribP1uiv && glVertexAttribP2ui && glVertexAttribP2uiv && glVertexAttribP3ui && 
		glVertexAttribP3uiv && glVertexAttribP4ui && glVertexAttribP4uiv) ? 1 : 0;
}

/////////////////////////////// GL_VERSION_4_0 ////////////////////////////////

PFNGLMINSAMPLESHADINGPROC					pglMinSampleShading = 0;
PFNGLBLENDEQUATIONIPROC						pglBlendEquationi = 0;
PFNGLBLENDEQUATIONSEPARATEIPROC				pglBlendEquationSeparatei = 0;
PFNGLBLENDFUNCIPROC							pglBlendFunci = 0;
PFNGLBLENDFUNCSEPARATEIPROC					pglBlendFuncSeparatei = 0;
PFNGLDRAWARRAYSINDIRECTPROC					pglDrawArraysIndirect = 0;
PFNGLDRAWELEMENTSINDIRECTPROC				pglDrawElementsIndirect = 0;
PFNGLUNIFORM1DPROC							pglUniform1d = 0;
PFNGLUNIFORM2DPROC							pglUniform2d = 0;
PFNGLUNIFORM3DPROC							pglUniform3d = 0;
PFNGLUNIFORM4DPROC							pglUniform4d = 0;
PFNGLUNIFORM1DVPROC							pglUniform1dv = 0;
PFNGLUNIFORM2DVPROC							pglUniform2dv = 0;
PFNGLUNIFORM3DVPROC							pglUniform3dv = 0;
PFNGLUNIFORM4DVPROC							pglUniform4dv = 0;
PFNGLUNIFORMMATRIX2DVPROC					pglUniformMatrix2dv = 0;
PFNGLUNIFORMMATRIX3DVPROC					pglUniformMatrix3dv = 0;
PFNGLUNIFORMMATRIX4DVPROC					pglUniformMatrix4dv = 0;
PFNGLUNIFORMMATRIX2X3DVPROC					pglUniformMatrix2x3dv = 0;
PFNGLUNIFORMMATRIX2X4DVPROC					pglUniformMatrix2x4dv = 0;
PFNGLUNIFORMMATRIX3X2DVPROC					pglUniformMatrix3x2dv = 0;
PFNGLUNIFORMMATRIX3X4DVPROC					pglUniformMatrix3x4dv = 0;
PFNGLUNIFORMMATRIX4X2DVPROC					pglUniformMatrix4x2dv = 0;
PFNGLUNIFORMMATRIX4X3DVPROC					pglUniformMatrix4x3dv = 0;
PFNGLGETUNIFORMDVPROC						pglGetUniformdv = 0;
PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC		pglGetSubroutineUniformLocation = 0;
PFNGLGETSUBROUTINEINDEXPROC					pglGetSubroutineIndex = 0;
PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC		pglGetActiveSubroutineUniformiv = 0;
PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC		pglGetActiveSubroutineUniformName = 0;
PFNGLGETACTIVESUBROUTINENAMEPROC				pglGetActiveSubroutineName = 0;
PFNGLUNIFORMSUBROUTINESUIVPROC				pglUniformSubroutinesuiv = 0;
PFNGLGETUNIFORMSUBROUTINEUIVPROC				pglGetUniformSubroutineuiv = 0;
PFNGLGETPROGRAMSTAGEIVPROC					pglGetProgramStageiv = 0;
PFNGLPATCHPARAMETERIPROC						pglPatchParameteri = 0;
PFNGLPATCHPARAMETERFVPROC					pglPatchParameterfv = 0;
PFNGLBINDTRANSFORMFEEDBACKPROC				pglBindTransformFeedback = 0;
PFNGLDELETETRANSFORMFEEDBACKSPROC			pglDeleteTransformFeedbacks = 0;
PFNGLGENTRANSFORMFEEDBACKSPROC				pglGenTransformFeedbacks = 0;
PFNGLISTRANSFORMFEEDBACKPROC					pglIsTransformFeedback = 0;
PFNGLPAUSETRANSFORMFEEDBACKPROC				pglPauseTransformFeedback = 0;
PFNGLRESUMETRANSFORMFEEDBACKPROC				pglResumeTransformFeedback = 0;
PFNGLDRAWTRANSFORMFEEDBACKPROC				pglDrawTransformFeedback = 0;
PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC			pglDrawTransformFeedbackStream = 0;
PFNGLBEGINQUERYINDEXEDPROC					pglBeginQueryIndexed = 0;
PFNGLENDQUERYINDEXEDPROC						pglEndQueryIndexed = 0;
PFNGLGETQUERYINDEXEDIVPROC					pglGetQueryIndexediv = 0;

int GL_4_0_LoadFuncPointers()
{
	glMinSampleShading = (PFNGLMINSAMPLESHADINGPROC)wglGetProcAddress("glMinSampleShading");
	glBlendEquationi = (PFNGLBLENDEQUATIONIPROC)wglGetProcAddress("glBlendEquationi");
	glBlendEquationSeparatei = (PFNGLBLENDEQUATIONSEPARATEIPROC)wglGetProcAddress("glBlendEquationSeparatei");
	glBlendFunci = (PFNGLBLENDFUNCIPROC)wglGetProcAddress("glBlendFunci");
	glBlendFuncSeparatei = (PFNGLBLENDFUNCSEPARATEIPROC)wglGetProcAddress("glBlendFuncSeparatei");
	glDrawArraysIndirect = (PFNGLDRAWARRAYSINDIRECTPROC)wglGetProcAddress("glDrawArraysIndirect");
	glDrawElementsIndirect = (PFNGLDRAWELEMENTSINDIRECTPROC)wglGetProcAddress("glDrawElementsIndirect");
	glUniform1d = (PFNGLUNIFORM1DPROC)wglGetProcAddress("glUniform1d");
	glUniform2d = (PFNGLUNIFORM2DPROC)wglGetProcAddress("glUniform2d");
	glUniform3d = (PFNGLUNIFORM3DPROC)wglGetProcAddress("glUniform3d");
	glUniform4d = (PFNGLUNIFORM4DPROC)wglGetProcAddress("glUniform4d");
	glUniform1dv = (PFNGLUNIFORM1DVPROC)wglGetProcAddress("glUniform1dv");
	glUniform2dv = (PFNGLUNIFORM2DVPROC)wglGetProcAddress("glUniform2dv");
	glUniform3dv = (PFNGLUNIFORM3DVPROC)wglGetProcAddress("glUniform3dv");
	glUniform4dv = (PFNGLUNIFORM4DVPROC)wglGetProcAddress("glUniform4dv");
	glUniformMatrix2dv = (PFNGLUNIFORMMATRIX2DVPROC)wglGetProcAddress("glUniformMatrix2dv");
	glUniformMatrix3dv = (PFNGLUNIFORMMATRIX3DVPROC)wglGetProcAddress("glUniformMatrix3dv");
	glUniformMatrix4dv = (PFNGLUNIFORMMATRIX4DVPROC)wglGetProcAddress("glUniformMatrix4dv");
	glUniformMatrix2x3dv = (PFNGLUNIFORMMATRIX2X3DVPROC)wglGetProcAddress("glUniformMatrix2x3dv");
	glUniformMatrix2x4dv = (PFNGLUNIFORMMATRIX2X4DVPROC)wglGetProcAddress("glUniformMatrix2x4dv");
	glUniformMatrix3x2dv = (PFNGLUNIFORMMATRIX3X2DVPROC)wglGetProcAddress("glUniformMatrix3x2dv");
	glUniformMatrix3x4dv = (PFNGLUNIFORMMATRIX3X4DVPROC)wglGetProcAddress("glUniformMatrix3x4dv");
	glUniformMatrix4x2dv = (PFNGLUNIFORMMATRIX4X2DVPROC)wglGetProcAddress("glUniformMatrix4x2dv");
	glUniformMatrix4x3dv = (PFNGLUNIFORMMATRIX4X3DVPROC)wglGetProcAddress("glUniformMatrix4x3dv");
	glGetUniformdv = (PFNGLGETUNIFORMDVPROC)wglGetProcAddress("glGetUniformdv");
	glGetSubroutineUniformLocation = (PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC)wglGetProcAddress("glGetSubroutineUniformLocation");
	glGetSubroutineIndex = (PFNGLGETSUBROUTINEINDEXPROC)wglGetProcAddress("glGetSubroutineIndex");
	glGetActiveSubroutineUniformiv = (PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC)wglGetProcAddress("glGetActiveSubroutineUniformiv");
	glGetActiveSubroutineUniformName = (PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC)wglGetProcAddress("glGetActiveSubroutineUniformName");
	glGetActiveSubroutineName = (PFNGLGETACTIVESUBROUTINENAMEPROC)wglGetProcAddress("glGetActiveSubroutineName");
	glUniformSubroutinesuiv = (PFNGLUNIFORMSUBROUTINESUIVPROC)wglGetProcAddress("glUniformSubroutinesuiv");
	glGetUniformSubroutineuiv = (PFNGLGETUNIFORMSUBROUTINEUIVPROC)wglGetProcAddress("glGetUniformSubroutineuiv");
	glGetProgramStageiv = (PFNGLGETPROGRAMSTAGEIVPROC)wglGetProcAddress("glGetProgramStageiv");
	glPatchParameteri = (PFNGLPATCHPARAMETERIPROC)wglGetProcAddress("glPatchParameteri");
	glPatchParameterfv = (PFNGLPATCHPARAMETERFVPROC)wglGetProcAddress("glPatchParameterfv");
	glBindTransformFeedback = (PFNGLBINDTRANSFORMFEEDBACKPROC)wglGetProcAddress("glBindTransformFeedback");
	glDeleteTransformFeedbacks = (PFNGLDELETETRANSFORMFEEDBACKSPROC)wglGetProcAddress("glDeleteTransformFeedbacks");
	glGenTransformFeedbacks = (PFNGLGENTRANSFORMFEEDBACKSPROC)wglGetProcAddress("glGenTransformFeedbacks");
	glIsTransformFeedback = (PFNGLISTRANSFORMFEEDBACKPROC)wglGetProcAddress("glIsTransformFeedback");
	glPauseTransformFeedback = (PFNGLPAUSETRANSFORMFEEDBACKPROC)wglGetProcAddress("glPauseTransformFeedback");
	glResumeTransformFeedback = (PFNGLRESUMETRANSFORMFEEDBACKPROC)wglGetProcAddress("glResumeTransformFeedback");
	glDrawTransformFeedback = (PFNGLDRAWTRANSFORMFEEDBACKPROC)wglGetProcAddress("glDrawTransformFeedback");
	glDrawTransformFeedbackStream = (PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC)wglGetProcAddress("glDrawTransformFeedbackStream");
	glBeginQueryIndexed = (PFNGLBEGINQUERYINDEXEDPROC)wglGetProcAddress("glBeginQueryIndexed");
	glEndQueryIndexed = (PFNGLENDQUERYINDEXEDPROC)wglGetProcAddress("glEndQueryIndexed");
	glGetQueryIndexediv = (PFNGLGETQUERYINDEXEDIVPROC)wglGetProcAddress("glGetQueryIndexediv");

	return ( glMinSampleShading && glBlendEquationi && glBlendEquationSeparatei && glBlendFunci && glBlendFuncSeparatei && 
		glDrawArraysIndirect && glDrawElementsIndirect && glUniform1d && glUniform2d && glUniform3d && glUniform4d && glUniform1dv && 
		glUniform2dv && glUniform3dv && glUniform4dv && glUniformMatrix2dv && glUniformMatrix3dv && glUniformMatrix4dv && 
		glUniformMatrix2x3dv && glUniformMatrix2x4dv && glUniformMatrix3x2dv && glUniformMatrix3x4dv && glUniformMatrix4x2dv && 
		glUniformMatrix4x3dv && glGetUniformdv && glGetSubroutineUniformLocation && glGetSubroutineIndex && glGetActiveSubroutineUniformiv && 
		glGetActiveSubroutineUniformName && glGetActiveSubroutineName && glUniformSubroutinesuiv && glGetUniformSubroutineuiv && 
		glGetProgramStageiv && glPatchParameteri && glPatchParameterfv && glBindTransformFeedback && glDeleteTransformFeedbacks && 
		glGenTransformFeedbacks && glIsTransformFeedback && glPauseTransformFeedback && glResumeTransformFeedback && 
		glDrawTransformFeedback && glDrawTransformFeedbackStream && glBeginQueryIndexed && glEndQueryIndexed && glGetQueryIndexediv	) ? 1 : 0;
}
/////////////////////////////// GL_VERSION_4_1 ////////////////////////////////

PFNGLRELEASESHADERCOMPILERPROC		pglReleaseShaderCompiler = 0;
PFNGLSHADERBINARYPROC				pglShaderBinary = 0;
PFNGLGETSHADERPRECISIONFORMATPROC	pglGetShaderPrecisionFormat = 0;
PFNGLDEPTHRANGEFPROC					pglDepthRangef = 0;
PFNGLCLEARDEPTHFPROC					pglClearDepthf = 0;
PFNGLGETPROGRAMBINARYPROC			pglGetProgramBinary = 0;
PFNGLPROGRAMBINARYPROC				pglProgramBinary = 0;
PFNGLPROGRAMPARAMETERIPROC			pglProgramParameteri = 0;
PFNGLUSEPROGRAMSTAGESPROC			pglUseProgramStages = 0;
PFNGLACTIVESHADERPROGRAMPROC			pglActiveShaderProgram = 0;
PFNGLCREATESHADERPROGRAMVPROC		pglCreateShaderProgramv = 0;
PFNGLBINDPROGRAMPIPELINEPROC			pglBindProgramPipeline = 0;
PFNGLDELETEPROGRAMPIPELINESPROC		pglDeleteProgramPipelines = 0;
PFNGLGENPROGRAMPIPELINESPROC			pglGenProgramPipelines = 0;
PFNGLISPROGRAMPIPELINEPROC			pglIsProgramPipeline = 0;
PFNGLGETPROGRAMPIPELINEIVPROC		pglGetProgramPipelineiv = 0;
PFNGLPROGRAMUNIFORM1IPROC			pglProgramUniform1i = 0;
PFNGLPROGRAMUNIFORM1IVPROC			pglProgramUniform1iv = 0;
PFNGLPROGRAMUNIFORM1FPROC			pglProgramUniform1f = 0;
PFNGLPROGRAMUNIFORM1FVPROC			pglProgramUniform1fv = 0;
PFNGLPROGRAMUNIFORM1DPROC			pglProgramUniform1d = 0;
PFNGLPROGRAMUNIFORM1DVPROC			pglProgramUniform1dv = 0;
PFNGLPROGRAMUNIFORM1UIPROC			pglProgramUniform1ui = 0;
PFNGLPROGRAMUNIFORM1UIVPROC			pglProgramUniform1uiv = 0;
PFNGLPROGRAMUNIFORM2IPROC			pglProgramUniform2i = 0;
PFNGLPROGRAMUNIFORM2IVPROC			pglProgramUniform2iv = 0;
PFNGLPROGRAMUNIFORM2FPROC			pglProgramUniform2f = 0;
PFNGLPROGRAMUNIFORM2FVPROC			pglProgramUniform2fv = 0;
PFNGLPROGRAMUNIFORM2DPROC			pglProgramUniform2d = 0;
PFNGLPROGRAMUNIFORM2DVPROC			pglProgramUniform2dv = 0;
PFNGLPROGRAMUNIFORM2UIPROC			pglProgramUniform2ui = 0;
PFNGLPROGRAMUNIFORM2UIVPROC			pglProgramUniform2uiv = 0;
PFNGLPROGRAMUNIFORM3IPROC			pglProgramUniform3i = 0;
PFNGLPROGRAMUNIFORM3IVPROC			pglProgramUniform3iv = 0;
PFNGLPROGRAMUNIFORM3FPROC			pglProgramUniform3f = 0;
PFNGLPROGRAMUNIFORM3FVPROC			pglProgramUniform3fv = 0;
PFNGLPROGRAMUNIFORM3DPROC			pglProgramUniform3d = 0;
PFNGLPROGRAMUNIFORM3DVPROC			pglProgramUniform3dv = 0;
PFNGLPROGRAMUNIFORM3UIPROC			pglProgramUniform3ui = 0;
PFNGLPROGRAMUNIFORM3UIVPROC			pglProgramUniform3uiv = 0;
PFNGLPROGRAMUNIFORM4IPROC			pglProgramUniform4i = 0;
PFNGLPROGRAMUNIFORM4IVPROC			pglProgramUniform4iv = 0;
PFNGLPROGRAMUNIFORM4FPROC			pglProgramUniform4f = 0;
PFNGLPROGRAMUNIFORM4FVPROC			pglProgramUniform4fv = 0;
PFNGLPROGRAMUNIFORM4DPROC			pglProgramUniform4d = 0;
PFNGLPROGRAMUNIFORM4DVPROC			pglProgramUniform4dv = 0;
PFNGLPROGRAMUNIFORM4UIPROC			pglProgramUniform4ui = 0;
PFNGLPROGRAMUNIFORM4UIVPROC			pglProgramUniform4uiv = 0;
PFNGLPROGRAMUNIFORMMATRIX2FVPROC		pglProgramUniformMatrix2fv = 0;
PFNGLPROGRAMUNIFORMMATRIX3FVPROC		pglProgramUniformMatrix3fv = 0;
PFNGLPROGRAMUNIFORMMATRIX4FVPROC		pglProgramUniformMatrix4fv = 0;
PFNGLPROGRAMUNIFORMMATRIX2DVPROC		pglProgramUniformMatrix2dv = 0;
PFNGLPROGRAMUNIFORMMATRIX3DVPROC		pglProgramUniformMatrix3dv = 0;
PFNGLPROGRAMUNIFORMMATRIX4DVPROC		pglProgramUniformMatrix4dv = 0;
PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC	pglProgramUniformMatrix2x3fv = 0;
PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC	pglProgramUniformMatrix3x2fv = 0;
PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC	pglProgramUniformMatrix2x4fv = 0;
PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC	pglProgramUniformMatrix4x2fv = 0;
PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC	pglProgramUniformMatrix3x4fv = 0;
PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC	pglProgramUniformMatrix4x3fv = 0;
PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC	pglProgramUniformMatrix2x3dv = 0;
PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC	pglProgramUniformMatrix3x2dv = 0;
PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC	pglProgramUniformMatrix2x4dv = 0;
PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC	pglProgramUniformMatrix4x2dv = 0;
PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC	pglProgramUniformMatrix3x4dv = 0;
PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC	pglProgramUniformMatrix4x3dv = 0;
PFNGLVALIDATEPROGRAMPIPELINEPROC		pglValidateProgramPipeline = 0;
PFNGLGETPROGRAMPIPELINEINFOLOGPROC	pglGetProgramPipelineInfoLog = 0;	
PFNGLVERTEXATTRIBL1DPROC				pglVertexAttribL1d = 0;
PFNGLVERTEXATTRIBL2DPROC				pglVertexAttribL2d = 0;
PFNGLVERTEXATTRIBL3DPROC				pglVertexAttribL3d = 0;
PFNGLVERTEXATTRIBL4DPROC				pglVertexAttribL4d = 0;
PFNGLVERTEXATTRIBL1DVPROC			pglVertexAttribL1dv = 0;
PFNGLVERTEXATTRIBL2DVPROC			pglVertexAttribL2dv = 0;
PFNGLVERTEXATTRIBL3DVPROC			pglVertexAttribL3dv = 0;
PFNGLVERTEXATTRIBL4DVPROC			pglVertexAttribL4dv = 0;
PFNGLVERTEXATTRIBLPOINTERPROC		pglVertexAttribLPointer = 0;
PFNGLGETVERTEXATTRIBLDVPROC			pglGetVertexAttribLdv = 0;
PFNGLVIEWPORTARRAYVPROC				pglViewportArrayv = 0;
PFNGLVIEWPORTINDEXEDFPROC			pglViewportIndexedf = 0;
PFNGLVIEWPORTINDEXEDFVPROC			pglViewportIndexedfv = 0;
PFNGLSCISSORARRAYVPROC				pglScissorArrayv = 0;
PFNGLSCISSORINDEXEDPROC				pglScissorIndexed = 0;
PFNGLSCISSORINDEXEDVPROC				pglScissorIndexedv = 0;
PFNGLDEPTHRANGEARRAYVPROC			pglDepthRangeArrayv = 0;
PFNGLDEPTHRANGEINDEXEDPROC			pglDepthRangeIndexed = 0;
PFNGLGETFLOATI_VPROC					pglGetFloati_v = 0;
PFNGLGETDOUBLEI_VPROC				pglGetDoublei_v = 0;

int GL_4_1_LoadFuncPointers()
{
	glReleaseShaderCompiler = (PFNGLRELEASESHADERCOMPILERPROC)wglGetProcAddress("glReleaseShaderCompiler");
	glShaderBinary = (PFNGLSHADERBINARYPROC)wglGetProcAddress("glShaderBinary");
	glGetShaderPrecisionFormat= (PFNGLGETSHADERPRECISIONFORMATPROC)wglGetProcAddress("glGetShaderPrecisionFormat");
	glDepthRangef = (PFNGLDEPTHRANGEFPROC)wglGetProcAddress("glDepthRangef");
	glClearDepthf = (PFNGLCLEARDEPTHFPROC)wglGetProcAddress("glClearDepthf");
	glGetProgramBinary = (PFNGLGETPROGRAMBINARYPROC)wglGetProcAddress("glGetProgramBinary");
	glProgramBinary = (PFNGLPROGRAMBINARYPROC)wglGetProcAddress("glProgramBinary");
	glProgramParameteri = (PFNGLPROGRAMPARAMETERIPROC)wglGetProcAddress("glProgramParameteri");
	glUseProgramStages = (PFNGLUSEPROGRAMSTAGESPROC)wglGetProcAddress("glUseProgramStages");
	glActiveShaderProgram = (PFNGLACTIVESHADERPROGRAMPROC)wglGetProcAddress("glActiveShaderProgram");
	glCreateShaderProgramv = (PFNGLCREATESHADERPROGRAMVPROC)wglGetProcAddress("glCreateShaderProgramv");
	glBindProgramPipeline = (PFNGLBINDPROGRAMPIPELINEPROC)wglGetProcAddress("glBindProgramPipeline");
	glDeleteProgramPipelines = (PFNGLDELETEPROGRAMPIPELINESPROC)wglGetProcAddress("glDeleteProgramPipelines");
	glGenProgramPipelines = (PFNGLGENPROGRAMPIPELINESPROC)wglGetProcAddress("glGenProgramPipelines");
	glIsProgramPipeline = (PFNGLISPROGRAMPIPELINEPROC)wglGetProcAddress("glIsProgramPipeline");
	glGetProgramPipelineiv = (PFNGLGETPROGRAMPIPELINEIVPROC)wglGetProcAddress("glGetProgramPipelineiv");
	glProgramUniform1i = (PFNGLPROGRAMUNIFORM1IPROC)wglGetProcAddress("glProgramUniform1i");
	glProgramUniform1iv = (PFNGLPROGRAMUNIFORM1IVPROC)wglGetProcAddress("glProgramUniform1iv");
	glProgramUniform1f = (PFNGLPROGRAMUNIFORM1FPROC)wglGetProcAddress("glProgramUniform1f");
	glProgramUniform1fv = (PFNGLPROGRAMUNIFORM1FVPROC)wglGetProcAddress("glProgramUniform1fv");
	glProgramUniform1d = (PFNGLPROGRAMUNIFORM1DPROC)wglGetProcAddress("glProgramUniform1d");
	glProgramUniform1dv = (PFNGLPROGRAMUNIFORM1DVPROC)wglGetProcAddress("glProgramUniform1dv");
	glProgramUniform1ui = (PFNGLPROGRAMUNIFORM1UIPROC)wglGetProcAddress("glProgramUniform1ui");
	glProgramUniform1uiv = (PFNGLPROGRAMUNIFORM1UIVPROC)wglGetProcAddress("glProgramUniform1uiv");
	glProgramUniform2i = (PFNGLPROGRAMUNIFORM2IPROC)wglGetProcAddress("glProgramUniform2i");
	glProgramUniform2iv = (PFNGLPROGRAMUNIFORM2IVPROC)wglGetProcAddress("glProgramUniform2iv");
	glProgramUniform2f = (PFNGLPROGRAMUNIFORM2FPROC)wglGetProcAddress("glProgramUniform2f");
	glProgramUniform2fv = (PFNGLPROGRAMUNIFORM2FVPROC)wglGetProcAddress("glProgramUniform2fv");
	glProgramUniform2d = (PFNGLPROGRAMUNIFORM2DPROC)wglGetProcAddress("glProgramUniform2d");
	glProgramUniform2dv = (PFNGLPROGRAMUNIFORM2DVPROC)wglGetProcAddress("glProgramUniform2dv");
	glProgramUniform2ui = (PFNGLPROGRAMUNIFORM2UIPROC)wglGetProcAddress("glProgramUniform2ui");
	glProgramUniform2uiv = (PFNGLPROGRAMUNIFORM2UIVPROC)wglGetProcAddress("glProgramUniform2uiv");
	glProgramUniform3i = (PFNGLPROGRAMUNIFORM3IPROC)wglGetProcAddress("glProgramUniform3i");
	glProgramUniform3iv = (PFNGLPROGRAMUNIFORM3IVPROC)wglGetProcAddress("glProgramUniform3iv");
	glProgramUniform3f = (PFNGLPROGRAMUNIFORM3FPROC)wglGetProcAddress("glProgramUniform3f");
	glProgramUniform3fv = (PFNGLPROGRAMUNIFORM3FVPROC)wglGetProcAddress("glProgramUniform3fv");
	glProgramUniform3d = (PFNGLPROGRAMUNIFORM3DPROC)wglGetProcAddress("glProgramUniform3d");
	glProgramUniform3dv = (PFNGLPROGRAMUNIFORM3DVPROC)wglGetProcAddress("glProgramUniform3dv");
	glProgramUniform3ui = (PFNGLPROGRAMUNIFORM3UIPROC)wglGetProcAddress("glProgramUniform3ui");
	glProgramUniform3uiv = (PFNGLPROGRAMUNIFORM3UIVPROC)wglGetProcAddress("glProgramUniform3uiv");
	glProgramUniform4i = (PFNGLPROGRAMUNIFORM4IPROC)wglGetProcAddress("glProgramUniform4i");
	glProgramUniform4iv = (PFNGLPROGRAMUNIFORM4IVPROC)wglGetProcAddress("glProgramUniform4iv");
	glProgramUniform4f = (PFNGLPROGRAMUNIFORM4FPROC)wglGetProcAddress("glProgramUniform4f");
	glProgramUniform4fv = (PFNGLPROGRAMUNIFORM4FVPROC)wglGetProcAddress("glProgramUniform4fv");
	glProgramUniform4d = (PFNGLPROGRAMUNIFORM4DPROC)wglGetProcAddress("glProgramUniform4d");
	glProgramUniform4dv = (PFNGLPROGRAMUNIFORM4DVPROC)wglGetProcAddress("glProgramUniform4dv");
	glProgramUniform4ui = (PFNGLPROGRAMUNIFORM4UIPROC)wglGetProcAddress("glProgramUniform4ui");
	glProgramUniform4uiv = (PFNGLPROGRAMUNIFORM4UIVPROC)wglGetProcAddress("glProgramUniform4uiv");
	glProgramUniformMatrix2fv = (PFNGLPROGRAMUNIFORMMATRIX2FVPROC)wglGetProcAddress("glProgramUniformMatrix2fv");
	glProgramUniformMatrix3fv = (PFNGLPROGRAMUNIFORMMATRIX3FVPROC)wglGetProcAddress("glProgramUniformMatrix3fv");
	glProgramUniformMatrix4fv = (PFNGLPROGRAMUNIFORMMATRIX4FVPROC)wglGetProcAddress("glProgramUniformMatrix4fv");
	glProgramUniformMatrix2dv = (PFNGLPROGRAMUNIFORMMATRIX2DVPROC)wglGetProcAddress("glProgramUniformMatrix2dv");
	glProgramUniformMatrix3dv = (PFNGLPROGRAMUNIFORMMATRIX3DVPROC)wglGetProcAddress("glProgramUniformMatrix3dv");
	glProgramUniformMatrix4dv = (PFNGLPROGRAMUNIFORMMATRIX4DVPROC)wglGetProcAddress("glProgramUniformMatrix4dv");
	glProgramUniformMatrix2x3fv = (PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC)wglGetProcAddress("glProgramUniformMatrix2x3fv");
	glProgramUniformMatrix3x2fv = (PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC)wglGetProcAddress("glProgramUniformMatrix3x2fv");
	glProgramUniformMatrix2x4fv = (PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC)wglGetProcAddress("glProgramUniformMatrix2x4fv");
	glProgramUniformMatrix4x2fv = (PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC)wglGetProcAddress("glProgramUniformMatrix4x2fv");
	glProgramUniformMatrix3x4fv = (PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC)wglGetProcAddress("glProgramUniformMatrix3x4fv");
	glProgramUniformMatrix4x3fv = (PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC)wglGetProcAddress("glProgramUniformMatrix4x3fv");
	glProgramUniformMatrix2x3dv = (PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC)wglGetProcAddress("glProgramUniformMatrix2x3dv");
	glProgramUniformMatrix3x2dv = (PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC)wglGetProcAddress("glProgramUniformMatrix3x2dv");
	glProgramUniformMatrix2x4dv = (PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC)wglGetProcAddress("glProgramUniformMatrix2x4dv");
	glProgramUniformMatrix4x2dv = (PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC)wglGetProcAddress("glProgramUniformMatrix4x2dv");
	glProgramUniformMatrix3x4dv = (PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC)wglGetProcAddress("glProgramUniformMatrix3x4dv");
	glProgramUniformMatrix4x3dv = (PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC)wglGetProcAddress("glProgramUniformMatrix4x3dv");
	glValidateProgramPipeline = (PFNGLVALIDATEPROGRAMPIPELINEPROC)wglGetProcAddress("glValidateProgramPipeline");
	glGetProgramPipelineInfoLog = (PFNGLGETPROGRAMPIPELINEINFOLOGPROC)wglGetProcAddress("glGetProgramPipelineInfoLog");
	glVertexAttribL1d = (PFNGLVERTEXATTRIBL1DPROC)wglGetProcAddress("glVertexAttribL1d");
	glVertexAttribL2d = (PFNGLVERTEXATTRIBL2DPROC)wglGetProcAddress("glVertexAttribL2d");
	glVertexAttribL3d = (PFNGLVERTEXATTRIBL3DPROC)wglGetProcAddress("glVertexAttribL3d");
	glVertexAttribL4d = (PFNGLVERTEXATTRIBL4DPROC)wglGetProcAddress("glVertexAttribL4d");
	glVertexAttribL1dv = (PFNGLVERTEXATTRIBL1DVPROC)wglGetProcAddress("glVertexAttribL1dv");
	glVertexAttribL2dv = (PFNGLVERTEXATTRIBL2DVPROC)wglGetProcAddress("glVertexAttribL2dv");
	glVertexAttribL3dv = (PFNGLVERTEXATTRIBL3DVPROC)wglGetProcAddress("glVertexAttribL3dv");
	glVertexAttribL4dv = (PFNGLVERTEXATTRIBL4DVPROC)wglGetProcAddress("glVertexAttribL4dv");
	glVertexAttribLPointer = (PFNGLVERTEXATTRIBLPOINTERPROC)wglGetProcAddress("glVertexAttribLPointer");
	glGetVertexAttribLdv = (PFNGLGETVERTEXATTRIBLDVPROC)wglGetProcAddress("glGetVertexAttribLdv");
	glViewportArrayv = (PFNGLVIEWPORTARRAYVPROC)wglGetProcAddress("glViewportArrayv");
	glViewportIndexedf = (PFNGLVIEWPORTINDEXEDFPROC)wglGetProcAddress("glViewportIndexedf");
	glViewportIndexedfv = (PFNGLVIEWPORTINDEXEDFVPROC)wglGetProcAddress("glViewportIndexedfv");
	glScissorArrayv = (PFNGLSCISSORARRAYVPROC)wglGetProcAddress("glScissorArrayv");
	glScissorIndexed = (PFNGLSCISSORINDEXEDPROC)wglGetProcAddress("glScissorIndexed");
	glScissorIndexedv = (PFNGLSCISSORINDEXEDVPROC)wglGetProcAddress("glScissorIndexedv");
	glDepthRangeArrayv = (PFNGLDEPTHRANGEARRAYVPROC)wglGetProcAddress("glDepthRangeArrayv");
	glDepthRangeIndexed = (PFNGLDEPTHRANGEINDEXEDPROC)wglGetProcAddress("glDepthRangeIndexed");
	glGetFloati_v = (PFNGLGETFLOATI_VPROC)wglGetProcAddress("glGetFloati_v");
	glGetDoublei_v = (PFNGLGETDOUBLEI_VPROC)wglGetProcAddress("glGetDoublei_v");

	return (glReleaseShaderCompiler && glShaderBinary && glGetShaderPrecisionFormat && glDepthRangef && glClearDepthf && 
		glGetProgramBinary && glProgramBinary && glProgramParameteri && glUseProgramStages && glActiveShaderProgram && 
		glCreateShaderProgramv && glBindProgramPipeline && glDeleteProgramPipelines && glGenProgramPipelines && 
		glIsProgramPipeline && glGetProgramPipelineiv && glProgramUniform1i && glProgramUniform1iv && glProgramUniform1f && 
		glProgramUniform1fv && glProgramUniform1d && glProgramUniform1dv && glProgramUniform1ui && glProgramUniform1uiv && 
		glProgramUniform2i && glProgramUniform2iv && glProgramUniform2f && glProgramUniform2fv && glProgramUniform2d && 
		glProgramUniform2dv && glProgramUniform2ui && glProgramUniform2uiv && glProgramUniform3i && glProgramUniform3iv && 
		glProgramUniform3f && glProgramUniform3fv && glProgramUniform3d && glProgramUniform3dv && glProgramUniform3ui && 
		glProgramUniform3uiv && glProgramUniform4i && glProgramUniform4iv && glProgramUniform4f && glProgramUniform4fv && 
		glProgramUniform4d && glProgramUniform4dv && glProgramUniform4ui && glProgramUniform4uiv && glProgramUniformMatrix2fv && 
		glProgramUniformMatrix3fv && glProgramUniformMatrix4fv && glProgramUniformMatrix2dv && glProgramUniformMatrix3dv && 
		glProgramUniformMatrix4dv && glProgramUniformMatrix2x3fv && glProgramUniformMatrix3x2fv && glProgramUniformMatrix2x4fv && 
		glProgramUniformMatrix4x2fv && glProgramUniformMatrix3x4fv && glProgramUniformMatrix4x3fv && glProgramUniformMatrix2x3dv && 
		glProgramUniformMatrix3x2dv && glProgramUniformMatrix2x4dv && glProgramUniformMatrix4x2dv && glProgramUniformMatrix3x4dv && 
		glProgramUniformMatrix4x3dv && glValidateProgramPipeline && glGetProgramPipelineInfoLog && glVertexAttribL1d && 
		glVertexAttribL2d && glVertexAttribL3d && glVertexAttribL4d && glVertexAttribL1dv && glVertexAttribL2dv && glVertexAttribL3dv && 
		glVertexAttribL4dv && glVertexAttribLPointer && glGetVertexAttribLdv && glViewportArrayv && glViewportIndexedf && 
		glViewportIndexedfv && glScissorArrayv && glScissorIndexed && glScissorIndexedv && glDepthRangeArrayv && glDepthRangeIndexed && 
		glGetFloati_v && glGetDoublei_v) ? 1 : 0;
}

/////////////////////////////// GL_VERSION_4_2 ////////////////////////////////

PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC					pglDrawArraysInstancedBaseInstance = 0;
PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC				pglDrawElementsInstancedBaseInstance = 0;
PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC		pglDrawElementsInstancedBaseVertexBaseInstance = 0;
PFNGLGETINTERNALFORMATIVPROC								pglGetInternalformativ = 0;
PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC					pglGetActiveAtomicCounterBufferiv = 0;
PFNGLBINDIMAGETEXTUREPROC								pglBindImageTexture = 0;
PFNGLMEMORYBARRIERPROC									pglMemoryBarrier = 0;
PFNGLTEXSTORAGE1DPROC									pglTexStorage1D = 0;
PFNGLTEXSTORAGE2DPROC									pglTexStorage2D = 0;
PFNGLTEXSTORAGE3DPROC									pglTexStorage3D = 0;
PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC					pglDrawTransformFeedbackInstanced = 0;
PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC			pglDrawTransformFeedbackStreamInstanced = 0;

int GL_4_2_LoadFuncPointers()
{
	glDrawArraysInstancedBaseInstance = (PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC)wglGetProcAddress("glDrawArraysInstancedBaseInstance");
	glDrawElementsInstancedBaseInstance = (PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC)wglGetProcAddress("glDrawElementsInstancedBaseInstance");
	glDrawElementsInstancedBaseVertexBaseInstance = (PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC)wglGetProcAddress("glDrawElementsInstancedBaseVertexBaseInstance");
	glGetInternalformativ = (PFNGLGETINTERNALFORMATIVPROC)wglGetProcAddress("glGetInternalformativ");
	glGetActiveAtomicCounterBufferiv = (PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC)wglGetProcAddress("glGetActiveAtomicCounterBufferiv");
	glBindImageTexture = (PFNGLBINDIMAGETEXTUREPROC)wglGetProcAddress("glBindImageTexture");
	glMemoryBarrier = (PFNGLMEMORYBARRIERPROC)wglGetProcAddress("glMemoryBarrier");
	glTexStorage1D = (PFNGLTEXSTORAGE1DPROC)wglGetProcAddress("glTexStorage1D");
	glTexStorage2D = (PFNGLTEXSTORAGE2DPROC)wglGetProcAddress("glTexStorage2D");
	glTexStorage3D = (PFNGLTEXSTORAGE3DPROC)wglGetProcAddress("glTexStorage3D");
	glDrawTransformFeedbackInstanced = (PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC)wglGetProcAddress("glDrawTransformFeedbackInstanced");
	glDrawTransformFeedbackStreamInstanced = (PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC)wglGetProcAddress("glDrawTransformFeedbackStreamInstanced");

	return (glDrawArraysInstancedBaseInstance && glDrawElementsInstancedBaseInstance && glDrawElementsInstancedBaseVertexBaseInstance && 
		glGetInternalformativ && glGetActiveAtomicCounterBufferiv && glBindImageTexture && glMemoryBarrier && glTexStorage1D && 
		glTexStorage2D && glTexStorage3D && glDrawTransformFeedbackInstanced && glDrawTransformFeedbackStreamInstanced) ? 1 : 0;
}


/////////////////////////////// GL_VERSION_4_3 ////////////////////////////////

PFNGLCLEARBUFFERDATAPROC					pglClearBufferData = 0;
PFNGLCLEARBUFFERSUBDATAPROC					pglClearBufferSubData = 0;
PFNGLDISPATCHCOMPUTEPROC					pglDispatchCompute = 0;
PFNGLDISPATCHCOMPUTEINDIRECTPROC			pglDispatchComputeIndirect = 0;
PFNGLCOPYIMAGESUBDATAPROC					pglCopyImageSubData = 0;
PFNGLFRAMEBUFFERPARAMETERIPROC				pglFramebufferParameteri = 0;
PFNGLGETFRAMEBUFFERPARAMETERIVPROC			pglGetFramebufferParameteriv = 0;
PFNGLGETINTERNALFORMATI64VPROC				pglGetInternalformati64v = 0;
PFNGLINVALIDATETEXSUBIMAGEPROC				pglInvalidateTexSubImage = 0;
PFNGLINVALIDATETEXIMAGEPROC					pglInvalidateTexImage = 0;
PFNGLINVALIDATEBUFFERSUBDATAPROC			pglInvalidateBufferSubData = 0;
PFNGLINVALIDATEBUFFERDATAPROC				pglInvalidateBufferData = 0;
PFNGLINVALIDATEFRAMEBUFFERPROC				pglInvalidateFramebuffer = 0;
PFNGLINVALIDATESUBFRAMEBUFFERPROC			pglInvalidateSubFramebuffer = 0;
PFNGLMULTIDRAWARRAYSINDIRECTPROC			pglMultiDrawArraysIndirect = 0;
PFNGLMULTIDRAWELEMENTSINDIRECTPROC			pglMultiDrawElementsIndirect = 0;
PFNGLGETPROGRAMINTERFACEIVPROC				pglGetProgramInterfaceiv = 0;
PFNGLGETPROGRAMRESOURCEINDEXPROC			pglGetProgramResourceIndex = 0;
PFNGLGETPROGRAMRESOURCENAMEPROC				pglGetProgramResourceName = 0;
PFNGLGETPROGRAMRESOURCEIVPROC				pglGetProgramResourceiv = 0;
PFNGLGETPROGRAMRESOURCELOCATIONPROC			pglGetProgramResourceLocation = 0;
PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC	pglGetProgramResourceLocationIndex = 0;
PFNGLSHADERSTORAGEBLOCKBINDINGPROC			pglShaderStorageBlockBinding = 0;
PFNGLTEXBUFFERRANGEPROC						pglTexBufferRange = 0;
PFNGLTEXSTORAGE2DMULTISAMPLEPROC			pglTexStorage2DMultisample = 0;
PFNGLTEXSTORAGE3DMULTISAMPLEPROC			pglTexStorage3DMultisample = 0;
PFNGLTEXTUREVIEWPROC						pglTextureView = 0;
PFNGLBINDVERTEXBUFFERPROC					pglBindVertexBuffer = 0;
PFNGLVERTEXATTRIBFORMATPROC					pglVertexAttribFormat = 0;
PFNGLVERTEXATTRIBIFORMATPROC				pglVertexAttribIFormat = 0;
PFNGLVERTEXATTRIBLFORMATPROC				pglVertexAttribLFormat = 0;
PFNGLVERTEXATTRIBBINDINGPROC				pglVertexAttribBinding = 0;
PFNGLVERTEXBINDINGDIVISORPROC				pglVertexBindingDivisor = 0;
PFNGLDEBUGMESSAGECONTROLPROC				pglDebugMessageControl = 0;
PFNGLDEBUGMESSAGEINSERTPROC					pglDebugMessageInsert = 0;
PFNGLDEBUGMESSAGECALLBACKPROC				pglDebugMessageCallback = 0;
PFNGLGETDEBUGMESSAGELOGPROC					pglGetDebugMessageLog = 0;
PFNGLPUSHDEBUGGROUPPROC						pglPushDebugGroup = 0;
PFNGLPOPDEBUGGROUPPROC						pglPopDebugGroup = 0;
PFNGLOBJECTLABELPROC						pglObjectLabel = 0;
PFNGLGETOBJECTLABELPROC						pglGetObjectLabel = 0;
PFNGLOBJECTPTRLABELPROC						pglObjectPtrLabel = 0;
PFNGLGETOBJECTPTRLABELPROC					pglGetObjectPtrLabel = 0;

int GL_4_3_LoadFuncPointers()
{
	glClearBufferData = (PFNGLCLEARBUFFERDATAPROC)wglGetProcAddress("glClearBufferData");
	glClearBufferSubData = (PFNGLCLEARBUFFERSUBDATAPROC)wglGetProcAddress("glClearBufferSubData");
	glDispatchCompute = (PFNGLDISPATCHCOMPUTEPROC)wglGetProcAddress("glDispatchCompute");
	glDispatchComputeIndirect = (PFNGLDISPATCHCOMPUTEINDIRECTPROC)wglGetProcAddress("glDispatchComputeIndirect");
	glCopyImageSubData = (PFNGLCOPYIMAGESUBDATAPROC)wglGetProcAddress("glCopyImageSubData");
	glFramebufferParameteri = (PFNGLFRAMEBUFFERPARAMETERIPROC)wglGetProcAddress("glFramebufferParameteri");
	glGetFramebufferParameteriv = (PFNGLGETFRAMEBUFFERPARAMETERIVPROC)wglGetProcAddress("glGetFramebufferParameteriv");
	glGetInternalformati64v = (PFNGLGETINTERNALFORMATI64VPROC)wglGetProcAddress("glGetInternalformati64v");
	glInvalidateTexSubImage = (PFNGLINVALIDATETEXSUBIMAGEPROC)wglGetProcAddress("glInvalidateTexSubImage");
	glInvalidateTexImage = (PFNGLINVALIDATETEXIMAGEPROC)wglGetProcAddress("glInvalidateTexImage");
	glInvalidateBufferSubData = (PFNGLINVALIDATEBUFFERSUBDATAPROC)wglGetProcAddress("glInvalidateBufferSubData");
	glInvalidateBufferData = (PFNGLINVALIDATEBUFFERDATAPROC)wglGetProcAddress("glInvalidateBufferData");
	glInvalidateFramebuffer = (PFNGLINVALIDATEFRAMEBUFFERPROC)wglGetProcAddress("glInvalidateFramebuffer");
	glInvalidateSubFramebuffer = (PFNGLINVALIDATESUBFRAMEBUFFERPROC)wglGetProcAddress("glInvalidateSubFramebuffer");
	glMultiDrawArraysIndirect = (PFNGLMULTIDRAWARRAYSINDIRECTPROC)wglGetProcAddress("glMultiDrawArraysIndirect");
	glMultiDrawElementsIndirect = (PFNGLMULTIDRAWELEMENTSINDIRECTPROC)wglGetProcAddress("glMultiDrawElementsIndirect");
	glGetProgramInterfaceiv = (PFNGLGETPROGRAMINTERFACEIVPROC)wglGetProcAddress("glGetProgramInterfaceiv");
	glGetProgramResourceIndex = (PFNGLGETPROGRAMRESOURCEINDEXPROC)wglGetProcAddress("glGetProgramResourceIndex");
	glGetProgramResourceName = (PFNGLGETPROGRAMRESOURCENAMEPROC)wglGetProcAddress("glGetProgramResourceName");
	glGetProgramResourceiv = (PFNGLGETPROGRAMRESOURCEIVPROC)wglGetProcAddress("glGetProgramResourceiv");
	glGetProgramResourceLocation = (PFNGLGETPROGRAMRESOURCELOCATIONPROC)wglGetProcAddress("glGetProgramResourceLocation");
	glGetProgramResourceLocationIndex = (PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC)wglGetProcAddress("glGetProgramResourceLocationIndex");
	glShaderStorageBlockBinding = (PFNGLSHADERSTORAGEBLOCKBINDINGPROC)wglGetProcAddress("glShaderStorageBlockBinding");
	glTexBufferRange = (PFNGLTEXBUFFERRANGEPROC)wglGetProcAddress("glTexBufferRange");
	glTexStorage2DMultisample = (PFNGLTEXSTORAGE2DMULTISAMPLEPROC)wglGetProcAddress("glTexStorage2DMultisample");
	glTexStorage3DMultisample = (PFNGLTEXSTORAGE3DMULTISAMPLEPROC)wglGetProcAddress("glTexStorage3DMultisample");
	glTextureView = (PFNGLTEXTUREVIEWPROC)wglGetProcAddress("glTextureView");
	glBindVertexBuffer = (PFNGLBINDVERTEXBUFFERPROC)wglGetProcAddress("glBindVertexBuffer");
	glVertexAttribFormat = (PFNGLVERTEXATTRIBFORMATPROC)wglGetProcAddress("glVertexAttribFormat");
	glVertexAttribIFormat = (PFNGLVERTEXATTRIBIFORMATPROC)wglGetProcAddress("glVertexAttribIFormat");
	glVertexAttribLFormat = (PFNGLVERTEXATTRIBLFORMATPROC)wglGetProcAddress("glVertexAttribLFormat");
	glVertexAttribBinding = (PFNGLVERTEXATTRIBBINDINGPROC)wglGetProcAddress("glVertexAttribBinding");
	glVertexBindingDivisor = (PFNGLVERTEXBINDINGDIVISORPROC)wglGetProcAddress("glVertexBindingDivisor");
	glDebugMessageControl = (PFNGLDEBUGMESSAGECONTROLPROC)wglGetProcAddress("glDebugMessageControl");
	glDebugMessageInsert = (PFNGLDEBUGMESSAGEINSERTPROC)wglGetProcAddress("glDebugMessageInsert");
	glDebugMessageCallback = (PFNGLDEBUGMESSAGECALLBACKPROC)wglGetProcAddress("glDebugMessageCallback");
	glGetDebugMessageLog = (PFNGLGETDEBUGMESSAGELOGPROC)wglGetProcAddress("glGetDebugMessageLog");
	glPushDebugGroup = (PFNGLPUSHDEBUGGROUPPROC)wglGetProcAddress("glPushDebugGroup");
	glPopDebugGroup = (PFNGLPOPDEBUGGROUPPROC)wglGetProcAddress("glPopDebugGroup");
	glObjectLabel = (PFNGLOBJECTLABELPROC)wglGetProcAddress("glObjectLabel");
	glGetObjectLabel = (PFNGLGETOBJECTLABELPROC)wglGetProcAddress("glGetObjectLabel");
	glObjectPtrLabel = (PFNGLOBJECTPTRLABELPROC)wglGetProcAddress("glObjectPtrLabel");
	glGetObjectPtrLabel = (PFNGLGETOBJECTPTRLABELPROC)wglGetProcAddress("glGetObjectPtrLabel");

	return (glClearBufferData && glClearBufferSubData && glDispatchCompute && glDispatchComputeIndirect && glCopyImageSubData && 
		glFramebufferParameteri && glGetFramebufferParameteriv && glGetInternalformati64v && glInvalidateTexSubImage && glInvalidateTexImage && 
		glInvalidateBufferSubData && glInvalidateBufferData && glInvalidateFramebuffer && glInvalidateSubFramebuffer && glMultiDrawArraysIndirect && 
		glMultiDrawElementsIndirect && glGetProgramInterfaceiv && glGetProgramResourceIndex && glGetProgramResourceName && glGetProgramResourceiv && 
		glGetProgramResourceLocation && glGetProgramResourceLocationIndex && glShaderStorageBlockBinding && glTexBufferRange && 
		glTexStorage2DMultisample && glTexStorage3DMultisample && glTextureView && glBindVertexBuffer && glVertexAttribFormat &&
		glVertexAttribIFormat && glVertexAttribLFormat && glVertexAttribBinding && glVertexBindingDivisor && glDebugMessageControl && 
		glDebugMessageInsert && glDebugMessageCallback && glGetDebugMessageLog && glPushDebugGroup && glPopDebugGroup && glObjectLabel && 
		glGetObjectLabel && glObjectPtrLabel && glGetObjectPtrLabel) ? 1 : 0;
}
