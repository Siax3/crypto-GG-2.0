#include "clsCryptoEx.h"
#include <Windows.h>

clsCryptoEx::clsCryptoEx()
{

}

bool clsCryptoEx::OpenFile(LPCWSTR p_chNameSource, LPCWSTR p_chNameDest)
{

	// otevření souboru
	hFile = CreateFile(p_chNameSource, GENERIC_WRITE | GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
	
    // získání velikosti souboru
    GetFileSizeEx(hFile,&pintFileSize);

	// paměťové mapování
	hFileMapping=CreateFileMapping(hFile, NULL, PAGE_READWRITE, 0, 100, NULL);

	// namapování pohledu do souboru
	p_mSourceFirstByte = (PBYTE)MapViewOfFile(hFileMapping, FILE_MAP_COPY, 0, 0, 0);



	return false;
}

bool clsCryptoEx::CloseFile()
{
	// uložení změn
	FlushViewOfFile(p_mSourceFirstByte, 0);
	
	// odmapování
	UnmapViewOfFile(p_mSourceFirstByte);

	// uzavření handles
	CloseHandle(hFileMapping);
	CloseHandle(hFile);
	
	return false;
}

bool clsCryptoEx::Crypt() {
    int shift=3;

    // Přesun na začátek souboru pro zápis
    SetFilePointer(hFile, 0, NULL, FILE_BEGIN);

    for (int i = 0; p_mSourceFirstByte[i] != 0; i++) {
        // Přesun písmena o daný počet míst v abecedě
        p_mSourceFirstByte[i] = (p_mSourceFirstByte[i] + 3) % 256; // Omezení na rozsah 0-255
    }
    // Přesun na začátek souboru pro zápis
    SetFilePointer(hFile, 0, NULL, FILE_BEGIN);

    // Zápis zašifrovaných dat zpět do souboru
    DWORD bytesWritten;
    WriteFile(hFile, p_mSourceFirstByte, pintFileSize.QuadPart, &dwBytesWritten, NULL);



    return true;
}

bool clsCryptoEx::Decrypt() {

    int shift=3;


    // Dešifrování textu pomocí Caesarovy šifry s daným posunutím

    for (int i = 0; p_mSourceFirstByte[i] != 0; i++) {
        // Přesun písmena o daný počet míst v abecedě (opačný směr než při šifrování)
        p_mSourceFirstByte[i] = (p_mSourceFirstByte[i] - 3 + 256) % 256; // Omezení na rozsah 0-255
    }
    // Přesun na začátek souboru pro zápis
    SetFilePointer(hFile, 0, NULL, FILE_BEGIN);

    // Zápis zašifrovaných dat zpět do souboru
    DWORD bytesWritten;
    WriteFile(hFile, p_mSourceFirstByte, pintFileSize.QuadPart, &dwBytesWritten, NULL);


    return true;
}


