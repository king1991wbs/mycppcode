/*************************************************************************
	> File Name: multithread.cpp
	> Author: wilson_91
	> Mail: wilson_91@foxmail.com 
	> Created Time: Fri 27 Jun 2014 09:06:46 PM CST
 ************************************************************************/

#include<iostream>
#include <condition_variable>
#include <mutex>
#include <thread>
//#include <queue>
#include <chrono>
//using namespace std;
//
int main()
{
   // std::mutex time_lock,image_process_lock;
    std::mutex lock;
    std::condition_variable cv;
    //time_lock.lock();

    std::thread thread_time([&]()
                       {
                        while(true)
                           {
                               //time_lock.lock();
                               std::unique_lock<std::mutex> lck(lock);
                               cv.wait(lck);
                               //do time work
                               std::cout << "time thread running..." << std::endl;
                              //image_process_lock.unlock();
                               std::this_thread::sleep_for(std::chrono::milliseconds(1));
                           }
                       });

    std::thread thread_image_process([&]()
                                     {
                                         while(true)
                                         {
                                            //do some process work
                                             std::cout << "image process thread running..." << std::endl;
                                             cv.notify_one();
                                         }
                                     });

    thread_time.join();
    thread_image_process.join();

    return 0;
}


