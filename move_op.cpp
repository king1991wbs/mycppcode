/*************************************************************************
	> File Name: move_op.cpp
	> Author: wilson_91
	> Mail: wilson_91@foxmail.com 
	> Created Time: Mon 02 Jun 2014 08:22:21 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class HasPtrMem
{
public:
    HasPtrMem():d(new int(3))
    {
        cout << "Constructor: " << ++n_cstr << endl;
    }
    HasPtrMem(const HasPtrMem &h):d(new int(*h.d))
    {
        cout << "Copy constructor: " << ++n_cptr << endl;
    }
    HasPtrMem(HasPtrMem &&h):d(h.d)
    {
        h.d = nullptr;
        cout << "Move constructor: " << ++n_mvtr << endl;
    }
    ~HasPtrMem()
    {
        delete d;
        cout << "Move constructor: " << ++n_dstr << endl;
    }

    int *d;
    static int n_cptr;
    static int n_cstr;
    static int n_dstr;
    static int n_mvtr;
};
int HasPtrMem::n_cptr = 0;
int HasPtrMem::n_cstr = 0;
int HasPtrMem::n_dstr = 0;
int HasPtrMem::n_mvtr = 0;

HasPtrMem GetTemp()
{
    HasPtrMem h;
    cout << "Resource from " << __func__ << ":" << hex << h.d <<endl;
    return h;
}

int main()
{
    HasPtrMem a = GetTemp();
    cout << "Resource from " << __func__ << ":" << hex << a.d <<endl;
    return 0;
}
