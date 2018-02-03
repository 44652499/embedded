#include "appheader.h"
/*

*/

int isconnect=0;//是否连接其它的服务器
void  timeout_fun(int signum)
{
	isconnect=1;
}
int main(int argc, char const *argv[])
{
	int sckd=socket(PF_INET,SOCK_STREAM,0);
	if(sckd==-1)
	{
		perror("socket:");
		exit(-1);
	}
	struct sockaddr_in  seraddr;
	bzero(&seraddr,sizeof(seraddr));
	seraddr.sin_family=AF_INET;
	seraddr.sin_port=htons(PORT);
  seraddr.sin_addr.s_addr=inet_addr("192.168.252.3");
  alarm(5);
  signal(SIGALRM,timeout_fun);
  printf("connecting..................\n");
  int ret=connect(sckd,(struct sockaddr*)&seraddr,sizeof(seraddr));
    while(ret==-1)
    {
    	if(isconnect==1)
    	{
    		 alarm(5);
    		 seraddr.sin_addr.s_addr=inet_addr("192.168.252.5");
    		 isconnect=0;
    	}
    	ret=connect(sckd,(struct sockaddr*)&seraddr,sizeof(seraddr));
    }	
    printf("connect ok\n");
    alarm(0);
   while(1)
   {
   	char buf[100];
   	gets(buf);
	int ret=send(sckd,buf,strlen(buf),0);	
	//bzero(buf,sizeof(buf));
	//recv(sckd,buf,sizeof(buf)-1,0);
	//printf("recv:%s\n",buf);	
   }
	
	close(sckd);
	return 0;
}