#include "Meniu.h"
#include "Tabla.h"
#include "FallingBlocks.h"
#include "GuessTheNumber.h"
#include "Casuta_Joc.h"
#include "TicTacToe.h"
int Tabla::ct_tabla=0;
int FallingBlocks:: numar_inamici=0;
float Casuta_Joc::x_scale = 300;
float const Meniu::sceneHeigh = 900.f;



int Tabla::numar_mutari=0;
int main()
{
    srand(time(nullptr));
    //creare casute care vor aparea in meniu
    auto* EndlessMaze = new Casuta_Joc("EndlessMaze");
    auto* FallingBlocks = new Casuta_Joc("FallingBlocks");
    auto* GuessTheNumber = new Casuta_Joc("GuessNumber");
    auto* TicTacToe = new Casuta_Joc("TicTacToe");

    Interfata_joc* joc0 = nullptr;
    Interfata_joc* joc1 = nullptr;
    Interfata_joc* joc2 = nullptr;
    Interfata_joc* joc3 = nullptr;


    Meniu& meniu = Meniu::getInstance();
    meniu.addCasuta(EndlessMaze);
    meniu.addCasuta(FallingBlocks);
    meniu.addCasuta(GuessTheNumber);
    meniu.addCasuta(TicTacToe);
    meniu.initializare_casute();

    meniu.addJoc(joc0);
    meniu.addJoc(joc1);
    meniu.addJoc(joc2);
    meniu.addJoc(joc3);

    while(meniu.running())
    {
        meniu.update();
        meniu.render();
    }


}

