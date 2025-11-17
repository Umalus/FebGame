#define STB_IMAGE_IMPLEMENTATION
#include "TextureResource.h"
#include "../Manager/FBXLoader.h"
#include <ImageTranscode.h>
#include "../ThirdParty/stb_image.h"
#include <glad/glad.h>

TextureResource::TextureResource()
	:textureID{-1}
	,texturePath{""}
{
}

TextureResource::~TextureResource()
{
	
}

void TextureResource::Load(const std::string& _filePath)
{
	//ロード済みなら早期リターン
	if (isLoaded)return;

	//画像を読み込む
	//FBXManagerの初期化
	FBXLoader loader;
	bool isFbxDataLoaded = loader.LoadFBX(_filePath);
	//ロード出来ていなければ早期リターン
	if (!isFbxDataLoaded)
		return;
	//マテリアルを取得
	int width, height, channels;		//読み込んだテクスチャの幅、高さ、チャンネル数
	FbxSurfaceMaterial* matrial = loader.GetScene()->GetNode(0)->GetMaterial(0);
	FbxSurfacePhong* phong = dynamic_cast<FbxSurfacePhong*>(matrial);
	//テクスチャを取得
	FbxProperty prop = matrial->FindProperty(FbxSurfaceMaterial::sDiffuse);
	if (prop.IsValid()) {
		FbxFileTexture* texture = prop.GetSrcObject<FbxFileTexture>(0);
		std::string texturePath = texture->GetFileName();
		//バッファをテクスチャのパスから受け取る
		unsigned char* data = stbi_load(texturePath.c_str(), &width, &height, &channels, 0);
		//データが受け取れなければ処理しない
		if (!data)return;

		//データをバインド
		GLuint textureID;
		glGenTextures(1, &textureID);
		glBindTexture(GL_TEXTURE_2D, textureID);
		//チャンネル数によって分岐
		GLenum format = (channels == 4) ? GL_RGBA : GL_RGB;
		glTexImage2D(GL_TEXTURE_2D,0,format,width,height,0,format,GL_UNSIGNED_BYTE,data);

		//フィルタリングとラップモードの設定
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		//textureIDを保存
		this->textureID = textureID;

		//texturePathを保存
		this->texturePath = texturePath;

		//データを解放
		stbi_image_free(data);
	}
}

void TextureResource::UnLoad()
{
	//テクスチャIDがリセットされていなければバインドしたテクスチャとIDをリセット
	if(textureID != -1)
	glDeleteTextures(1, &textureID);
	textureID = -1;
}

void TextureResource::Clear()
{
	//パスをクリア
	texturePath.clear();
	//テクスチャIDがリセットされてなければ念のためリセット
	if (textureID != -1)
		textureID = -1;
}

bool TextureResource::isLoaded() const
{
	//IDとパスが両方とも設定されていたらture
	return textureID != -1 && !texturePath.empty();
}

void TextureResource::Bind(GLuint _index)
{
	glActiveTexture(GL_TEXTURE0 + _index);
	glBindTexture(GL_TEXTURE_2D, textureID);
}

int TextureResource::GetTextureID() const
{
	return textureID;
}

std::string TextureResource::GetTexturePath() const
{
	return texturePath;
}
