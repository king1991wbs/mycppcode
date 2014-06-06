/*************************************************************************
	> File Name: test_lambda_quote.cpp
	> Author: wilson_91
	> Mail: wilson_91@foxmail.com 
	> Created Time: Fri 06 Jun 2014 10:04:27 AM CST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
//using namespace std;

void Stat(std::vector<int> &v)
{
    int errors;
    int score;
    auto print = [&](){
        std::cout << "Errors:" << errors << std::endl << "Score: " << score << std::endl;
    };

    errors = accumulate(v.begin(),v.end(),0);
    score  = accumulate(v.begin(),v.end(),100,std::minus<int>()); 
    print();

    errors = 0;
    score = 100;

    for_each(v.begin(),v.end(),[&](int i){
        errors += i;
        score -= i;
    });
   // print();
    std::cout << errors << "  " << score << std::endl;
}

int main()
{
    std::vector<int> v(10);
    generate(v.begin(),v.end(),[]{
        return rand() % 10;
    });
    Stat(v);
    return 0;
}

