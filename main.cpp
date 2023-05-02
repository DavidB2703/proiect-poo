#include "Interfata_joc.h"
#include "Meniu.h"
#include "Tabla.h"
#include "FallingBlocks.h"
#include "GuessTheNumber.h"
int Tabla::ct_tabla=0;
int Tabla::numar_mutari=0;
int FallingBlocks:: numar_inamici=0;
int GuessTheNumber::numGamesPlayed = 0;



int main()
{
    Interfata_joc *MeniuPtr = new Meniu() ;
        while(MeniuPtr->running())
        {
            MeniuPtr->update();
            MeniuPtr->render();
        }
    return 0;
}

