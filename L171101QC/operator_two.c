#include <stdio.h> 
#include <limits.h> 
/*
程序=逻辑+表达式
表达式=操作数+操作符号
C语言常用操作符号:
1.运算符号
2.逻辑符号
3.比较符号
4.位运算符号
5.赋值符号
6.逗号
7.问号(?:)
8.其它符号

i++/++i
i++:后置++,先赋值再+1.首先分配一个临时空间,将a赋值给临时空间,再改变a空间值
++i:前置++,先+1再赋值.不分配临时空间,全在a空间值完成
++i效率高于i++


*/
int main(int argc,const char* argv[])
{
    //int a=5;
    //printf("%d\t%d\t%d\n",a++,++a,a++);//函数参数存储栈(FILO)
    // int a=3;
    // printf("%d\n",(a++)+(a++)+(a++));//个人认为输出9.原因是:后置++在表达式计算完毕后再+1
    // int b=3;
    // printf("%d\n",(++b)+(++b)+(++b));//5+5+6=16??

    int a=3;
    //int b=a+++++a;//自增操作数必须是左值
    //符号贪婪法:多个符号连续结合必须保证是一个有效正确符号,否则就不能结合,符号后面就必须为操作数
    //int b=a++ + ++a;//用户空格解决符号结合问题
    //int b=a+++a++;
    int *p=&a;
    //int b=9/*p;//"/*"注释符号一部分
    //int b=9/(*p);
    printf("%d\n",b);
    return 0;
}