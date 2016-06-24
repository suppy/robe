#pragma once
#ifndef __TEXTFILE_H__INCLUDED__
#define __TEXTFILE_H__INCLUDED__

#include <string.h>
#include "File.h"

class CTextFile : public CFile
{
public:
	int WriteString(const char* pszString);  // ���������������
};

// ���������������
inline int CTextFile::WriteString(const char* pszString)
{
	return Write(pszString, strlen(pszString));
}

#endif