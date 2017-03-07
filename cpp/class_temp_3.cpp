#include <iostream>
using namespace std;
template <class tum, int sum >

class A{
	private:
		int a;
		int b;
	public:
		A(){
			a = 5;
			b = sum;
		}
		void show () {
			cout << "a= " << a << endl;
			cout << "b= " << b << endl;
		}
};

int main() {
	A <int, 10> a1;
	a1.show();
	return 0;
}
	
