#include "TextureManager.h"

TextureResourceManager::TextureResourceManager()
{
}

TextureResourceManager::~TextureResourceManager()
{
}

std::shared_ptr<TextureResource> TextureResourceManager::LoadTexture(const std::string& _filePath)
{
    //テクスチャを作成してポインタを返す
    std::shared_ptr<TextureResource> loadTexture = std::make_shared<TextureResource>();
    loadTexture->Load(_filePath);
    return loadTexture;
}
