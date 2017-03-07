#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include<semaphore.h>

//void *thread_write(void *arg);
void *thread_function(void *arg);
int run_now = 1;
char message[10];
sem_t s1;
sem_t s2;


int main() {
	int res;
	pthread_t a_thread;
	FILE *fp = fopen("source.txt", "r");
	//res = pthread_mutex_init(&work_mutex, NULL);
	int print_count1 = 0;

	res = pthread_create(&a_thread, NULL, thread_function, NULL);
	res = sem_init(&s1, 0, 0);
	res = sem_init(&s2, 0, 0);
	//res = pthread_create(&a_thread_1, NULL, thread_read, NULL);
	run_now = 1;

	while(print_count1++ < 10) {
		

		//if (run_now == 1) {
			fread(message, 5, 1, fp);
			fflush(fp);//to clear buffer no need here
			sem_post(&s1);
			sem_wait(&s2);
			printf("1");
			
			//run_now = 2;
                  //     }
	}	
	printf("Waiting for thread to finish...\n");
	res = pthread_join(a_thread, NULL);
//	res = pthread_join(a_thread_1, NULL);
	if (res != 0) {
		perror("Thread join failed");
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}

void *thread_function(void *arg) {
	
      
	int print_count2 = 0;
	FILE *fp2 = fopen("desti.txt", "w");
	//char buff;
	run_now =2;
       
//       sem_wait(&s1);
	
	while(print_count2++ < 10) {
		
		//if (run_now == 2) {
			sem_wait(&s1);
			
			fwrite((char *)message, 5, 1, fp2);
			fflush(fp2);
			printf("2");
			sem_post(&s2);
			//run_now = 1;
		//}

	}
     
fclose(fp2);
	pthread_exit(NULL);
} 

