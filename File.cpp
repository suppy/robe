#include <stdio.h>
#include <string.h>
#include "MainDefs.h"
#include "File.h"

// �R���X�g���N�^
CFile::CFile()
{
	m_pfile = NULL;
	m_bCopy = false;
}

// �R�s�[�R���X�g���N�^
CFile::CFile(const CFile& rother)
{
	m_pfile = rother.m_pfile;
	m_bCopy = true;
}

// �f�X�g���N�^
CFile::~CFile()
{
	if (m_bCopy == false)
		Close();
}

// �t�@�C�����J��
bool CFile::Open(const char* pszFile, const char* pszFlags)
{
	Close();

	char bufFlags[8];
	if (ModifyFlags(pszFlags, bufFlags, numof(bufFlags)) == false)
		return false;

	fopen_s(&m_pfile, pszFile, bufFlags);
	return (m_pfile != NULL);
}

// �t�@�C�������
void CFile::Close()
{
	if (IsValid() == true)
	{
		fclose(m_pfile);
		m_pfile = 0;
	}
}

// �t���O�̒���
bool CFile::ModifyFlags(const char* pszSource, char* pszDest, int nSize)
{
	bool bBinary;  // 'b' �̎w�肪���邩�ǂ���

				   // strchr �́A�w�肵�����������߂ɏo�Ă���ʒu��Ԃ��֐��ł�
				   // �����P�ɕ������܂܂�Ă��邩�ǂ������m�F����̂ɂ��g���܂�
	bBinary = (strchr(pszSource, 'b') != NULL);

	// �t���O����������Ƃ��� false ��Ԃ�
	if ((int)strlen(pszSource) > nSize - 1 - !bBinary)
		return false;

	// �����I�Ƀo�C�i�����[�h�ŊJ���܂�
	// strcpy �͕�������R�s�[����֐��Astrcat �͕������ǉ�����֐��ł�
	strcpy_s(pszDest, nSize, pszSource);
	if (bBinary == false)
		strcat_s(pszDest, nSize, "b");
	return true;
}

// �t�@�C������ǂݏo��
size_t CFile::Read(void* pData, size_t nSize)
{
	if (IsValid() == false)
		return 0;
	return fread(pData, 1, nSize, m_pfile);
}

// �t�@�C���ɏ�������
size_t CFile::Write(const void* pData, size_t nSize)
{
	if (IsValid() == false)
		return 0;
	return fwrite(pData, 1, nSize, m_pfile);
}

// �t�@�C���̏I�[�ɒB�������ǂ���
bool CFile::Eof()
{
	if (IsValid() == false)
		return true;
	return (feof(m_pfile) != 0);
}