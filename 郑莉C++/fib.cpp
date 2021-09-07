#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int fib(int n);	// ����������ڵ���֮��Ļ���Ҫ�ڵ���֮ǰ��������

int main() {
	int n, answer;
	string line;
	while (getline(cin, line)) {
		stringstream ss(line);
		ss >> n;
		cout << fib(n) << endl;
	}
	return 0;
}

int fib(int n) {
	if (n < 2) {
		return (1);
	}
	else {
		return (fib(n - 2) + fib(n - 1));
	}
}