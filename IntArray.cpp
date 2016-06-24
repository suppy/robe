#include <iostream>
#include <memory>
#include "IntArray.h"

using namespace std;

CIntArray::CIntArray(const int nNumOf)
{
	m_pnum = new int[nNumOf];
	if (m_pnum == NULL)
		m_nNumOf = 0;
	else {
		m_nNumOf = nNumOf;
		memset(m_pnum, 0, nNumOf * sizeof *m_pnum);
	}

	cout << "コンストラクタが呼ばれました。"
		<< "要素数は " << m_nNumOf << " です。" << endl;
}

CIntArray::~CIntArray()
{
	if (m_pnum != NULL)
		delete[] m_pnum;

	cout << "デストラクタが呼ばれました。"
		<< "要素数は " << m_nNumOf << " でした。" << endl;
}

int CIntArray::Get(const int index)
{
	CheckIndex(index);
	return m_pnum[index];
}

void CIntArray::Set(const int index, const int value)
{
	CheckIndex(index);
	m_pnum[index] = value;
}

void CIntArray::CheckIndex(const int index)
{
	if ((unsigned int)index < (unsigned int)m_nNumOf)
		return;

	cout << "インデックスが不正です！" << endl
		<< "値：" << index << endl;
	exit(1);
}