#include <iostream>
#include <Windows.h>
#include <TlHelp32.h>
#include <tchar.h>

#include "Header.h"

using std::cout;
using std::endl;

DWORD GetModuleBaseAddress(TCHAR* lpszModuleName, DWORD pID) {
	DWORD dwModuleBaseAddress = 0;
	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, pID); // make snapshot of all modules within process
	MODULEENTRY32 ModuleEntry32 = { 0 };
	ModuleEntry32.dwSize = sizeof(MODULEENTRY32);

	if (Module32First(hSnapshot, &ModuleEntry32)) //store first Module in ModuleEntry32
	{
		do {
			if (_tcscmp(ModuleEntry32.szModule, lpszModuleName) == 0) // if Found Module matches Module we look for -> done!
			{
				dwModuleBaseAddress = (DWORD)ModuleEntry32.modBaseAddr;
				break;
			}
		} while (Module32Next(hSnapshot, &ModuleEntry32)); // go through Module entries in Snapshot and store in ModuleEntry32


	}
	cout << "[DEBUG]" << "Finnished Getmodulebaseaddress()" << endl;
	CloseHandle(hSnapshot);
	return dwModuleBaseAddress;
}

int main()
{
	HWND hwnd = FindWindow(NULL, "AssaultCube"); // Get the window handle

	if (hwnd == NULL)
	{
		cout << "[DEBUG]" << "No game opened" << endl;
		return -1;
	}

	DWORD pID = NULL;
	GetWindowThreadProcessId(hwnd, &pID); // Get the process ID

	HANDLE processHandle = NULL;

	processHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pID); // Opens the process for All Access and gets process handle

	cout << "[DEBUG]" << "Procceshandle " << processHandle << endl;

	if (processHandle == NULL)
	{
		cout << "[DEBUG]" << "Failed to open procces";
		return -1;
	}

	TCHAR game_name[] = _T("ac_client");
	DWORD gameBaseAddress = GetModuleBaseAddress(_T(game_name), pID);

	DWORD PlayerHealth = (gameBaseAddress + offsetLocalPlayer) + Player_Health;

	ReadProcessMemory(processHandle, (LPCVOID)PlayerHealth, &PlayerHealth, sizeof(PlayerHealth), NULL);

	cout << "\n";
	cout << "Player Health: " << PlayerHealth << endl;

	return 0;
}