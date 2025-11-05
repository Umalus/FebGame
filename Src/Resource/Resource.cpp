#include "Resource.h"

Resource::Resource()
    :id{ -1 }   
    ,path{}
{
}

Resource::~Resource()
{
}

const std::string Resource::GetPath() const
{
    return path;
}

int Resource::GetID() const
{
    return id;
}

void Resource::SetPath(const std::string _filePath)
{
    path = _filePath;
}

void Resource::SetID(int _ID)
{
    id = _ID;
}
