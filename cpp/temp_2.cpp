#include <iostream>
using namespace std;
template <class T1, class T2>
void show (T1 a, T2 b) {
	cout << "a = " << a <<endl;
	cout << "b = " << b <<endl;
}
int main() {
	show (5.6, 7);
	show ("RAKESH", 2.7);
	return 0;
}	
