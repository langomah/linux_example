#include <iostream>
using namespace std;

class sample{
	public: 
		void func() {
			cout << "smart pointer" << endl;
		}
};

class smtptr {
	sample s;
	public :
		sample *operator->(){
			return &s;
		}
};

int main() {
	smtptr s;
	s -> func();
	return 0;
}
