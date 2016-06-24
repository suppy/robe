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
	cout << "名前：" << student.szName << endl
		<< "国語：" << student.nJapanese << " 点, "
		<< "数学：" << student.nMath << " 点, "
		<< "英語：" << student.nEnglish << " 点" << endl;
}

int main()
{
	SStudent students[] = {
		{ "田中", 80, 60, 70, },
		{ "佐藤", 50, 60, 80, },
		{ "鈴木", 70, 80, 100, },
	};

	int i;
	for (i = 0; i < ELEM(students); i++)
		Disp(students[i]);

	return 0;
}