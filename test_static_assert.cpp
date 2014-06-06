/*************************************************************************
	> File Name: test_static_assert.cpp
	> Author: wilson_91
	> Mail: wilson_91@foxmail.com 
	> Created Time: Sun 01 Jun 2014 09:50:39 PM CST
 ************************************************************************/

#include<iostream>
//using namespace std;

template <typename T,typename U> 
int bit_copy(T& a,U& b)
{
    static_assert(sizeof(b) == sizeof(a),"the parameters of bit_copy must have same width!");
    //memcpy(&a,&b,sizeof(b));
}
int main()
{
    int a = 0x2468;
    double b;
    bit_copy(a,b);
    return 0;
}

