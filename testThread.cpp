/*************************************************************************
	> File Name: testThread.cpp
	> Author: wilson_91
	> Mail: wilson_91@foxmail.com 
	> Created Time: Sun 01 Jun 2014 12:40:23 PM CST
 ************************************************************************/

#include<iostream>
#include<atomic>
#include<thread>
//using namespace std;

std::atomic_llong total{0};

void func()
{
    for(long long i = 0;i < 100000000LL;i++)
        total += i;
}
int main()
{
    std::thread t1(func);
    std::thread t2(func);

    t1.join();
    t2.join();

    std::cout << "total = " << total << std::endl;
    return 0;
}
