#include "RLProc.h"
using namespace RL;
RLProc::RLProc() : Proc(PROC_NAME) {}

DWORD RLProc::getBoost()
{
    return readInt(BOOST_ADDRESS, BOOST_OFFSETS, BOOST_OFFSET_COUNT);
}
DWORD RLProc::getOrangeScore()
{
    return readInt(ORNGSCORE_ADDRESS, ORNGSCORE_OFFSETS, ORNGSCORE_OFFSET_COUNT);
}
DWORD RLProc::getBlueScore()
{
    return readInt(BLUESCORE_ADDRESS, BLUESCORE_OFFSETS, BLUESCORE_OFFSET_COUNT);
}
