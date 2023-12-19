#pragma once

class clsProtoCrypto // abstraktn� t��da - nelze z n� ud�lat instanci
{
public:
	clsProtoCrypto() {};						// konstruktor // u abstraktn�ho konstruktoru nelze napsat =0
	bool OpenFile(const char* p_chNameSource, const char* p_chNameDest) { return false;  };	// =0, ukazuje abstraktn� t��du - nen� to re�ln� objekt
	virtual bool CloseFile() = 0;					// zav�e soubor
	virtual bool Crypt() = 0;						// �ifruje
	virtual bool Decrypt() = 0;						// de�ifruje
};