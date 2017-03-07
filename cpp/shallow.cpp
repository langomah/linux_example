#include <iostream>
using namespace std;
class code {
	int id;
public:
	void init(int x){
		id = x;
	}
	void display() {
		cout << id << endl;
	}
};

int main() {
	code obj1;
	obj1.init(5);
	obj1.display();
	code obj2 = obj1;
///	obj2.init(6);
	obj1.display();
	obj2.display();
	return 0;
}
	
