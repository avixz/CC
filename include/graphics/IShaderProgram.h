//---------------------------------------------------------------------------
// IShaderProgram.h
//---------------------------------------------------------------------------

#pragma once

namespace CC
{
  class IShaderProgram
  {
    public:
      virtual ~IShaderProgram() {};
      virtual void Compile() = 0;
      virtual void Link() = 0;
      virtual void Validate() = 0;
      virtual void Bind() = 0;
      virtual void UnBind() = 0;
  };
}
