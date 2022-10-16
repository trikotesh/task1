#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
        int fd[2],fd1[2],ret,ret1;
        char wbuf[20],rbuf[20];
        pipe(fd);
        pipe(fd1);

        int pid=fork();
while(1)
{
        if(pid>0)
        {

                close(fd[0]);
                scanf("%[^\n]s",wbuf);
                __fpurge(stdin);
                write(fd[1],wbuf,strlen(wbuf));
                printf("parent is sending data\n%s\n",wbuf);
                close(fd1[1]);
                ret=read(fd1[0],rbuf,15);
                rbuf[ret]='\0';
                printf("parent is reading data\n%s\n",rbuf);
        }
        else
        {
                close(fd[1]);
                ret1=read(fd[0],rbuf,15);
                rbuf[ret1]='\0';
                printf("child is reading data\n%s\n",rbuf);
                close(fd1[0]);
                scanf("%[^\n]s",wbuf);
		__fpurge(stdin);
                write(fd1[1],wbuf,strlen(wbuf));
                printf("child is sending data\n%s\n",wbuf);

        }

}
}

