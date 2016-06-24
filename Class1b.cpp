#include <iostream>

using namespace std;

#define ELEM(array)	(sizeof (array) / sizeof *(array))

class SStudent
{
public:
	char szName[16];
	int nJapanese;
	int nMath;
	int nEnglish;

	void Disp();
};

void SStudent::Disp()
{
	cout << "���O�F" << szName << endl
		<< "����F" << nJapanese << " �_, "
		<< "���w�F" << nMath << " �_, "
		<< "�p��F" << nEnglish << " �_" << endl;
}

int main()
{
	SStudent students[] = {
		{ "�c��", 80, 60, 70, },
		{ "����", 50, 60, 80, },
		{ "���", 70, 80, 100, },
	};

	int i;
	for (i = 0; i < ELEM(students); i++)
		students[i].Disp();

	return 0;
}