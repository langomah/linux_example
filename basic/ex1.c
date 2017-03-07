#include <stdio.h>
#define MAX 10
int arr[MAX];
int top = -1;
void push (int data) {
	if (top == MAX-1){
		printf("Stack is full");
	}
	else {
		top = top + 1;
		arr[top] = data;
	}

}
int pop (){
	int res = 0;
	if (top == -1) {
		printf("Stack is empty");
		return -1;
	}

	res = arr[top];
	top = top -1;
	return res;
}
		
void display(){
	int i = 0;
	if (top == -1) {
		printf("Stack is empty");
		//return -1;
	}
	else {
		for (i = 0;i <= top; i++){
			printf("%d\n", arr[i]);
		}
	}
}

int main() {
	int data, pop_data;
	char choice;
	
	printf("Enter the choice\n");
	choice = getchar();
//	scanf("%c", &choice);
	while (choice < '4') {
		switch (choice) {
			case '1':
				printf("Enter the data\n");
				scanf("%d", &data);
				push (data);
				break;
			case '2':
				pop_data = pop();
				printf("popped data is %d",pop_data);
				break;
			case '3':
				display();
				break;
		//	default:
		//		printf("Invalid statement");
				//exit(0);
		}
	printf("Enter the choice\n");
	choice = getchar();
	//scanf("%c", &choice);
	}
	return 0;
}	
