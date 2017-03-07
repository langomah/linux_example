#include <iostream>
using namespace std;

class smtptr {
	private:
		int *ptr;
	public:
		smtptr(int v) {
			ptr = new int [v];
			int *temp = ptr;
			for (int i = 0; i<= 9; i++) {
				*temp++ = i* i;
			}
		}
		int *operator++ (int) {
			return ptr++;
		}
		int operator *() {
			return *ptr;
		}
};

int main() {
	smtptr s(10);
	for (int i = 0; i <= 9; i++) {
		cout << *s++<<endl;
	}
	return 0;
}

