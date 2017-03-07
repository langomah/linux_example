#include <stdio.h>

main() {
	int p[2], t;
	t = pipe (p);
	printf("p[0] is %d p[1] is %d t is %d\n", p[0], p[1], t);
}

