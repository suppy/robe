#include <iostream>

using namespace std;

class CInt
{
public:
	int m_num;

	CInt();
	void Disp();
};

CInt::CInt()
{
	m_num = 0;
}

void CInt::Disp()
{
	cout << m_num << endl;
}

int main()
{
	CInt a, b, c, d;

	a.Disp();
	b.Disp();
	c.Disp();
	d.Disp();

	return 0;
}