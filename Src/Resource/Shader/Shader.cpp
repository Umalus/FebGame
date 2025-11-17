#include "Shader.h"
#include <fstream>
#include <sstream>
#include <iostream>

Shader::Shader()
    :programID{0}
{
}

Shader::~Shader()
{
}

bool Shader::Load(const std::string& _vertPath, const std::string& _fragPath)
{
    //頂点シェーダーのソースコード取得
    std::string vertSource = LoadFile(_vertPath);
    //フラグメントシェーダーのソースコード取得
    std::string fragSource = LoadFile(_fragPath);
    //コンパイル
    GLuint vertID = Compile(GL_VERTEX_SHADER, vertSource);
    GLuint fragID = Compile(GL_FRAGMENT_SHADER, fragSource);
    //どちらかがエラーなら処理を止める
    if (vertID == -1 || fragID == -1) {
        std::cerr << "どちらかのシェーダーがありません" << std::endl;
        return false;
    }
    //プログラム作成とリンク
    programID = glCreateProgram();
    glAttachShader(programID, vertID);
    glAttachShader(programID, fragID);

    glLinkProgram(programID);
    glValidateProgram(programID);

    //シェーダーオブジェクトを破棄
    glDeleteShader(vertID);
    glDeleteShader(fragID);

    //ここまで通ってtrueを返す
    return true;
}

void Shader::Bind() const
{
    //初期化状態のままなら処理しない
    if (programID == 0)return;
    //バインドします
    glUseProgram(programID);
}

void Shader::UnBind() const
{
    //バインドを解除します
    glUseProgram(0);
}

void Shader::SetUniformMat4(const std::string& _uMVP, const Matrix_4x4& _matrix)
{
    glUseProgram(programID);
    std::array<float, 16> data = _matrix.GetDataArray();
    glUniformMatrix4fv(GetUniformLocation(_uMVP), 1, GL_FALSE,data.data() );
}

void Shader::SetUniformVec3(const std::string& _uColor, const Vector3& _color)
{
    GLint location = glGetUniformLocation(programID, _uColor.c_str());
    glUniform3fv(location, 1, &_color.x);
    
}

void Shader::SetUniformInt(const std::string& _uMap, int _slot)
{
    GLint location = glGetUniformLocation(programID, _uMap.c_str());
    glUniform1i(location, _slot);
}

std::string Shader::LoadFile(const std::string& _filePath)
{
    //ファイル読み込み
    std::ifstream ifs(_filePath);
    //読み込みエラー
    if (!ifs) {
        std::cerr << "ファイルが読み込めませんでした！" << std::endl;
        return "";
    }
    //一行ずつ読み込み、ソースコードを文字列に起こす
    std::string line;
    std::string sourceCode;
    while (std::getline(ifs, line)) {
        sourceCode += line + "\n";
    }
    //ファイルを閉じる
    ifs.close();


    return sourceCode;
}

GLuint Shader::Compile(GLenum _type, const std::string& _source)
{
    //最終的に返す値
    int result;

    const char* src = _source.c_str();
    //シェーダーオブジェクトの作成
    GLuint shaderObj = glCreateShader(_type);
    //ソースコードを渡す
    glShaderSource(shaderObj,1,&src, nullptr);
    //コンパイル
    glCompileShader(shaderObj);
    //確認
    glGetShaderiv(shaderObj,GL_COMPILE_STATUS,&result);
    if (result == GL_FALSE) {
        std::cerr << "失敗" << std::endl;
        return -1;
    }
    //値を返す
    return shaderObj;
}

GLint Shader::GetUniformLocation(const std::string& _name)
{
    //ロケーションを返す
    GLint location = glGetUniformLocation(programID, _name.c_str());


    return location;
}
