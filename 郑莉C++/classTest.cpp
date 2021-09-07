#include <iostream>
using namespace std;

// 类定义
class Clock {
public:
	Clock(int newH, int newM, int newS);	// 有参构造函数
	Clock();
	void setTime(int newH, int newM, int newS);
	void showTime();
private:
	int hour, minute, second;
};

// 构造函数的实现：
Clock::Clock(int newH, int newM, int newS): hour(newH), minute(newM), second(newS){}
Clock::Clock() : hour(0), minute(0), second(0) {}

// 时钟类成员函数的具体实现
void Clock::setTime(int newH, int newM, int newS) {
	hour = newH;
	minute = newM;
	second = newS;
}

inline void Clock::showTime() {
	cout << hour << ":" << minute << ":" << second << endl;
}

int main() {
	Clock c1(10, 15, 30);
	Clock c2;
	c1.showTime();
	c2.showTime();
	return 0;
}