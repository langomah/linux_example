#include <stdio.h>
int main() {
	if (fork()>0){
		printf("parent\n");
		sleep(50);
	}
}

