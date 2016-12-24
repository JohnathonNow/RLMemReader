#include <Windows.h>
#include <iostream>
#include "Proc.h"

#define GAME ("RocketLeague.exe")

#define BOOST_ADDRESS (0x01666AE8)
#define BOOST_OFFSETS {0x108, 0x4e4, 0x3c0, 0x534, 0x54}
#define BOOST_OFFSET_COUNT (5)

#define BLUESCORE_ADDRESS (0x0166AB44)
#define BLUESCORE_OFFSETS {0x7c, 0x48, 0x398, 0x0, 0x4c}
#define BLUESCORE_OFFSET_COUNT (5)

#define ORNGSCORE_ADDRESS (0x0166AB44)
#define ORNGSCORE_OFFSETS {0x7C, 0x48, 0x398, 0x10, 0x4c}
#define ORNGSCORE_OFFSET_COUNT (5)

#define SLEEP_BETWEEN_BOOST (50)
#define SLEEP_BETWEEN_RETRY (3000)

int main()
{
    /* Make offset arrays */
    DWORD boost_offsets[BOOST_OFFSET_COUNT] = BOOST_OFFSETS;
    DWORD bluescore_offsets[BLUESCORE_OFFSET_COUNT] = BLUESCORE_OFFSETS;
    DWORD orngscore_offsets[ORNGSCORE_OFFSET_COUNT] = ORNGSCORE_OFFSETS;
    while (1)
    {
        /* Connect to the game process */
        Proc p(GAME);
        while (p.isAlive())
        {
            /* Grab values and print them */
            std::cout << "Boost: " << p.readInt(BOOST_ADDRESS, boost_offsets, BOOST_OFFSET_COUNT);
            std::cout << "  Blue Score: " << p.readInt(BLUESCORE_ADDRESS, bluescore_offsets, BLUESCORE_OFFSET_COUNT);
            std::cout << "  Orange Score: " << p.readInt(ORNGSCORE_ADDRESS, orngscore_offsets, ORNGSCORE_OFFSET_COUNT);
            std::cout << std::endl;
            /* Sleep so we don't flood anything */
            Sleep(SLEEP_BETWEEN_BOOST);
        }
        /* If we exited the loop, we had an error reading a value, so try reconnecting to the process after sleep */
        Sleep(SLEEP_BETWEEN_RETRY);
    }
    return 0;
}
