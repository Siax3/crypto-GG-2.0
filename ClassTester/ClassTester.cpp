#include <iostream>
#include "clsCrypto.h"
#include "clsCryptoEx.h"

int main()
{
    clsCryptoEx* p_lobjCryptoEx;

    // vytvořit objekt
    p_lobjCryptoEx = new clsCryptoEx();

    // otevřít soubor
    p_lobjCryptoEx->OpenFile(L"c:\\Users\\Siax\\Documents\\test.txt", L"c: \\Users\\Siax\\Documents\\testgg.txt");

    // zašifrovat
    p_lobjCryptoEx->Crypt();

    // zavřít soubor
    p_lobjCryptoEx->CloseFile();

    // otevřít soubor
    p_lobjCryptoEx->OpenFile(L"c:\\Users\\Siax\\Documents\\testgg.txt", L"c: \\Users\\Siax\\Documents\\testdecrypt.txt");

    // odšifrovat
    p_lobjCryptoEx->Decrypt();

    // zavřít soubor
    p_lobjCryptoEx->CloseFile();

    // zrušit objekt
    delete(p_lobjCryptoEx);
}
