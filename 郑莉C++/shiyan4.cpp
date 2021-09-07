#include <iostream>
using namespace std;

enum CPU_Rank { P1 = 1, P2, P3, P4, P5, P6, P7 };
class CPU {
private:
	CPU_Rank rank;
	int frequency;
	float voltage;
public:
	CPU(CPU_Rank r, int f, float v) {
		rank = r;
		frequency = f;
		voltage = v;
		cout << "构造了一个CPU！" << endl;
	}

	CPU(CPU& c) {
		rank = c.rank;
		frequency = c.frequency;
		voltage = c.voltage;

		cout << "拷贝构造了一个CPU！" << endl;
	}

	~CPU() {
		cout << "析构了一个CPU！" << endl;
	}

	CPU_Rank GetRank() const { return rank; }
	int GetFrequency() const { return frequency; }
	float GetVoltage() const { return voltage; }

	void SetRank(CPU_Rank r) { rank = r; }
	void SetFrequency(int f) { frequency = f; }
	void SetVoltage(float v) { voltage = v; }

	void Run() { cout << "CPU开始运行！" << endl; }
	void Stop() { cout << "CPU停止运行！" << endl; }
};

enum RAM_Type { DDR1 = 1, DDR2, DDR3, DDR4, DDR5 };
class RAM {
private:
	int size;
	RAM_Type type;
	int frequency;
public:
	RAM(int s, RAM_Type t, int f) {
		size = s;
		type = t;
		frequency = f;
		cout << "构造了一个RAM！" << endl;
	}

	~RAM() {
		cout << "析构了一个RAM！" << endl;
	}

	int GetSize() const { return size; }
	RAM_Type GetType() const { return type; }
	float GetFrequency() const { return frequency; }

	void SetSize(int s) { size = s; }
	void SetType(RAM_Type t) { type = t; }
	void SetFrequency(int f) { frequency = f; }

	void Run() { cout << "RAM开始运行！" << endl; }
	void Stop() { cout << "RAM停止运行！" << endl; }
};

enum CDROM_Interface { SATA, USB };
enum CDROM_Install_type { external, built_in };
class CDROM {
private:
	CDROM_Interface interface_type;
	CDROM_Install_type install_type;
public:
	CDROM(CDROM_Interface i, CDROM_Install_type it) {
		interface_type = i;
		install_type = it;
		cout << "构造了一个CDROM！" << endl;
	}

	~CDROM() {
		cout << "析构了一个CDROM！" << endl;
	}

	CDROM_Interface GetInterface() const { return interface_type; }
	CDROM_Install_type GetInstallType() const { return install_type; }

	void SetInterface(CDROM_Interface i) { interface_type = i; }
	void SetInstallType(CDROM_Install_type it) { install_type = it; }

	void Run() { cout << "CDROM开始运行！" << endl; }
	void Stop() { cout << "CDROM停止运行！" << endl; }
};

class COMPUTER {
private:
	CPU	my_cpu;
	RAM my_ram;
	CDROM my_cdrom;
	int storage_size;
	int bandwidth;
public:
	COMPUTER(CPU c, RAM r, CDROM cd, int s, int b);
	~COMPUTER() { cout << "析构了一个COMPUTER！" << endl; }

	void Run() {
		my_cpu.Run();
		my_ram.Run();
		my_cdrom.Run();
		cout << "COMPUTER开始运行！" << endl;
	}

	void Stop() {
		my_cpu.Stop();
		my_ram.Stop();
		my_cdrom.Stop();
		cout << "COMPUTER停止运行！" << endl;
	}
};

// COMPUTER构造函数写在外面，要加类标识符。
// 简单赋值直接用:my_cpu(c)这种拷贝构造的方式
COMPUTER::COMPUTER(CPU c, RAM r, CDROM cd, int s, int b) :my_cpu(c), my_ram(r), my_cdrom(cd) {
	storage_size = s;
	bandwidth = b;

	cout << "构造了一个COMPUTER！" << endl;

}

int main() {
	CPU a(P6, 300, 8);
	a.Run();
	a.Stop();
	cout << "**************************\n";

	RAM b(8, DDR3, 1600);
	b.Run();
	b.Stop();
	cout << "**************************\n";

	CDROM c(SATA, built_in);
	c.Run();
	c.Stop();
	cout << "**************************\n";

	COMPUTER my_computer(a, b, c, 128, 10);
	cout << "**************************\n";

	return 0;
}