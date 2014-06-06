/*************************************************************************
	> File Name: test_or_enum.cpp
	> Author: wilson_91
	> Mail: wilson_91@foxmail.com 
	> Created Time: Sun 01 Jun 2014 08:55:46 PM CST
 ************************************************************************/

#include<iostream>
//using namespace std;

int main()
{
    enum FS{C99 = 0x0001,ExInt = 0x0002,SAssert = 0x0004,NoExcept = 0x0008,SMAX = 0x0010,};
    std::cout << ((SMAX - 1) == (C99|ExInt|SAssert|NoExcept)) << std::endl;
    std::cout << SMAX - 1 << (C99|ExInt|SAssert|NoExcept) << std::endl;
    return 0;
}
