#include "Matrix_4x4.h"

Matrix_4x4::Matrix_4x4(){
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            matrix[i][j] = Identity().matrix[i][j];
        }
    }

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

std::array<float, 16> Matrix_4x4::GetDataArray() const
{
    //配列に展開して返す
    std::array<float, 16> result;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            result[i * 4 + j] = matrix[j][i];
        }
    }

    return result;
}

Matrix_4x4 Matrix_4x4::FromTranslation(const Vector3& _pos)
{
    //単位行列を生成
    Matrix_4x4 result = Identity();
    //最下段に_posをそれぞれ代入
    result.matrix[0][3] = _pos.x;
    result.matrix[1][3] = _pos.y;
    result.matrix[2][3] = _pos.z;


    return result;
}

Matrix_4x4 Matrix_4x4::FromRotationEuler(const Vector3& _rota)
{
    //各軸の回転行列を個別に生成
    Matrix_4x4 yaw = FromRotationY(_rota.y);
    Matrix_4x4 pitch = FromRotationX(_rota.x);
    Matrix_4x4 roll = FromRotationZ(_rota.z);

    Matrix_4x4 rotationMatrix = roll.Multiply(pitch.Multiply(yaw));

    return rotationMatrix;
}

Matrix_4x4 Matrix_4x4::FromScale(const Vector3& _scale)
{
    //各軸のスケール値を対角成分に配置
    std::array<float, 4> x = { _scale.x, 0.0f, 0.0f, 0.0f };
    std::array<float, 4> y = { 0.0f,_scale.y,0.0f,0.0f };
    std::array<float, 4> z = { 0.0f, 0.0f, _scale.z, 0.0f };
    std::array<float, 4> w = { 0.0f, 0.0f, 0.0f, 1.0f };

    return Matrix_4x4(x,y,z,w);
}

Matrix_4x4 Matrix_4x4::FromRotationX(float _radX)
{
    //cosΘとsinΘを生成
    float cosTheta = cosf(Vector3::Radians(_radX));
    float sinTheta = sinf(Vector3::Radians(_radX));
    //各行を生成
    std::array<float, 4> x = { 1.0f, 0.0f, 0.0f, 0.0f};
    std::array<float, 4> y = { 0.0f,cosTheta,-sinTheta,0.0f };
    std::array<float, 4> z = { 0.0f, sinTheta, cosTheta, 0.0f };
    std::array<float, 4> w = { 0.0f, 0.0f, 0.0f, 1.0f };

    return Matrix_4x4(x,y,z,w);
}

Matrix_4x4 Matrix_4x4::FromRotationY(float _radY)
{
    //cosΘとsinΘを生成
    float cosTheta = cosf(Vector3::Radians(_radY));
    float sinTheta = sinf(Vector3::Radians(_radY));
    //各行を生成
    std::array<float, 4> x = { cosTheta, 0.0f, sinTheta, 0.0f };
    std::array<float, 4> y = { 0.0f, 1.0f, 0.0f, 0.0f };
    std::array<float, 4> z = { -sinTheta, 0.0f, cosTheta, 0.0f };
    std::array<float, 4> w = { 0.0f, 0.0f, 0.0f, 1.0f };

    return Matrix_4x4(x, y, z, w);
}

Matrix_4x4 Matrix_4x4::FromRotationZ(float _radZ)
{
    //cosΘとsinΘを生成
    float cosTheta = cosf(Vector3::Radians(_radZ));
    float sinTheta = sinf(Vector3::Radians(_radZ));
    //各行を生成
    std::array<float, 4> x = { cosTheta, -sinTheta, 0.0f, 0.0f };
    std::array<float, 4> y = { sinTheta,cosTheta,0.0f,0.0f };
    std::array<float, 4> z = { 0.0f, 0.0f, 1.0f, 0.0f };
    std::array<float, 4> w = { 0.0f, 0.0f, 0.0f, 1.0f };

    return Matrix_4x4(x, y, z, w);
}

Vector3 Matrix_4x4::operator*(const Vector3& _vec3)
{
    float w = 1.0f;
    float resultX = matrix[0][0] * _vec3.x + matrix[0][1] * _vec3.y + matrix[0][2] * _vec3.z + matrix[0][3] * w;
    float resultY = matrix[1][0] * _vec3.x + matrix[1][1] * _vec3.y + matrix[1][2] * _vec3.z + matrix[1][3] * w;
    float resultZ = matrix[2][0] * _vec3.x + matrix[2][1] * _vec3.y + matrix[2][2] * _vec3.z + matrix[2][3] * w;

    return Vector3(resultX,resultY,resultZ);
}
