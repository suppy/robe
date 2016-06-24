#pragma once

#ifndef __INTARRAY_H_INCLUDED__
#define __INTARRAY_H_INCLUDED__

class CIntArray
{
	int* m_pnum;
	int m_nNumOf;

public:
	CIntArray(const int nNumOf);
	~CIntArray();
public:
	int Get(const int index);
	void Set(const int index, const int value);
private:
	void CheckIndex(const int index);
};

#endif