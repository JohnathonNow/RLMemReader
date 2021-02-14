#include <Windows.h>
#include <TlHelp32.h>
#include <Psapi.h>
#include <string>
#include "Proc.h"
Proc::Proc(std::string name)
{
    pname = name;
    pid = GetPIDByName();
    pHandle = OpenProcess(PROCESS_ALL_ACCESS ,0, pid);
    base = getBaseAddress();
    alive = pHandle;
}
Proc::~Proc()
{
    CloseHandle(pHandle);
}
DWORD Proc::GetPIDByName()
{
    PROCESSENTRY32 entry;
    entry.dwSize = sizeof(PROCESSENTRY32);

    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

    if (Process32First(snapshot, &entry) == TRUE)
    {
        while (Process32Next(snapshot, &entry) == TRUE)
        {
            std::string a(entry.szExeFile);
            std::string b(pname);
            if (a == b)
            {
                CloseHandle(snapshot);
                return entry.th32ProcessID;
            }
        }
    }
    CloseHandle(snapshot);
    return 0;
}
DWORD Proc::getBaseAddress()
{
    HMODULE hMods[1024];
    DWORD cbNeeded;
    unsigned int i;
    if (EnumProcessModules(pHandle, hMods, sizeof(hMods), &cbNeeded))
        {
        for (i = 0; i < (cbNeeded / sizeof(HMODULE)); i++)
        {
            char szModName[MAX_PATH];
            if (GetModuleFileNameEx(pHandle, hMods[i], szModName, sizeof(szModName) / sizeof(TCHAR)))
            {
                std::string wstrModName(szModName);
                std::string wstrModContain(pname);
                if (wstrModName.find(wstrModContain) != std::string::npos)
                {
                    return (DWORD_PTR)hMods[i];
                }
            }
        }
    }
    return 0;
}
DWORD Proc::readInt(const DWORD_PTR addr, const DWORD* offsets, const DWORD n)
{
    DWORD_PTR address = base + addr;
    DWORD value = 0;
    for (DWORD i = 0; i < n; i++)
    {
        ReadProcessMemory(pHandle, (LPCVOID)address, &value, sizeof(DWORD), NULL);
        address = value + offsets[i];
    }
    if (!ReadProcessMemory(pHandle, (LPCVOID)address, &value, sizeof(DWORD), NULL))
    {
        alive = false;
    }
    return value;
}
bool Proc::isAlive() const
{
    return alive;
}
