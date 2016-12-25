#include <Windows.h>
#include <string>
#include "Proc.h"
#ifndef RLPROC_HEADER
#define RLPROC_HEADER
class RLProc: public Proc
{
    public:
        RLProc();
        DWORD getBoost();
        DWORD getOrangeScore();
        DWORD getBlueScore();
};
namespace RL
{
    const std::string PROC_NAME = "RocketLeague.exe";
    const DWORD BOOST_ADDRESS = (0x01666AE8);
    const DWORD BOOST_OFFSETS[] = {0x108, 0x4e4, 0x3c0, 0x534, 0x54};
    const DWORD BOOST_OFFSET_COUNT = (5);

    const DWORD BLUESCORE_ADDRESS = (0x0166AB44);
    const DWORD BLUESCORE_OFFSETS[] = {0x7c, 0x48, 0x398, 0x0, 0x4c};
    const DWORD BLUESCORE_OFFSET_COUNT = (5);

    const DWORD ORNGSCORE_ADDRESS = (0x0166AB44);
    const DWORD ORNGSCORE_OFFSETS[] = {0x7C, 0x48, 0x398, 0x10, 0x4c};
    const DWORD ORNGSCORE_OFFSET_COUNT = (5);

    const DWORD SPEED_ADDRESS = (0x01677934);
    const DWORD SPEED_OFFSETS[] = {0x140, 0x7a8, 0x75c, 0x6f8, 0xd8};
    const DWORD SPEED_OFFSET_COUNT = (5);
}
#endif
