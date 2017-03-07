#include <iostream>
using namespace std;
template <class T1>
void show (T1 a, int b) {
	cout << "a = " << a <<endl;
	cout << "b = " << b <<endl;
}
int main() {
	show (5.6, 7);
	show ("RAKESH", 2);
	return 0;
}	
