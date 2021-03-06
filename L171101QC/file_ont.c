#include <stdio.h>
/*
文件编程:
1.文件存储在存储磁盘(硬盘)的数据.一般分为数据文件和设备文件
数据文件:存储数据,一般指文本文件(源码文件),二进制文件(程序执行文件)
设备文件:与操作系统有关,表示某种设备.如:键盘 鼠标 显示器等.通过操作一种特殊文件实现操作设备
2.程序中操作文件实质是把文件映射到当前进程空间.所有文件读写操作都是在进程内存空间.不直接访问存储磁盘.
  读文件:内核后台进程从磁盘文件数据读取到文件读取缓存区.把内核数据复制到用户空间,程序从进程用户空间读取
  写文件:用户程序把数据写入到进程用户空间缓存,复制用户空间数据到内核文件写入缓存区.内核后台写入进程写数据到存储磁盘文件
3.文件编程API 分为两类:
  1.标准c API
  2.系统文件 API(linux  window)
标准c API使用通用文件编程API:
FILE:标准c是内存文件结构,含有文件状态,文件当前读写我位置等信息
FILE基于文件流读写文件
文件操作三步:
1.打开文件:a.告知内核访问文件名及其路径值  b.指定进程对文件访问的状态 c.创建文件结构并返回FILE指针
2.文件读写操作
3.关闭:a.告知内核文件操作结束,可以刷新内核文件缓存数据 b.释放进程文件结构

打开文件:
fopen
FILE *fopen(const char *path, const char *mode);
const char *path:文件路径值可以是绝对路径值或相对路径值
const char *mode:访问模式,对文件访问权限,读写/只读/只写
返回值:文件流FILE * 指针
文件文件模式:
rt:只读方式打开文本文件,文件必须存在否则错误
wt:只写方式打开文本文件,文件如果不存在先创建,如果存在先清空文件再写入新数据.
at:只写方式打开文本文件,如果文件存在先移动文件内部指针到文件末尾,在文件末尾写入数据.如果文件不存在创建文件
rt+:读写方式打开文件
wt+:读写方式打开文件
rb:只读方式打开二进制文件,文件必须存在否则错误
wb:只写方式打开二进制文件,文件如果不存在先创建,如果存在先清空文件再写入新数据
ab:只写方式打开二进制文件,如果文件存在先移动文件内部指针到文件末尾,在文件末尾写入数据.如果文件不存在创建文件.
rb+读写方式打开文件
wb+读写方式打开文件

读取文件
fgets
 char *fgets(char *s, int size, FILE *stream);
 char *s:指向程序一个存放文件数据数组
 int size:读取文件字符数.如果先遇到文件换行字符,停止读取下一行

fgetc
 int fgetc(FILE *stream);
 读取单个字符

*/
int main(int argc,const char* argv)
{
    //FILE *  fp=fopen("abc.txt","rt");
   // FILE *  fp=fopen("abc.txt","wt");
   //FILE *  fp=fopen("abc.txt","at");
   FILE *  fp=fopen("/etc/passwd","rt");
    if(fp==NULL)
    {
        perror("fopen:");//输出内核错误信息
        return ;
    }
    char  buf[1024];
    bzero(buf,sizeof(buf));
    //fgets(buf,sizeof(buf)-1,fp);
    //printf("%s\n",buf);
    //printf("%c\n",fgetc(fp));
    //循环读取文件所有数据
    // while(1)
    // {
    //     char c=fgetc(fp);
    //     if(c==EOF)  //EOF表示读取到文件末尾
    //     {
    //         break;
    //     }
    //     printf("%c",fgetc(fp));
    // }

    while(!feof(fp))
    {
        bzero(buf,sizeof(buf));
        fgets(buf,sizeof(buf)-1,fp);
        printf("%s\n",buf);
    }
    fclose(fp);
}