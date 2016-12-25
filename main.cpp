#include <Windows.h>
#include <iostream>
#include "Proc/RLProc.h"

#define SLEEP_BETWEEN_POLL  (50)
#define SLEEP_BETWEEN_RETRY (3000)

int main()
{
    while (1)
    {
        /* Connect to the game process */
        RLProc p;
        while (p.isAlive())
        {
            /* Grab values and print them */
            std::cout << "Boost: " << p.getBoost();
            std::cout << "  Blue Score: " << p.getBlueScore();
            std::cout << "  Orange Score: " << p.getOrangeScore();
            std::cout << std::endl;
            /* Sleep so we don't flood anything */
            Sleep(SLEEP_BETWEEN_POLL);
        }
        /* If we exited the loop, we had an error reading a value, so try reconnecting to the process after sleep */
        Sleep(SLEEP_BETWEEN_RETRY);
    }
    return 0;
}
