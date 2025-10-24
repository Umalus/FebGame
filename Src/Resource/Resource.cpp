#include "Resource.h"

Resource::Resource()
    :id{ -1 }   
    ,path{}
{
}

Resource::~Resource()
{
}

std::string Resource::GetPath() const
{
    return path;
}

int Resource::GetID() const
{
    return id;
}
