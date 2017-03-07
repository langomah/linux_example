#include <stdio.h>
main(){
	long i;
	printf("process ID is %d\n",getpid());
	for (i = 0;i<=4000000;i++);
	printf("I is %ld\n", i);
//	return 0;
} 
