#include  <iostream>
using namespace std;
/*
只读(const):
只读对象:只读变量,表示对象的数据成员不能被类的成员函数修改,
只读数据成员:构造函数中用列表方式初始化.
只读函数成员:在函数中不能修改对象的数据成员,只读成员函数只能调用只读成员函数.


mutable 修饰的成员变量是可以在只读的成员函数中修改

*/
class   A
{
public:
	A(int _a,int _b):b(_b)
	{
		a=_a;
		//b=_b;//错误,不能对只读成员变量赋值
	}
	void  print() const;

	void  fun()
	{
		cout<<b<<endl;//读取可以
		cout<<"fun"<<endl;
	}
private:
	mutable int a;
	const int b;//只读数据成员
};

void  A::print() const
{
	a=400;
	cout<<a<<'\t'<<b<<endl;
}
int main(int argc, char const *argv[])
{
	A  a1(1,2);
	return 0;
}