#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
char buf[10];
pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex1=PTHREAD_MUTEX_INITIALIZER;
void *capitalthread();
void *lowerthread();
int main()
{
	
	scanf("%[^\n]s",buf);
        pthread_t ti1,ti2;
        pthread_create(&ti1,NULL,capitalthread,buf);
        pthread_create(&ti2,NULL,lowerthread,buf);
        pthread_join(ti1,NULL);
        pthread_join(ti2,NULL);
}
void *capitalthread()
{
        int i;
        for(i=0;buf[i]!='\0';i++)
        {

                pthread_mutex_lock(&mutex1);
                if(buf[i]<91&&buf[i]>64)
                printf("thread capital %c\n",buf[i]);
                pthread_mutex_unlock(&mutex);

        }
}

void *lowerthread()
{
        int i;
        for(i=0;buf[i]!='\0';i++)
        {
                pthread_mutex_lock(&mutex);
                if(buf[i]<123&&buf[i]>96)
                printf("thread 1ower %c\n",buf[i]);
		pthread_mutex_unlock(&mutex1);

        }
}

