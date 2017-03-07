#include <iostream>
using namespace std;
class A{
	const int z;
	int x;
	double y;
public:
	A(const int w, int a, double b):z(w) {
		x = a;
		y = b;
	}
	void show ()
	{
		cout << x << " " << y << " " << z << endl;
	}
};

int main() {
	A a[5] = { A(5, 1, 1.1), A(6, 2, 2.2), A(7, 3, 3.3), A(8, 4, 4.4), A(9, 5, 5.5) };
	for (int i = 0; i < 5; i++) {
		a[i].show();
	}
	return 0;

}
