#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
pthread_cond_t cond=PTHREAD_COND_INITIALIZER;
pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex1=PTHREAD_MUTEX_INITIALIZER;
int k=0;
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

	pthread_mutex_lock(&mutex1);
                if(i%2!=0)
                        printf("thread 1 %d\n",i);
		pthread_cond_wait(&cond,&mutex);
                        pthread_mutex_unlock(&mutex);
        }
}

void *eventhread()
{
        int i;
        for(i=1;i<=10;i++)
        {
        	pthread_mutex_lock(&mutex);
		if(i%2==0)
                        printf("thread 2 %d\n",i);
		pthread_cond_signal(&cond);
		pthread_mutex_unlock(&mutex1);
                        
        }
}

