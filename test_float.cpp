/*************************************************************************
	> File Name: test_float.cpp
	> Author: wilson_91
	> Mail: wilson_91@foxmail.com 
	> Created Time: Sun 08 Jun 2014 11:26:14 AM CST
 ************************************************************************/

#include<iostream>
//using namespace std;


int main()
{
    double f = 0.00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001;
    if(f == 0)
    {
        std::cout << "not strict!" << std::endl;
    }
    else
    {
        std::cout << "strict!" << std::endl;
    }
    return 0;
}

