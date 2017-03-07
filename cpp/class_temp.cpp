#include <iostream>
using namespace std;
template <class T>

class A{
	private:
		T a, b;
	public:
		A(T x, T y){
			a = x;
			b = y;
		}
		void show () {
			cout << "a= " << a << endl;
			cout << "b= " << b << endl;
		}
};

int main() {
	A <int> a1(3, 4);
	a1.show();
	A <double> a2(2.3, 4.6);
	a2.show();
	return 0;
}
	
