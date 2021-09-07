#include <iostream>
#include <cmath>

using namespace std;

// 练习函数重载，求几个数中的最大值
int max1(int x, int y);

int max1(int x, int y, int z);

double max1(double x, double y);

double max1(double x, double y, double z);

int main() {
	int a, b, c;
	double m, n, l;

	cout << "Enter int a:";
	cin >> a;

	cout << "Enter int b:";
	cin >> b;

	cout << "Enter int c:";
	cin >> c;

	cout << "\n";

	cout << "max of " << a << " and " << b << " is " << max1(a, b) << endl;
	cout << "max of " << a << " and " << b << " and " << c << " is " << max1(a, b, c) << endl;

	cout << "\n";

	cout << "Enter double m:";
	cin >> m;

	cout << "Enter double n:";
	cin >> n;

	cout << "Enter double l:";
	cin >> l;

	cout << "\n";

	cout << "max of " << m << " and " << n << " is " << max1(m, n) << endl;
	cout << "max of " << m << " and " << n << " and " << l << " is " << max1(m, n, l) << endl;

}

int max1(int x, int y) {
	if (x >= y) return x;
	else return y;
}

int max1(int x, int y, int z) {
	return max1(max1(x, y), z);
}

double max1(double x, double y) {
	if (abs(x - y) < 1e-10) return x;	// 判断浮点数是否相等的常见办法
	else if (x >= y) return x;
	else return y;
}

double max1(double x, double y, double z) {
	return max1(max1(x, y), z);
}