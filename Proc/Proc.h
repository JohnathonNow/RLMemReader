#include <Windows.h>
#include <string>
#ifndef PROC_HEADER
#define PROC_HEADER
class Proc
{
    private:
        std::string pname;
        DWORD pid;
        DWORD base;
        HANDLE pHandle;
        bool alive;
        DWORD GetPIDByName();
        DWORD getBaseAddress();
    public:
        Proc(std::string name);
        ~Proc();
        DWORD readInt(const DWORD_PTR addr, const DWORD* offsets, const DWORD n);
        bool isAlive() const;
};
#endif
