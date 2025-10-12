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

Matrix_4x4 Matrix_4x4::Transpose() const
{
    Matrix_4x4 result;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            result.matrix[i][j] = matrix[j][i];
        }
    }
    return result;
}

Matrix_4x4 Matrix_4x4::Inverse()const
{
    //行列式が0の場合逆行列は存在しないので早期リターン
    float det = Determinant();
    if (det == 0)
        return Matrix_4x4();

    Matrix_4x4 result;
    Matrix_4x4 cofactor;
    Matrix_4x4 adjugate;
    //各成分に対して余因子展開をする
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cofactor.matrix[i][j] = MakeCofactor(i, j);
        }
    }
    //転置して随伴行列を作成
    adjugate = cofactor.Transpose();

   

    //元の行列を随伴行列で割って逆行列完成
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            result.matrix[i][j] = adjugate.matrix[i][j] / det;
        }
    }

    return result;
}

Matrix_4x4 Matrix_4x4::Multiply(const Matrix_4x4& _other)const
{
    //最終的に返す行列
    Matrix_4x4 result;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {

            result.matrix[i][j] = 0.0f;
            for (int k = 0; k < 4; k++) {
                result.matrix[i][j] += this->matrix[i][k] * _other.matrix[k][j];
            }
        }
    }

    return result;
}

Matrix_3x3 Matrix_4x4::PickupMiniQueue(int _row, int _column) const
{
    //小行列を返すために新しい3x3の行列を作る
    Matrix_3x3 result;
    int miniRow = 0;
    for (int i = 0; i < 4; i++) {
        if (i == _row)continue;
        int miniCol = 0;
        for (int j = 0; j < 4; j++) {
            if(j == _column)continue;
            result.matrix[miniRow][miniCol] = this->matrix[i][j];

            miniCol++;
        }
        miniRow++;
    }

    return result;
}

float Matrix_4x4::MakeCofactor(int _row, int _column)const
{
    //小行列を生成
    Matrix_3x3 copy = PickupMiniQueue(_row, _column);
    //余因子行列を作るために-1^(_row + _column)が必要なので三項演算子で正負を判定
    float sign = ((_row + _column) % 2 == 0) ? 1.0f : -1.0f;
    return sign * copy.Determinant();
    
}

float Matrix_4x4::Determinant()const {
    float result = 0.0f;
    for (int i = 0; i < 4; i++) {
        float sign = ((0 + i) % 2 == 0) ? 1.0f : -1.0f;
        Matrix_3x3 copy = PickupMiniQueue(0, i);
        result += sign * copy.Determinant();
    }

    return result;
}
