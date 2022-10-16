#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
int fd1,ret1,ret2;
char rbuf1[10],rbuf2[10],wbuf1[10]="trikotesh",wbuf2[10]="sirasani",buf[10];
fd1=open("12.txt",O_CREAT|O_WRONLY,0777);
ret2=write(fd1,wbuf1,strlen(wbuf1));
fd1=open("12.txt",O_RDONLY);
ret1=read(fd1,rbuf1,ret2);
rbuf1[ret1]='\0';
printf("%d\n%s\n",ret1,rbuf1);
fd1=open("13.txt",O_CREAT|O_WRONLY,0777);
ret2=write(fd1,wbuf2,strlen(wbuf1));
fd1=open("13.txt",O_RDONLY);
ret1=read(fd1,rbuf2,ret2);
rbuf2[ret1]='\0';
printf("%d\n%s\n",ret1,rbuf2);
fd1=open("12.txt",O_WRONLY);
lseek(fd1,SEEK_SET,0);
write(fd1,rbuf2,strlen(rbuf2));
fd1=open("13.txt",O_WRONLY);
lseek(fd1,SEEK_SET,0);
write(fd1,rbuf1,strlen(rbuf1));



}

