#include <iostream>
using namespace std;
class A{
	template <class T>
	class B{
		public:
			T var1;
			B(){
			}
			B (T t) {
				var1 = t;
			}
	};
	

	B <int> i1;
	B <char> i2;
	public:
		A(int i, char c){
			i1 = i;
			i2 = c;
		}
		void show () {
			cout << i1.var1 << " " << i2.var1<< endl;
			//cout << "b= " << b << endl;
		}
};

int main() {
	A a1(45, 'R');
	a1.show();
	return 0;
}
	
