#include <stdio.h>
#define MSGSIZE 16
main() {	
	char *msg1 = "helloworld#1";
	char *msg2 = "helloworld#2";
	char *msg3 = "helloworld#3`";
	char inbuff[MSGSIZE];
	int p[2], j;
	pipe (p);
	write(p[1], msg1, MSGSIZE);
	write(p[1], msg2, MSGSIZE);
	write(p[1], msg3, MSGSIZE);

	for (j = 0;j < 3; j++) {
		read (p[0], inbuff, MSGSIZE);
		printf("%s\n", inbuff);
	}
	exit(0);
}

