/#include<stdio.h>
#include<sys/shm.h>
#include<sys/sem.h>
#include<sys/types.h>
#define KEY 0X29980
void main()
{
	struct sembuf semop3;
	char *nik;
	int shmid=shmget(KEY,512,IPC_CREAT|0660);
	nik=shmat(shmid,NULL,0);
	int semid=semget(KEY,2,IPC_CREAT|0660);
	semctl(semid,0,SETVAL,0);
	semctl(semid,1,SETVAL,0);

	semop3.sem_num=0;
	semop3.sem_op=-1;
	semop3.sem_flg=0;
	semop(semid,&semop3,1);
       	printf("%s\n",nik);

	semop3.sem_num=1;
	semop3.sem_op=+1;
	semop3.sem_flg=0;
	scanf("%s",&nik[256]);
	semop(semid,&semop3,1);
}

