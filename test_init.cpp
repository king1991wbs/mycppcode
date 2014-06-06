/*************************************************************************
	> File Name: test_init.cpp
	> Author: wilson_91
	> Mail: wilson_91@foxmail.com 
	> Created Time: Sun 01 Jun 2014 10:38:49 PM CST
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

struct C
{
    C(int i):c(i){}
    int c;
};

struct init
{
    int a = 1;
    const string b = "hello";
    C c(1);
    init(){}
};
int main()
{
    string s("gg");
    return 0;
}
