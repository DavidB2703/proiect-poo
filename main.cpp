#include "Meniu.h"
#include "Tabla.h"
#include "EndlessMaze.h"
#include "FallingBlocks.h"
#include "GuessTheNumber.h"
#include "Casuta_Joc.h"

int Tabla::ct_tabla=0;
int FallingBlocks:: numar_inamici=0;
int GuessTheNumber::numGamesPlayed = 0;
int Tabla::numar_mutari=0;
float Casuta_Joc::x_scale = 300;
float const Meniu::sceneHeigh = 900.f;
int main()
{

    Casuta_Joc EndlessMaze("EndlessMaze");
    Casuta_Joc FallingBlocks("FallingBlocks");
    Casuta_Joc GuessTheNumber("GuessNumber");


    std::vector<Casuta_Joc> casute;

    casute.emplace_back(EndlessMaze);
    casute.emplace_back(FallingBlocks);
    casute.emplace_back(GuessTheNumber);
    std::vector<Interfata_joc*> jocuri;
    jocuri.resize(casute.size());
    jocuri[0] = new class EndlessMaze();
    jocuri[1] = new class FallingBlocks();
    jocuri[2] = new class GuessTheNumber(10);



    float y_scale = 225;
    for (auto & casuta : casute)
    {
        casuta.initializare_variabile(y_scale);
        y_scale+=120;
    }



    Meniu meniu ;

    while(meniu.running())
    {
        meniu.update(casute, jocuri);
        meniu.render(casute);
    }

    for (auto & joc : jocuri)
        delete joc;

    return 0;
}

