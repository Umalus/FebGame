#pragma once
#include "Resource.h"
#include "../Math/Vec3.h"
#include "TextureResource.h"
#include "../Manager/FBXLoader.h"
enum class ColorMode {
	Diffuse,
	Specular,
	Emissive,
};

enum class MapMode {
	Diffuse,
	Normal,
	Specular,
	Emissive,
	Opacity,
};


/*
 * @class	MaterialResource
 */
class MaterialResource : public Resource {
public:		//メンバ変数


	Vector3 diffuseColor;		//基本色
	Vector3 specularColor;		//反射色
	Vector3 emissiveColor;		//発光色
	float shininess;			//光沢度
	float transparency;			//透明度

	std::shared_ptr<TextureResource> diffuseMap;	//アルベド
	std::shared_ptr<TextureResource> normalMap;		//法線
	std::shared_ptr<TextureResource> specularMap;	//反射
	std::shared_ptr<TextureResource> emissiveMap;	//発光
	std::shared_ptr<TextureResource> opacityMap;	//透明度
public:			//コンストラクタとデストラクタ

	/*
	 * @brief	コンストラクタ
	 */
	MaterialResource();

	/*
	 * @brief	デストラクタ
	 */
	~MaterialResource();

public:			//オーバーライドしたメンバ関数

	/*
	 * @function	Load
	 * @brief		テクスチャをロード
	 * @param[in]	const std::string	_filePath
	 */
	void Load(const std::string& _filePath)override;
	
	/*
	 * @function	LoadFromFBX
	 * @brief		FBXから直接マテリアルを生成
	 * @param[in]	FbxSurfaceMaterial* mat
	 */
	void LoadFromFBX(FbxSurfaceMaterial* mat);
	
	/*
	 * @function	UnLoad
	 * @brief		テクスチャをアンロード
	 */
	void UnLoad()override;

	/*
	 * @function	Clear
	 * @brief		テクスチャをクリア
	 */
	void Clear()override;

	/*
	 * @function	isLoaded
	 * @brief		ロードしたかどうか
	 * @return		bool
	 */
	bool isLoaded()const override;

private:		//メンバ関数

	/*
	 * @function	FbxDouble3ToVec3
	 * @brief		FbxDouble3をvector3に変換
	 * @param[in]	const FbxDouble3& _color
	 * @return		Vector3
	 */
	Vector3 FbxDouble3ToVec3(const FbxDouble3& _color);

	/*
	 * @function	GetColor
	 * @brief		プロパティから色を抽出
	 * @param[in]	FbxSurfaceMaterial _mat
	 * @param[in]	colorMode _colorMode
	 * @return		Vector3
	 */
	Vector3 GetColor(FbxSurfaceMaterial* _mat, ColorMode _colorMode);

	/*
	 * @function	GetColor
	 * @brief		プロパティから色を抽出
	 * @param[in]	FbxSurfaceMaterial _mat
	 * @param[in]	const std::string& _filePath
	 * @param[in]	mapMode _mapMode
	 * @return		std::shared_ptr<TextureResource>
	 */
	std::shared_ptr<TextureResource> GetTexture(FbxSurfaceMaterial* _mat, MapMode _mapMode);
};
