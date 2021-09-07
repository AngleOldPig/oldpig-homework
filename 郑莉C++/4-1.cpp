#include <iostream> 
using namespace std; 

class Integer { 
private: 
	int _num; 
public: 
	//���캯�� Integer(int num) 
	Integer(int n) {
		_num = n;
	}
	~Integer() { }
	//���㵱ǰInteger �� b֮������Լ�� 
	int gcd(Integer b) { 
		int higher_number;
		int lower_number;
		int max_number;
		int i = 2;
		higher_number = _num;
		lower_number = b._num;
		if (higher_number == 0) {
			return 0;
		}
		if (lower_number == 0) {
			return 0;
		}
		if (higher_number == 1) {
			return 1;
		}
		if (lower_number == 1) {
			return 1;
		}
		if (b._num>higher_number){
			lower_number = higher_number;
			higher_number = b._num;
		}
		max_number = lower_number;
		while (higher_number % max_number > 0) {
			if (lower_number % i == 0) {
				max_number = lower_number / i;
			}
			i += 1;
		}
		return max_number;
	} 
}; 

int main(){ 
	int a, b; 
	cin >> a >> b; 
	Integer A(a); 
	Integer B(b); 
	cout << A.gcd(B) << endl; 
	return 0; 
}