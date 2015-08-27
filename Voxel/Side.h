#ifndef SIDE_H
#define SIDE_H
#include <string>
class Side
{
public:
    Side(std::string s);
    Side(Side* side);
    Side();
    ~Side();
    std::string imagePath;
};

#endif // Side
