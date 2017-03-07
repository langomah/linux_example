#include <iostream>
using namespace std;

template <class T>

void show (T a, T b) {
	cout << "a= " <<a<<endl;
	cout << "b= " <<b<<endl;
}

int main() {
	show (2, 5);
	show (3.4, 6.7);
	return 0;
}
