#include<stdio.h>
#include<sys/shm.h>
#include<sys/types.h>
#include<sys/sem.h>
#define KEY 0X29980
void main()
{
        struct sembuf semop3;
        char *nik;
        int shmid=shmget(KEY,512,0);
        nik=shmat(shmid,NULL,0);
        int semid=semget(KEY,2,0);
        scanf("%s",nik);

	semop3.sem_num=0;
        semop3.sem_op=+1;
        semop3.sem_flg=0;
        //scanf("%s",addk);
	//
        semop(semid,&semop3,1);

	semop3.sem_num=1;
        semop3.sem_op=-1;
        semop3.sem_flg=0;
	semop(semid,&semop3,1);

        printf("%s\n",&nik[256]);

}
