#include  <iostream>
using namespace std;
template<class T>
class  Array
{
//声明友元模板函数
// template<class T1>
// friend istream&  operator >>(istream& in,Array<T1>  & obj);
// template<class T1>
// friend ostream &  operator <<(ostream& out,Array<T1>& obj);
public:
	Array(int _size)
	{
		size=_size;
		ptr=new T[size];
	}
	//T operator[](int index)//获取元素值
	T& operator[](int index)//反写元素值
	{
		//增加判断数组是否越界
		if(index<size)
		   return ptr[index];
		else
		{
			cout<<"out of range"<<endl;
			return ptr[0];//不能返回常数值
		}
	}
	bool operator==(Array<T> obj)
	{
		bool is_equal=true;
		if(this->size!=obj.size)
		{
			is_equal=false;
			return is_equal;
		}
		int i;
		for(i=0;i<obj.size;i++)
		{
			if((*this)[i]!=obj[i])
			{
				is_equal=false;
				return is_equal;
			}
		}
		return is_equal;		
	}
private:
	T*  ptr;
	int size;
};
//模板类的输入输出重载
// template<class T>
// istream&  operator >>(istream& in,Array<T>  & obj)
// {
// 	int i;
// 	for(i=0;i<8;i++)
// 	{
// 		in>>obj.ptr[i];
// 	}
// 	return in;
// }
// template<class T>
// ostream &  operator <<(ostream& out,Array<T>& obj)
// {
// 	int i;
// 	for(i=0;i<obj.size;i++)
// 	{
// 		cout<<obj.ptr[i]<<"\t";
// 	}
// 	cout<<endl;
// 	return out;
// }
int main(int argc, char const *argv[])
{
	Array<int>  a1(5);
    Array<int>  a2(5);
	//cin>>a1>>a2;
	// if(a1==a2)
	// {
	// 	cout<<"a1==a2"<<endl;
	// }
	// else
	// {
	// 	cout<<"a1!=a2"<<endl;
	// }

	int i  ;
	for(i=0;i<8;i++)
	{
		cin>>a1[i];
	}
	return 0;
}