//---------------------------------------------------------------------------
// GFXshaderProgram.h
//---------------------------------------------------------------------------

#pragma once

#include <list>
#include "GL/gl3.h"

namespace cc
{

struct IGLAPI;

class GFXshaderProgram
{
    public:
        GFXshaderProgram(IGLAPI* IGL3);
        void AddShader(GLenum shaderType, const char* fileName);
        void Compile();
        void Enable();

    private:
        typedef std::list<GLuint> ShaderObjList;
        ShaderObjList m_shaderObjList;
        GLuint m_program;
};

}
