#include <stdio.h>

int main() {
	char x[] = "ff";
	int n = sizeof(x);

//	int n=strlen(x); // where x is pointer to hex string
	unsigned int sum=0;
	int leftshift=0;
	while(n>0)
	{
		if((x[n-1]>='0') && (x[n-1]<='9'))
			sum+=(x[n-1]-'0')<<leftshift;
		if((x[n-1]>='A') && (x[n-1]<='F'))
			sum+=(x[n-1]-'A'+10)<<leftshift;
		if((x[n-1]>='a') && (x[n-1]<='f'))
			sum+=(x[n-1]-'a'+10)<<leftshift;
		n--;
		leftshift+=4;
	}
	printf("%d", sum);

}
