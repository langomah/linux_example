#include <stdio.h>
#include <signal.h>

void abc();

main(){
	printf("press DEL key\n");
	signal(SIGINT, abc);
	getchar();
}

void abc () {
	printf("you have pressed DEL key");
}
