#include "iostream"
using namespace std;
 
#define  PI 3.1415926

class MyCircle {

public:
	double m_r;  //�����Ա���� �뾶
	double m_s;  //�����Ա���� ���

public:
	void SetR(double r) {
		m_r = r;
	}

	double GetR() {
		return m_r;
	}

	double CalSqure() {
		return PI * m_r*m_r;
	}

};

int main() {

	MyCircle circle;
	double r;
	cout << "����Բ�İ뾶" << endl;
	cin >> r;
	circle.SetR(r);
	cout << "Բ�İ뾶" << circle.GetR() << endl<<"Բ�������"<<circle.CalSqure()<<endl;
	system("pause");

	return 0;
}