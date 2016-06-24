#include <iostream>
#include "File.h"
#include "TextFile.h"

using namespace std;

int main()
{
	CFile     bin;
	CTextFile txt;
	char      buffer[128];
	int       nRead;

	if (txt.Open("Test.txt", "w") == false)
		return 0;
	txt.WriteString("F‚Í“õ‚Ö‚ÇU‚è‚Ê‚é‚ğ");
	txt.Close();

	if (bin.Open("Test.txt", "r") == false)
		return 0;
	nRead = bin.Read(buffer, sizeof buffer - 1);
	buffer[nRead] = 0;
	cout << buffer << endl;

	return 0;
}