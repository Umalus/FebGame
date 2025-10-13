#include "Matrix_3x3.h"

Matrix_3x3::Matrix_3x3()
    :matrix{}
{
}

Matrix_3x3::Matrix_3x3(
    std::array<float, 3> _x, 
    std::array<float, 3> _y = {0.0f,0.0f,0.0f},
    std::array<float, 3> _z = {0.0f,0.0f,0.0f})
{
    for (int i = 0; i < 3; i++) {
        matrix[i][0] = _x[i];
        matrix[i][1] = _y[i];
        matrix[i][2] = _z[i];

    }
}

Matrix_3x3::~Matrix_3x3()
{
}

float Matrix_3x3::Determinant() const
{
    //‚±‚Ì‹óŠÔ‚ª‚Ç‚ê‚¾‚¯‰Ÿ‚µL‚°‚Ä‚¢‚é‚©‚ðŠm”F‚·‚é
    //0->‹óŠÔ‚ª‚È‚¢(‹ts—ñ‚ª‘¶Ý‚µ‚È‚¢)
    //³->Œü‚«‚ð•Û‚Á‚½•ÏŠ·
    //•‰->Œü‚«‚ð”½“]‚µ‚½•ÏŠ·
    float result = 0.0f;
    result = (matrix[0][0] * matrix[1][1] * matrix[2][2])
        + (matrix[1][0] * matrix[2][1] * matrix[0][2])
        + (matrix[2][0] * matrix[0][1] * matrix[1][2])
        - (matrix[0][2] * matrix[1][1] * matrix[2][0])
        - (matrix[0][1] * matrix[1][0] * matrix[2][2])
        - (matrix[0][0] * matrix[1][2] * matrix[2][1]);
    return result;
}

Matrix_3x3 Matrix_3x3::Transpose() const
{
    Matrix_3x3 result;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result.matrix[i][j] = matrix[j][i];
        }
    }
    return result;
}
