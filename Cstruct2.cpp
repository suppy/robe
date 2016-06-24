#include <iostream>

using namespace std;

class CInt
{
public:
	int m_num;

	CInt();
	CInt(int num);
	void Disp();
};

CInt::CInt() { m_num = 0; }
CInt::CInt(int num) {
	m_num = num;
}

void CInt::Disp()
{
	cout << m_num << endl;
}

int main()
{
	CInt a, b(100), c(40);

	a.Disp();
	b.Disp();
	c.Disp();

	return 0;
}