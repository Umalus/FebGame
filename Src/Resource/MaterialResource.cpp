#include "MaterialResource.h"
#include "../Manager/ResourceManager.h"
#include <filesystem>

MaterialResource::MaterialResource()
	: shininess{ -1.0f }
	, transparency{ -1.0f }
{
}

MaterialResource::~MaterialResource()
{
}

void MaterialResource::Load(const std::string& _filePath)
{
	//FbxLoaderを取得
	FBXLoader loader;
	bool isFbxDataLoaded = loader.LoadFBX(_filePath);
	//ロード出来ていなければ早期リターン
	if (!isFbxDataLoaded)
		return;
	FbxNode* node = loader.GetScene()->GetRootNode();
	int materialCount = loader.GetScene()->GetMaterialCount();
	for (int i = 0; i < materialCount; i++) {
		//マテリアルを取得
		FbxSurfaceMaterial* material = node->GetMaterial(i);
		if (!material)continue;

		//マテリアルの型がPhongなら
		if (dynamic_cast<FbxSurfacePhong*>(material)) {
			//光沢や反射が使えるので取得
			//基本色の取得
			diffuseColor = GetColor(material, ColorMode::Diffuse);
			if (diffuseColor == Vector3::zero)
				diffuseColor = Vector3::one;
			//反射色取得
			specularColor = GetColor(material, ColorMode::Specular);
			if (specularColor == Vector3::zero)
				specularColor = Vector3::zero;
			//発光色取得
			emissiveColor = GetColor(material, ColorMode::Emissive);
			if (emissiveColor == Vector3::zero)
				emissiveColor = Vector3::zero;
		}
		//Lambertなら基本色のみ取得
		else {
			//基本色の取得
			diffuseColor = GetColor(material, ColorMode::Diffuse);
			if (diffuseColor == Vector3::zero)
				diffuseColor = Vector3::one;
		}

		//テクスチャの抽出
		diffuseMap = GetTexture(material, MapMode::Diffuse);
		normalMap = GetTexture(material, MapMode::Normal);
		specularMap = GetTexture(material, MapMode::Specular);
		emissiveMap = GetTexture(material, MapMode::Emissive);
		opacityMap = GetTexture(material, MapMode::Opacity);
	}
}

void MaterialResource::LoadFromFBX(FbxSurfaceMaterial* _mat) {
	diffuseColor = GetColor(_mat, ColorMode::Diffuse);
	specularColor = GetColor(_mat, ColorMode::Specular);
	emissiveColor = GetColor(_mat, ColorMode::Emissive);

	diffuseMap = GetTexture(_mat, MapMode::Diffuse);
	normalMap = GetTexture(_mat, MapMode::Normal);
	specularMap = GetTexture(_mat, MapMode::Specular);
	emissiveMap = GetTexture(_mat, MapMode::Emissive);
	opacityMap = GetTexture(_mat, MapMode::Opacity);
}


void MaterialResource::UnLoad()
{
}

void MaterialResource::Clear()
{
}

bool MaterialResource::isLoaded() const
{
	return false;
}

Vector3 MaterialResource::FbxDouble3ToVec3(const FbxDouble3& _color)
{
	return Vector3(_color.mData[0], _color.mData[1], _color.mData[2]);
}

Vector3 MaterialResource::GetColor(FbxSurfaceMaterial* _mat, ColorMode _colorMode)
{
	FbxProperty propaty;
	switch (_colorMode)
	{
	case ColorMode::Diffuse:
		propaty = _mat->FindProperty(_mat->sDiffuse);
		break;
	case ColorMode::Specular:
		propaty = _mat->FindProperty(_mat->sSpecular);
		break;
	case ColorMode::Emissive:
		propaty = _mat->FindProperty(_mat->sEmissive);
		break;
	}

	if (propaty.IsValid())
		return FbxDouble3ToVec3(propaty.Get<FbxDouble3>());;
}

std::shared_ptr<TextureResource> MaterialResource::GetTexture(FbxSurfaceMaterial* _mat, MapMode _mapMode)
{
	FbxProperty propaty;
	switch (_mapMode)
	{
	case MapMode::Diffuse:
		propaty = _mat->FindProperty(_mat->sDiffuse);
		break;
	case MapMode::Normal:
		propaty = _mat->FindProperty(_mat->sNormalMap);
		break;
	case MapMode::Specular:
		propaty = _mat->FindProperty(_mat->sSpecular);
		break;
	case MapMode::Emissive:
		propaty = _mat->FindProperty(_mat->sEmissive);
		break;
	case MapMode::Opacity:
		propaty = _mat->FindProperty(_mat->sTransparentColor);
		break;
	}

	FbxFileTexture* texFile = propaty.GetSrcObject<FbxFileTexture>(0);

	//null確認
	if (!texFile)return nullptr;
	
	std::filesystem::path texPath(texFile->GetFileName());
	std::string justName = texPath.filename().string(); // "xxx.png"



	auto& resourManager = ResourceManager::getInstance();


	std::string texFilePath = "Res/Texture/" + justName;
	resourManager.LoadResource(texFilePath, Texture);
	std::shared_ptr<Resource> texRes = resourManager.GetResourceFromID(resourManager.pathToID[texFilePath]);
	std::shared_ptr<TextureResource> tex = std::dynamic_pointer_cast<TextureResource>(texRes);

	return tex;
}
