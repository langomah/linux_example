#include <stdio.h>
#define MSGSIZE 16

main() {
	char *msg1 = "Helloworld";
	char inbuf[MSGSIZE];
	int p[2], j, pid;
	pipe (p);

	pid = fork();
	
	if (pid > 0) {
		write(p[1], msg1, MSGSIZE);
		
	}else { 
		write(p[1], msg1, MSGSIZE);
		for (j = 0; j <= 1; j++) { 
			read(p[0],inbuf, MSGSIZE);
			printf("%s\n", inbuf);
		}
	
	}
	
}
