#include<iostream>
#include <stdio.h>
using namespace std;

extern "C" {
	void fun();
}

int main() {

	fun();
	return 0;
}

void fun(){
	printf("RAKESH");
}

