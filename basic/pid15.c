#include <stdio.h>

main() {
//main() {
//	int i, pid, exitstat, status;
//	printf("Ready to fork\n");
//	pid = fork();
//	if (pid  ==0){
//		sleep(10);
//	//	printf("enter exit stat");	
//	//	scanf("%d", &i);
//		exit(3);
//		
//	} else {
//		wait(&status);
//		if ((status & 0xff) != 0){
//			printf("Signal is interupted\n");
//		} else{
//			exitstat = (int)status /256;
//			printf("Exit status %d was %d\n", pid, exitstat);
//		}
//	}
//}
	int i, j = 0, pid, exitstat, status;
	printf("Ready to fork\n");
	pid = fork();
	if (pid  ==0){
		i = 10/j;
		
	} else {
		wait(&status);
		if ((status & 0x80) != 0){
			printf("Core is dumped\n");
		} else{
			exitstat = (int)status /256;
			printf("Exit status %d was %d\n", pid, exitstat);
		}
	}
}
