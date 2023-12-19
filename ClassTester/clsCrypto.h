#pragma once
#include <string.h>
#include "stdio.h"
#include "clsProtoCrypto.h";
#define Crypter -10

class clsCrypto: public clsProtoCrypto // t��da clsCrypto d�d� funkce z t��dy clsProtoCrypto
{
public:
	clsCrypto();						// konstruktor
	bool OpenFile(const char* p_chNameSource, const char* p_chNameDest);		// otev��t soubor
	bool CloseFile();					// zav�e soubor
	bool Crypt();						// �ifruje
	bool Decrypt();						// de�ifruje

private:
	char* p_mchFileNameSource; // n�zev souboru odkud
	FILE* p_mFileSource;
	char* p_mchFileNameDest; // n�zev souboru c�le
	FILE* p_mFileDest;
};


