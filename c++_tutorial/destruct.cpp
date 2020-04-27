//
// Created by fengpengfei on 2020/4/24.
//
#include <iostream>
#include <string.h>

using namespace std;
class Point {
public:
    //带参数的构造函数
    Point(int a, int b):x(a),y(b){
        x = x + 100;
    }

    //析构函数
    ~Point(){
        cout<<x-100<<endl;
        cout<<"析构函数被调用。。"<<endl;
    }

    void show(){
        cout<<x<<","<<y<<endl;
    }

private:
    int x,y;
};

int main(){
     Point pt1(10,20);
     pt1.show();

    return 0;
}

