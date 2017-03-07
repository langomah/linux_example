#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>
void *thread_function(void *arg);

pthread_mutex_t work_mutex; /* protects both work_area and time_to_exit */

#define WORK_SIZE 1024

char work_area[WORK_SIZE];

int time_to_exit = 0;

int main() {
	int res;
	pthread_t a_thread;
	void *thread_result;
	res = pthread_mutex_init(&work_mutex, NULL);
	if (res != 0) {
		perror(“Mutex initialization failed”);
		exit(EXIT_FAILURE);
	}
	res = pthread_create(&a_thread, NULL, thread_function, NULL);
	if (res != 0) {
		perror(“Thread creation failed”);
		exit(EXIT_FAILURE);
	}
	pthread_mutex_lock(&work_mutex);
	printf(“Input some text. Enter ‘end’ to finish\n”);
	while(!time_to_exit) {
		fgets(work_area, WORK_SIZE, stdin);
		pthread_mutex_unlock(&work_mutex);
	while(1) {
		pthread_mutex_lock(&work_mutex);
		if (work_area[0] != ‘\0’) {
			pthread_mutex_unlock(&work_mutex);
			sleep(1);
		}
		else {
			break;
		}

