/*************************************************************************
	> File Name: test_lambda.cpp
	> Author: wilson_91
	> Mail: wilson_91@foxmail.com 
	> Created Time: Fri 06 Jun 2014 09:17:48 AM CST
 ************************************************************************/

#include<iostream>
//using namespace std;
//
//
int d = 0;
int main()
{
    int e = 1;
    auto i = [&]() ->int {
        e += 1;
        d += 1;     //内层局部变量，隐藏外部变量
        return d;};

    d += 1;
    std::cout << "the value of d:" << d <<  std::endl;
    std::cout << "the value of i():" << i() << std::endl << " e:" << e << " d:"  << d << std::endl;
    //std::cout << " e:" << e << " d:" << d << std::endl;
    return 0; 
}

