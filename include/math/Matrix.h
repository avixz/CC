//---------------------------------------------------------------------------
// Matrix.h
//---------------------------------------------------------------------------

#pragma once

namespace CC
{
  template <typename T>
    struct Matrix
    {
      Matrix(
          T a00, T a01, T a02, T a03,
          T a10, T a11, T a12, T a13,
          T a20, T a21, T a22, T a23,
          T a30, T a31, T a32, T a33)
      {
        m[0][0] = a00;
        m[0][1] = a01;
        m[0][2] = a02;
        m[0][3] = a03;
        m[1][0] = a10;
        m[1][1] = a11;
        m[1][2] = a12;
        m[1][3] = a13;
        m[2][0] = a20;
        m[2][1] = a21;
        m[2][2] = a22;
        m[2][3] = a23;
        m[3][0] = a30;
        m[3][1] = a31;
        m[3][2] = a32;
        m[3][3] = a33;
      }

      T m[4][4];
    };
}
