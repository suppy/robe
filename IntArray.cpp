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

	cout << "�R���X�g���N�^���Ă΂�܂����B"
		<< "�v�f���� " << m_nNumOf << " �ł��B" << endl;
}

CIntArray::~CIntArray()
{
	if (m_pnum != NULL)
		delete[] m_pnum;

	cout << "�f�X�g���N�^���Ă΂�܂����B"
		<< "�v�f���� " << m_nNumOf << " �ł����B" << endl;
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

	cout << "�C���f�b�N�X���s���ł��I" << endl
		<< "�l�F" << index << endl;
	exit(1);
}