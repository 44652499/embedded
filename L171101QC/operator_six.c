#include <stdio.h> 
#include <limits.h> 
/*
位运算符号:
&:与
|:或
^:异或
~:非
>>:右移
<<:左移
位运算一般是处理二进制数(0 1)
0 &0 =0  1&1=1  0&1=0
0|0=0   1|0 =1  1|1=1
~0=1  ~1=0
0^1=1  0^0=0  1^1=0
三码:原码  反码  补码
正数:三码一样
负数: abs(负数)原码取反+1= 补码
      补码除符号位取反+1   =原码
+0 与 -0 补码?
+0: 0 ... 0000
-0: 0 ... 0000   取反  1 ... 1111 +1 =0 ...0000      
*/
int main(int argc,const char* argv[])
{
   // int a=3;
    // int b=5;
    // printf("%d\n",a&b);
    //a=3  0 0011
    //b=5  0 0101
    //a&b= 0 0001
    // int b=-5;
    // printf("%d\n",a&b);
    //a=3  0 0011
    //b=-5 0 0101   1 1010 +1  1 1011
    //a&b=0 0011

   // int a=-3;
    //int b=-5;
  //  printf("%d\n",a&b);
    //a=0 0011   1 1100  +1   1 1101
    //b=0 0101   1 1010  +1   1 1011
    //a&b=1  1001 最高位为1  表示负数
    //1 1001   1  0110 +1   1  0111  

    //printf("%d\n",a^b);
    //a=0 0011   1 1100  +1   1 1101
    //b=0 0101   1 1010  +1   1 1011
    //a^b=0 0110 
    //右移舍弃低n位,高位补n个符号位:
    //int a=9;
    //int a=-9;
    //printf("%d\n",a>>2);
    //a=9  0  1001    >>2  0   0010
    //a>>2相当于 a/2^2

    //a=-9  0 1001   1  0110  +1  1  0111  >>2  1  1101   1  0010 +1  1  0011  -3
    //a>>2  a/2^2 相当于取小于计算结果最大整数值

    //左移动:舍弃高n位,低位补n个0
    //int a=-9 ;
    //printf("%d\n",a<<2);
    //a=-9   0 1001  1  0110  +1  1  0111  <<2  1  1101 1100 
    //1  0010 0011 +1   1 0010 0100

    int a=-9 ;
    printf("%d\n",a<<1+1);//考虑符号优先级
    return 0;
}

/*
优先级	运算符	结合律
1	( )  [ ]  ->  .	从左至右
2	!  ~  ++  --  （类型） sizeof +  -  *  &	从右至左
3	*  /  %	从左至右
4	+  -	从左至右
5	<<  >>	从左至右
6	<   <=   >  >=	从左至右
7	==  !=	从左至右
8	&	从左至右
9	^	从左至右
10	|	从左至右
11	&&	从左至右
12	||	从左至右
13	?:	从右至左
14	=  +=  -=  *=  /=  %=  &=  ^= |=  <<=  >>=	从左至右
15	, 

取反(! ~)>运算>左右移>比较>位(&  ^  |)>逻辑

结核性


*/
