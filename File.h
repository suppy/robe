#pragma once
#ifndef __FILE_H_INCLUDED__
#define __FILE_H_INCLUDED__

//#include <stdio.h>

class CFile
{
private:
	FILE* m_pfile;
	bool m_bCopy;

public:
	CFile();
	CFile(const CFile& rother);
	~CFile();

public:
	bool Open(const char* pszFile, const char* pszFlags);
	void Close();

private:
	bool ModifyFlags(const char* pszSource, char* pszDest, int nSize);

public:
	size_t Read(void* pData, size_t nSize);
	size_t Write(const void*pData, size_t nSize);

public:
	bool IsValid() const;
	bool Eof();
};

// m_pfile ‚Ì’l‚ª—LŒø‚©‚Ç‚¤‚©
inline bool CFile::IsValid() const
{
	return (m_pfile != NULL);
}

#endif
