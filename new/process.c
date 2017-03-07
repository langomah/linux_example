#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<semaphore.h>
#include<stdlib.h>
#include <fcntl.h>
sem_t *s1;
//sem_t s2;
//FILE *fp;
int main() {
	int a, res;
        pid_t pid;
        FILE *fp;
	char buff[20];
        char v;
	s1 = sem_open("/process", O_CREAT, 0777,0);
	//printf("retval %d\n",v);	

	fp=fopen("1.txt","w+");
	pid=fork();
	if(pid==0)
	{
	
//	sem_wait(&s1);
	while (1){
		sem_wait(s1);	
//		sem_post(&s2);
		printf("IN child Process\n");
		res = fread((char*)buff,10,1,fp);
		printf("Out child Process %d\n", res);
        	printf("%s\n",buff);
//        wait(&v);
	}   
	}else if(pid>0){
//      		sem_post(&s2); 
       		while(1){
		res = fwrite("RAKESH GP ",10,1,fp);
	 	fflush(fp);
		printf("IN parent Process %d\n", res);
		printf("Out parent Process\n");
		sem_post(s1);
		}
                //exit(1);
	}else {
		perror("fork failed");
	}	
	fclose(fp);
	
}
