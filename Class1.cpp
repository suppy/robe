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
};

void Disp(const SStudent& student)
{
	cout << "���O�F" << student.szName << endl
		<< "����F" << student.nJapanese << " �_, "
		<< "���w�F" << student.nMath << " �_, "
		<< "�p��F" << student.nEnglish << " �_" << endl;
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
		Disp(students[i]);

	return 0;
}