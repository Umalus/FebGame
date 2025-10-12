#include "Matrix_4x4.h"

Matrix_4x4::Matrix_4x4()
    :matrix{}
{
}

Matrix_4x4::Matrix_4x4(std::array<float, 4> _x,
    std::array<float, 4> _y = {0.0f,0.0f,0.0f,0.0f}, 
    std::array<float, 4> _z = {0.0f,0.0f,0.0f,0.0f}, 
    std::array<float, 4> _w = {0.0f,0.0f,0.0f,0.0f})
{
    for (int i = 0; i < 4; i++) {
        matrix[i][0] = _x[i];
        matrix[i][1] = _y[i];
        matrix[i][2] = _z[i];
        matrix[i][3] = _w[i];

    }
}

Matrix_4x4::~Matrix_4x4()
{
}

Matrix_4x4 Matrix_4x4::Identity()
{
    std::array<float, 4> x = { 1.0f,0.0f,0.0f,0.0f };
    std::array<float, 4> y = { 0.0f,1.0f,0.0f,0.0f };
    std::array<float, 4> z = { 0.0f,0.0f,1.0f,0.0f };
    std::array<float, 4> w = { 0.0f,0.0f,0.0f,1.0f };

    return Matrix_4x4(x,y,z,w);
}

Matrix_4x4 Matrix_4x4::Transpose()
{
    Matrix_4x4 result;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            result.matrix[i][j] = matrix[j][i];
        }
    }
    return result;
}

Matrix_4x4 Matrix_4x4::Inverse()
{
    Matrix_4x4 result;

    return result;
}

Matrix_4x4 Matrix_4x4::Multiply(const Matrix_4x4& _other)
{
    return Matrix_4x4();
}
