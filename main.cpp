//#include <iostream>
//#include <vector>
#include "Joc.h"

int main()
{
        //Initializare Joc
        Joc joc;
        //game loop
        while(joc.running())
        {
           joc.update();
           joc.render();
        }
    return 0;
}

