#include <iostream>

#include <cs/base.h>
#include <cs/core.h>

int main(int argc, char** argv)
{
    cs::base::CSString str;
    str += u8"hoge";

    std::cout << str.c_str() << std::endl;
}
