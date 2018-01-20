//---------------------------------------------------------------------------
// ShaderProgramGL.h
//---------------------------------------------------------------------------

#pragma once

#include <string>
#include "GL/glew.h"
#include "graphics/IShaderProgram.h"

namespace CC
{
  class ShaderProgramGL : public IShaderProgram
  {
    public:
      ShaderProgramGL(const std::string& vertexShaderFileName,
                      const std::string& fragmentShaderFileName);

      void Compile();
      void Link();
      void Validate();
      void Bind();
      void UnBind();

    private:
      std::string m_vertexShaderSource;
      std::string m_fragmentShaderSource;
      GLuint m_shaderProgram;
  };
}
