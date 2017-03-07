#include <stdio.h>
int main() {

	int a = 219, p;

	a = ((a & 0xAA) >> 1 ) | ((a & 0x55) << 1);

	printf("%d", a);

	return 0;
}
