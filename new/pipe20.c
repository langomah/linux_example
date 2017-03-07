#include <stdio.h>

#define MSG 16

int main() {
	char *msg1 = "hello world#1";
	char inbuf[MSG];
	int p[2], j, pid;
	pipe(p);
	pid = fork ();
	if (pid > 0)
	{
		write (p[1], msg1, MSG);
	}
	else {
		printf("%d\n",lseek(p[0], 0L, 2));
		read(p[0], inbuf, MSG);
		printf("%s\n", inbuf);
	}
	exit(0);
}

