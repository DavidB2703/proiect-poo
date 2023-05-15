#include "Meniu.h"
#include "Tabla.h"
#include "EndlessMaze.h"
#include "FallingBlocks.h"
#include "GuessTheNumber.h"
#include "Casuta_Joc.h"

int Tabla::ct_tabla=0;
int FallingBlocks:: numar_inamici=0;
int GuessTheNumber::numGamesPlayed = 0;
float Casuta_Joc::x_scale = 300;
float const Meniu::sceneHeigh = 900.f;
int main()
{
    //creare casute care vor aparea in meniu
    Casuta_Joc EndlessMaze("EndlessMaze");
    Casuta_Joc FallingBlocks("FallingBlocks");
    Casuta_Joc GuessTheNumber("GuessNumber");



    Interfata_joc* joc0;
    Interfata_joc* joc1;
    Interfata_joc* joc2;

    joc0 = new class EndlessMaze();
    joc1 = new class FallingBlocks();
    joc2 = new class GuessTheNumber(10);


    Meniu meniu;

    meniu.addCasuta(&EndlessMaze);
    meniu.addCasuta(&FallingBlocks);
    meniu.addCasuta(&GuessTheNumber);
    meniu.initializare_casute();

    meniu.addJoc(joc0);
    meniu.addJoc(joc1);
    meniu.addJoc(joc2);

    while(meniu.running())
    {
        meniu.update();
        meniu.render();
    }

    meniu.deleteJocuri();

    return 0;
}

