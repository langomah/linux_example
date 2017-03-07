#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<string.h>
#define NUM_THREADS 6
char shared_x[100];
pthread_mutex_t lock_x;
pid_t pid,pid1;
char buf1[100],buf2[100],buf3[100];
void *receive1()
	{
	pthread_mutex_lock(&lock_x);
	char ch[100];
	FILE* fp;
	fp = fopen("print.txt","r");
	while(fgets(ch,100,fp)!= NULL )
		{
		if(strstr(ch,"process1"))
			{
			while(fgets(ch,100,fp) && (!strstr(ch,"end1")))
				strcat(buf1,ch);
			}
		}
	fclose(fp);
	pthread_mutex_unlock(&lock_x);
	}

void *receive2()
	{
	pthread_mutex_lock(&lock_x);
	FILE *fp1;
	char ch[100];
	fp1=fopen("print.txt","r");
	printf("thread2 is reading process2 details\n");	
	while(fgets(ch,100,fp1)!= NULL) 
		{
		if((strstr(ch,"process2")))
			{
			while(fgets(ch,100,fp1) != NULL && (!strstr(ch,"end2")))
			strcat(buf2,ch);
			}
		}
	fclose(fp1);
	pthread_mutex_unlock(&lock_x);
	}
void *receive3()
{
	pthread_mutex_lock(&lock_x);
	char ch[100];
	FILE *fp1;
	fp1=fopen("print.txt","r");
	printf("thread3 is reading process3 details\n");
	while((fgets(ch,100,fp1)) != NULL) 
		{
		if((strstr(ch,"process3")))
			{
			while(fgets(ch,100,fp1) != NULL && (!strstr(ch,"end3")))
			strcat(buf3,ch);
			}
		}
	fclose(fp1);
	pthread_mutex_unlock(&lock_x);
	}
void *send1()
	{
	pthread_mutex_lock(&lock_x);
	FILE *fp2;
	fp2=fopen("common.txt","w");
	fprintf(fp2,"%s\n",buf1);
	printf("writing p1 completed\n");
	fclose(fp2);
	pthread_mutex_unlock(&lock_x);
	}
void *send2()
	{
	pthread_mutex_lock(&lock_x);
	FILE *fp3;
	fp3=fopen("common.txt","a");
	fprintf(fp3,"%s\n",buf2);
	printf("writing p2 completed\n");
	fclose(fp3);
	pthread_mutex_unlock(&lock_x);
	}
void *send3()
	{
	pthread_mutex_lock(&lock_x);
	FILE *fp4;
	fp4=fopen("common.txt","a");
	fprintf(fp4,"%s\n",buf3);
	printf("writing p3 completed\n");
	fclose(fp4);
	pthread_mutex_unlock(&lock_x);
	}
int main()
	{
	pthread_t thr[NUM_THREADS];
	int i,rc,itr;
	pthread_mutex_init(&lock_x,NULL);
	pid = fork();
	if (pid==0)
		{
		printf("child process\n");
		printf("pid is %d\n",getpid(pid));
		printf("Child Exited\n");
		}
	else if(pid>0)
		{
		printf("parent process\n");
		printf("ppid is %d\n",getppid(pid));
		pthread_create(&thr[0],NULL,receive1,NULL);
		pthread_create(&thr[1],NULL,receive2,NULL);
		pthread_create(&thr[2],NULL,receive3,NULL);            
                pthread_create(&thr[3],NULL,send1,NULL);
		pthread_create(&thr[4],NULL,send2,NULL);
		pthread_create(&thr[5],NULL,send3,NULL);
		pthread_join(thr[0],NULL);
		pthread_join(thr[1],NULL);
		pthread_join(thr[2],NULL);
		pthread_join(thr[3],NULL);
		pthread_join(thr[4],NULL);
		pthread_join(thr[5],NULL);
		printf("Parent Exited\n");
		}
	else
		{
		return EXIT_SUCCESS;
		}
	return 0;
	}
	






