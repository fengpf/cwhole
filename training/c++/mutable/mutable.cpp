#include <iostream> 
using namespace std;
class test
{
	mutable int a;
	int b;
	public:
	test(int _a,int _b) :a(_a),b(_b){};
	void fun() const            //fun是const 函数，不能修改类的对象的数据成员，但由于a被mutable修饰，可以修改，但不能修改b
	{
		a += b;
	}
	void print()
	{
		cout << a << "," << b << endl;
	}
};
