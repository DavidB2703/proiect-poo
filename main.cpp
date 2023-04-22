#include "Meniu.h"

int main()
{
   // Interfata_joc joc;
    //meniu
    Meniu meniu;
        while(meniu.running())
        {
            meniu.update();
            meniu.render();
        }
    return 0;
}

