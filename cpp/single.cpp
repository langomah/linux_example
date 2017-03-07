#include <iostream>
#include <cstdlib>
using namespace std;
class single {
	private:
		static int count;
	public:
		single(){
			if (count >= 1){
				cout << "Only one object created" << endl;
				exit(0);

			}
			cout << "First object created" << endl;
			count++;
		}
};

int single ::count = 0;
int main() {
	single s1;
	single s2;
	single s3;
	single s4;
	return 0;
}
