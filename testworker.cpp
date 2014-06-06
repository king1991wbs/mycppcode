/*************************************************************************
	> File Name: testworker.cpp
	> Author: wilson_91
	> Mail: wilson_91@foxmail.com 
	> Created Time: Sun 01 Jun 2014 01:14:19 PM CST
 ************************************************************************/

#include <iostream>
#include <thread>

void worker()
{
        std::cout << "another thread";

}

int main()
{
        std::thread t(worker);
        std::cout << "main thread" << std::endl;
        t.join();
        return 0;

}
