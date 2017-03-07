#include <stdio.h>

main() {
	int i, pid, exitstat, status;
	printf("Ready to fork\n");
	pid = fork();
	if (pid  ==0){
		//sleep(10);
		printf("enter exit stat");	
		scanf("%d", &i);
		exit(i);
		
	} else {
		wait(&status);
		if ((status & 0xff) != 0){
			printf("Signal is interupted\n");
		} else{
			exitstat = (int)status /256;
			printf("Exit status %d was %d\n", pid, exitstat);
		}
	}
}
