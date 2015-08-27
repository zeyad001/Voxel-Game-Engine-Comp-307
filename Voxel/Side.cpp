#include "Side.h"

Side::Side(std::string s)
{
    this->imagePath = s;
}
Side::Side()
{
}
Side::Side(Side* s)
{
    this->imagePath = s->imagePath;
}

Side::~Side()
{
}
