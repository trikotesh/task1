#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

void *oddthread();
void *eventhread();

int main()
{
        pthread_t ti1,ti2;
        pthread_create(&ti1,NULL,oddthread,NULL);
        pthread_create(&ti2,NULL,eventhread,NULL);
        pthread_join(ti1,NULL);
        pthread_join(ti2,NULL);
}
void *oddthread()
{
        int i;
        for(i=1;i<=10;i++)
        {


                if(i%2!=0)                
                        printf("thread 1 %d\n",i);
                        sleep(1);
        }
}

void *eventhread()
{
	int i;
        for(i=1;i<=10;i++)
        {
    
                if(i%2==0)
                        printf("thread 2 %d\n",i);
      
                        sleep(1);
        }
}

