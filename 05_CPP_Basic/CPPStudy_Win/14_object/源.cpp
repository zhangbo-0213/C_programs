#include "iostream"
using namespace std;
 
#define  PI 3.1415926

class MyCircle {

public:
	double m_r;  //定义成员变量 半径
	double m_s;  //定义成员变量 面积

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
	cout << "输入圆的半径" << endl;
	cin >> r;
	circle.SetR(r);
	cout << "圆的半径" << circle.GetR() << endl<<"圆的面积："<<circle.CalSqure()<<endl;
	system("pause");

	return 0;
}