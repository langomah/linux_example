#include<stdio.h>
#include<unistd.h>
#include<semaphore.h>
#include<sys/types.h>
#include<fcntl.h>
sem_t s,*s1;
char buf[100];
int main()
{
	pid_t pid;
	FILE *fp;
	fp=fopen("1.txt","w+");
	pid=fork();
	s1 = sem_open("/basicsem",O_CREAT,0777,0);
	if(pid<0)
	{
		perror("fork creation failed\n");
	}
	else if(pid==0)
		{
                        while(1)
			{
			
			printf("i am in child\n");
                        //sleep(1);
	     		fprintf(fp,"shaikh\n");
			fflush(fp);
			sem_post(s1);
		       }
		}
         else
	{
		while(1)
		{
		sem_wait(s1);
		printf("i am in parent\n");
                fread(&buf,1,100,fp);
		printf("%s printng in parent buf by read\n",buf);
	        }
         }
}
