#include<stdio.h>
#include<pthread.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
int fd1;
pthread_mutex_t m1;
void *f1(void)
{    
     char ch;
     pthread_mutex_lock(&m1);    
     fd1=open("myfile.txt",O_RDONLY);
     printf("reading the file\n");
     read(fd1,&ch,1);
     printf("reading the file content");
     printf("%c\n",ch);
     pthread_mutex_unlock(&m1);
    
}
/*void *WIFI(void)
{
     pthread_mutex_lock(&m2);    
     fd1=open("myfile",O_RDONLY);
     printf("reading the file\n");
     read(fd1,&ch,1);
     printf("reading the file content");
     pthread_mutex_lock(&m2);    
 }
void *GPS(void)
{
 pthread_mutex_lock(&m3);    
     fd1=open("myfile",O_RDONLY);
     printf("reading the file\n");
     read(fd1,&ch,1);
     printf("reading the file content")
 pthread_mutex_lock(&m3);    
 }*/


 int main()
{
          pthread_mutex_init(&m1,NULL);
         // pthread_mutex_init(&m2,NULL);
         // pthread_mutex_init(&m3,NULL);
          int fd,fd1;
          char ch;
          pid_t pid,pid1;
          pid=fork();
          if(pid<0)
         {
              perror("thread creation failed\n");
         }
         else if(pid==0)
        {
	        while(1)
                {
			
         	   //char ch1[] = "daya";
                   char ch;
                   fd=open("myfile.txt",O_CREAT|O_WRONLY,777);
	           printf("enter the charactor\n");
	           scanf("%c",&ch);
	           write(fd,&ch,4);
                   printf("%c\n",ch);
                   sleep(5);
	         }
       }
else
    {
      pthread_t tid1,tid2,tid3;
      pthread_create(&tid1,NULL,(void *)f1,NULL);
      pthread_create(&tid2,NULL,(void*)f1,NULL);
      pthread_create(&tid3,NULL,(void*)f1,NULL);
    }

}
