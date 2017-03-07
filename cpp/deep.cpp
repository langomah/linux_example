#include <iostream>
#include <cstring>
using namespace std;

class code {
	char *str;
	int id;
public:
	code () {
	}
	void init(int x, char *s){
		id = x;
		str = new char[25];		
		strcpy(str, s);
	}
	void display() {
		cout << id << endl;
		cout << str << endl;
	}
	void change() {
		str[0] = 'k';
	}
	code (code &c) {
		id = c.id;
		str = new char[25];
		strcpy (str, c.str);
	}
};

int main() {
	code obj1;
	obj1.init(5, "Rakesh");
	obj1.display();
	code obj2 = obj1;
///	obj2.init(6);
	obj2.display();	
	obj1.change();
	obj1.display();

	obj2.display();
	return 0;
}
	
