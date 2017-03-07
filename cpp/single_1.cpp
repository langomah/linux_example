#include <iostream>
#include <cstdlib>
using namespace std;
class single {
	private:
		static single *objectptr;
	public:
		single(){
		}
		static single * createOneObj() {
			
			if (objectptr == NULL){
				cout << "First instance is created" << endl;
				objectptr = new single();

			}
			return objectptr;
		}
		void print(){
			cout << "I am in singleton class" <<endl;
		}
};


single * single :: objectptr = NULL;
int main() {
	single *s1 = single :: createOneObj();
	single *s2 = s1 -> createOneObj();
	single *s3 = s2 -> createOneObj();
	s1 -> print();
	s2 -> print();
	s3 -> print();
	return 0;
}
