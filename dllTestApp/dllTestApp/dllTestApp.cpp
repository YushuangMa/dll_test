// dllTestApp.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <windows.h>



int main()
{
	typedef int(*_pAdd)(int a, int b);
	typedef int(*_pSub)(int a, int b);
	HINSTANCE hDll = LoadLibrary(L"crypto.dll");
	int i = 9;
	int j = 6;
	_pAdd pAdd = (_pAdd)GetProcAddress(hDll, "add");
	_pSub pSub = (_pSub)GetProcAddress(hDll, "sub");
	int sAdd = pAdd(i, j);
	int sSub = pSub(i, j);
	std::cout << sAdd << ":" << sSub << std::endl;
	FreeLibrary(hDll);
	system("pause");
    return 0;
}

