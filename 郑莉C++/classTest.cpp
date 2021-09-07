#include <iostream>
using namespace std;

// �ඨ��
class Clock {
public:
	Clock(int newH, int newM, int newS);	// �вι��캯��
	Clock();
	void setTime(int newH, int newM, int newS);
	void showTime();
private:
	int hour, minute, second;
};

// ���캯����ʵ�֣�
Clock::Clock(int newH, int newM, int newS): hour(newH), minute(newM), second(newS){}
Clock::Clock() : hour(0), minute(0), second(0) {}

// ʱ�����Ա�����ľ���ʵ��
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