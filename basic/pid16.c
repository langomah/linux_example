#include <stdio.h>

main() {
	int pid, i = 1;
	for (;;){
		pid = fork();
		if (pid <0){
			printf("Max concurr process are %d\n", i);
		} else if (pid ==0) {
			i++;
		}else {
			wait(0);
			exit(0);
		}
	}
}

		
