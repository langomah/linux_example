#include <iostream>
using namespace std;
template <class T1>
void show (T1 a) {
	cout << "a = " << a <<endl;
//	cout << "b = " << b <<endl;
}
void show (int a) {
	cout << "a = " << a <<endl;
//	cout << "b = " << b <<endl;
}
int main() {
	show (5.6);
	show ( 2);
	return 0;
}	
