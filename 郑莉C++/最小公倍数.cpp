#include <iostream> 
using namespace std;

class Integer {
private:
	int _num;
public:
	//构造函数 Integer(int num) 
	Integer(int n) {
		_num = n;
	}
	~Integer() { }
	//计算当前Integer 和 b之间的最大公约数 
	int gcd(Integer b) {
		int higher_number;
		int lower_number;
		int max_number;
		int i = 2;
		higher_number = _num;
		lower_number = b._num;
		if (higher_number == 0) {
			return lower_number;
		}
		if (lower_number == 0) {
			return higher_number;
		}
		if (b._num > higher_number) {
			lower_number = higher_number;
			higher_number = b._num;
		}
		max_number = higher_number;
		while (max_number % higher_number + max_number % lower_number > 0) {
			max_number = higher_number * i;
			i += 1;
		}
		return max_number;
	}
};

int main() {
	int a, b;
	cin >> a >> b;
	Integer A(a);
	Integer B(b);
	cout << A.gcd(B) << endl;
	return 0;
}