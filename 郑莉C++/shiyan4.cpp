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
		cout << "������һ��CPU��" << endl;
	}

	CPU(CPU& c) {
		rank = c.rank;
		frequency = c.frequency;
		voltage = c.voltage;

		cout << "����������һ��CPU��" << endl;
	}

	~CPU() {
		cout << "������һ��CPU��" << endl;
	}

	CPU_Rank GetRank() const { return rank; }
	int GetFrequency() const { return frequency; }
	float GetVoltage() const { return voltage; }

	void SetRank(CPU_Rank r) { rank = r; }
	void SetFrequency(int f) { frequency = f; }
	void SetVoltage(float v) { voltage = v; }

	void Run() { cout << "CPU��ʼ���У�" << endl; }
	void Stop() { cout << "CPUֹͣ���У�" << endl; }
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
		cout << "������һ��RAM��" << endl;
	}

	~RAM() {
		cout << "������һ��RAM��" << endl;
	}

	int GetSize() const { return size; }
	RAM_Type GetType() const { return type; }
	float GetFrequency() const { return frequency; }

	void SetSize(int s) { size = s; }
	void SetType(RAM_Type t) { type = t; }
	void SetFrequency(int f) { frequency = f; }

	void Run() { cout << "RAM��ʼ���У�" << endl; }
	void Stop() { cout << "RAMֹͣ���У�" << endl; }
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
		cout << "������һ��CDROM��" << endl;
	}

	~CDROM() {
		cout << "������һ��CDROM��" << endl;
	}

	CDROM_Interface GetInterface() const { return interface_type; }
	CDROM_Install_type GetInstallType() const { return install_type; }

	void SetInterface(CDROM_Interface i) { interface_type = i; }
	void SetInstallType(CDROM_Install_type it) { install_type = it; }

	void Run() { cout << "CDROM��ʼ���У�" << endl; }
	void Stop() { cout << "CDROMֹͣ���У�" << endl; }
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
	~COMPUTER() { cout << "������һ��COMPUTER��" << endl; }

	void Run() {
		my_cpu.Run();
		my_ram.Run();
		my_cdrom.Run();
		cout << "COMPUTER��ʼ���У�" << endl;
	}

	void Stop() {
		my_cpu.Stop();
		my_ram.Stop();
		my_cdrom.Stop();
		cout << "COMPUTERֹͣ���У�" << endl;
	}
};

// COMPUTER���캯��д�����棬Ҫ�����ʶ����
// �򵥸�ֱֵ����:my_cpu(c)���ֿ�������ķ�ʽ
COMPUTER::COMPUTER(CPU c, RAM r, CDROM cd, int s, int b) :my_cpu(c), my_ram(r), my_cdrom(cd) {
	storage_size = s;
	bandwidth = b;

	cout << "������һ��COMPUTER��" << endl;

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