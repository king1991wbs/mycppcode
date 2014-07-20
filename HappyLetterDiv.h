/*************************************************************************
	> File Name: HappyLetterDiv.h
	> Author: wilson_91
	> Mail: wilson_91@foxmail.com 
	> Created Time: Sun 20 Jul 2014 09:41:17 AM CST
 ************************************************************************/

#include<iostream>
//using namespace std;
//
#include<map>
#include<string>
#include<functional>
#include<algorithm>

class HappyLetterDiv
{
    public:
        HappyLetterDiv() { for(auto &e : letterNums) { e = 0; } }
        ~HappyLetterDiv(){}
        std::string getHappyLetters();
    protected:
        void countLetterNum(const std::string&);
        std::multimap<int,char,std::greater<int> > sortChar();
        std::string letterLeaved(std::multimap<int,char,std::greater<int> >);
    private:
        int letterNums[26];
};

void HappyLetterDiv::countLetterNum(const std::string& letters)
{
    for(auto c : letters)
    {
        letterNums[c - 'a']++;
    }
}
std::multimap<int,char,std::greater<int> > HappyLetterDiv::sortChar()
{
    std::multimap<int,char,std::greater<int> > sortedLetter;
    for(int i = 0;i < 26;i++)
    {
        sortedLetter.insert(std::pair<int,char>(letterNums[i],static_cast<char>('a'+i)));
    }

//    for(auto i:sortedLetter)
//    {
//        std::cout << i.first << ":" << i.second;
//    }
//    std::cout << std::endl;

    return sortedLetter;
}
std::string HappyLetterDiv::letterLeaved(std::multimap<int,char,std::greater<int> > sortedLetter)
{
//    for(auto e:sortedLetter)
//    {
//        std::cout << e.first << ":" << e.second << std::endl;
//    }

    std::string leaved;
    for(auto i = sortedLetter.begin();i != sortedLetter.end() && i->first != 0;i++)//判断第i个元素能不能留下
    {
        //if(i->first == 0) break;//为0的话，元素不存在(包括后面)

        auto j = sortedLetter.begin();
        if(j == i) j++;//最后再与第i个的个数比较
        int  temp = j->first;
        if(++j == i) j++;
        //int temp = sortedLetter.begin() == i ? ++sortedLetter.begin()->first:sortedLetter.begin()->first; 
        for(;j != sortedLetter.end();j++)
        { 
            if(j ==i) continue;
            temp = abs(temp - j->first);
        }
        if(i->first > temp) leaved += i->second;
    }
    std::cout << leaved << std::endl;
    std::sort(leaved.begin(),leaved.end());
    std::cout << leaved << std::endl;
    std::sort(leaved.begin(),leaved.end());
    return ":" + leaved;
}
std::string HappyLetterDiv::getHappyLetters()
{
    std::string letters;
    std::cout << "please input your character:" << std::endl;
    std::cin >> letters;
    
    countLetterNum(letters);

    return letterLeaved(sortChar());
}

