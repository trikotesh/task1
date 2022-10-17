#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
int main()
{
	int fd,ret;
	char rbuf[10],wbuf[10];
	mkfifo("cltfifo",0664);
	while(1)
	{
	fd=open("serfifo",O_WRONLY);
	scanf("%[^\n]s",wbuf);
	__fpurge(stdin);
	write(fd,wbuf,strlen(wbuf));
	close(fd);
	fd=open("cltfifo",O_RDONLY);
	ret=read(fd,rbuf,10);
	rbuf[ret]='\0';
	printf("%s\n",rbuf);
	close(fd);
	}


}
			
