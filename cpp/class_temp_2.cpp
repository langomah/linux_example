#include <iostream>
using namespace std;
template <class tum, class sum >

class A{
	private:
		tum a;
		sum b;
	public:
		A(tum x, sum y){
			a = x;
			b = y;
		}
		void show () {
			cout << "a= " << a << endl;
			cout << "b= " << b << endl;
		}
};

int main() {
	A <int, int> a1(3, 4);
	a1.show();
	A <double, int> a2(3.5, 7);
	a2.show();
	A <double, double> a3(3.01, 4.7);
	a3.show();
	A <int, double> a4(2, 4.6);
	a4.show();
	return 0;
}
	
