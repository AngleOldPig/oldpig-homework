#include <iostream>
#include <string>
#include <sstream>
using namespace std;


bool isTriangle(int a, int b, int c) {
	if ( a * a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a) return true;
	else return false;
}

int main() {
	int a, b, c;
	string line;

	while (getline(cin, line)) {
		stringstream ss(line);
		ss >> a >> b >> c;
		if (isTriangle(a, b, c)) {
			cout << "True" << endl;
		}
		else {
			cout << "False" << endl;
		}
	}

	return 0;
}