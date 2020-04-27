//
// Created by fengpengfei on 2020/4/24.
//
#include <iostream>
#include <string.h>

using namespace std;
class CString {
public:
    CString(const char *str);
   ~CString();
    void show(){
        cout<<p<<endl;
    }

private:
    char *p;//存储字符串的动态内存区
};


CString::CString(const char *str) {
    p = new char [strlen(str) + 1];
    strcpy(p, str);
    cout<<"构造："<<str<<endl;
}

CString::~CString() {
    cout<<"析构："<<p<<endl;
    delete []p;
}

int main(){
     CString s1("C++"), s2="Go";//定义对象
     s1.show();
     s2.show();
    return 0;
}

