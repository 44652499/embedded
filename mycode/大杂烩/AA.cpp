#include <iostream>
using namespace std;

class B;
template<class T,class T2>
//template<class T,class T2>
class A
{
  public:
  	A(int _len,T2 b=T2())
  	//A(int _len,T2 b=T2())
  	{
  	   len=_len;
       data=new T[len];
       inputdata();
       sort(b);
  	}
  	void inputdata()
  	{
  		int i;
  		for(i=0;i<len;i++)
  		{
  			cin>>data[i];
  		}
  	}

  	void outputdata()
  	{
  		int i;
  		for(i=0;i<len;i++)
  		{
  			cout<<data[i]<<"\t";
  		}
  		cout<<endl;
  	}

  	void sort(T2 _b)
  	{
  		int i,j;
        for(i=0;i<len;i++)
        {
        	for(j=0;j<len-i-1;j++)
        	{
        		if(_b(data[j],data[j+1]))
        		{
        			int tmp=data[j];
        			data[j]=data[j+1];
        			data[j+1]=tmp;
        		}
        	}
        }
  	}

  private:
  	T* data;
  	int len;
};

class B
{
public:	
	bool operator()(int a,int b)
	{
		//return (a>b);
		return (a<b);
	}
};

int main(int argc, char const *argv[])
{
	//A<int> a1(200);
	//A<int,B> a2(200);
	//A<int,B> a1(200);

	A<int,B> a(6);
	a.outputdata();
	return 0;
}
