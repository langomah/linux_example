#include <stdio.h>
#include  <fcntl.h>

#define MSGSIZE 16

char *msg1 = "hello";
char *msg2 = "bye";

int main() {
	int pfd[2];
	pipe(pfd);
	fcntl(pfd[0], F_SETFL, O_NDELAY);
	if (fork() == 0) {
		child(pfd);
	} else {
		parent(pfd);
	}
	
}

parent(p)
int p[2];
{
	int nread;
	char buf[MSGSIZE];
	close(p[1]);
	for (;;)
	{
		nread = read(p[0], buf, MSGSIZE);
		if (nread == 0) {
			printf("Pipe empty\n");
			sleep(1);
		}
		else {
			if(strcmp(buf, msg2) ==	0){
				printf("End of converstaion\n");
				exit(0);
			}
			else {
				printf("MSG = %s\n", buf);
			}
		}
	}
}

child(p)
int p[2];
{
	int count;
	close (p[0]);
	for (count = 0; count < 3; count++) {
		write(p[1], msg1, MSGSIZE);
		sleep(3);
	}
	write(p[1], msg2, MSGSIZE);
	exit(0);
}


