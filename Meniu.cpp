//
// Created by david on 4/15/2023.
//
#include <cstring>
#include "Meniu.h"
#include "EndlessMaze.h"
#include "Interfata_joc.h"
#include "FallingBlocks.h"
#include "GuessTheNumber.h"
#include "Casuta_Joc.h"
///functii private
void Meniu::initializare_text() {

    font.loadFromFile(R"(arial.ttf)");
    titlu.setString("Choose your game!");
    titlu.setFont(font);
    titlu.setCharacterSize(24);
    titlu.setPosition(300, 100);
    titlu.setFillColor(sf::Color::White);

}
void Meniu::initializare_variabile() {

    this->window = nullptr;
}

void Meniu::initializare_fereastra() {
    this ->videoMode.height=600;
    this ->videoMode.width=800;
    this->window = new sf::RenderWindow(this ->videoMode,
                                        "Mini-Games", sf::Style::Titlebar | sf::Style::Close );
    this -> window ->setFramerateLimit(144);
    // Create a view with the same size as the window
    view.setSize(static_cast<float>(window->getSize().x), static_cast<float>(window->getSize().y));
    view.setCenter(view.getSize() / 2.f);
    // Set the view to be displayed in the window
    window->setView(view);
}
///functii publice
void Meniu::update() {
    this -> pollEvents();
}

void Meniu::render() {
    if(this->window != nullptr)
    {
        this->window->clear(sf::Color::Black);
        //Draw Meniu
        this->draw();
        this ->window ->display();
    }


}

void Meniu::draw() {
    if(this->window != nullptr)
    {
        this->window->draw(titlu);
    for (auto & casuta : casute)
            casuta->draw(window);
    }

}


void Meniu::pollEvents() {
    if(this->window != nullptr) {

        while (this->window->pollEvent(this->ev)) {
            switch (this->ev.type) {

                case sf::Event::Closed:
                    this->window->close();
                    break;
                case sf::Event::KeyPressed: {
                    if (this->ev.key.code == sf::Keyboard::Escape)
                        this->window->close();
                    if (this->ev.key.code == sf::Keyboard::Down)
                    {
                        view.move(0.f, 10.f); // move the view down by 10 pixels
                        window->setView(view); // update the window with the new view
                    }
                    if (this->ev.key.code == sf::Keyboard::Up)
                    {
                        if (view.getCenter().y + view.getSize().y  > Meniu::sceneHeigh)
                        {
                            view.move(0.f, -10.f); // move the view down by 10 pixels
                            window->setView(view); // update the window with the new view
                        }

                    }

                }break;
                case sf::Event::MouseButtonPressed: {

                    for ( long long unsigned i = 0; i<casute.size(); i++ )
                        if (casute[i]->isClicked(window, ev, view))
                        {

                            //start jocuri[i]
                            //game loop

                            jocuri[i] -> initializare_fereastra();

                            try {
                            while (jocuri[i]->running()) {

                                jocuri[i]->update();
                                jocuri[i]->render();
                                     }
                                std::cout<<"Game Over\n";

                            auto* guessTheNumber = dynamic_cast<GuessTheNumber*> (jocuri[i]);
                            if (guessTheNumber != nullptr)
                            {
                                std::cout<<"Do you want to see the number of games played?\n Yes/No\n";
                                char answer[10];
                                std::cin>>answer;
                                if (strcmp(answer,"Yes") == 0 or strcmp(answer,"1") == 0 or strcmp(answer,"YES") == 0)
                                    GuessTheNumber::afisare_nr_jocuri();

                            }

                            }catch (eroare_falling_blocks &err) {
                            std::cout << "Eroarea este: " << err.what() << "\n";
                                delete jocuri[i];
                                jocuri[i] = new FallingBlocks;

                            }
                            catch (eroare_endless_maze &err){

                                std::cout << "Eroarea este: " << err.what() << "\n"<<"Game Over\n";
                                delete jocuri[i];
                                jocuri[i] = new EndlessMaze;

                            }
                           catch (eroare_GuessTheNumber &err)
                            {
                                std::cout<<"Eroarea este: "<<err.what()<<"\nGame Over";
                                delete jocuri[i];
                                jocuri[i] = new GuessTheNumber(10);

                            }
                    }

                        }
                break;
                case sf::Event::MouseMoved: {

//                    for (auto & casuta : casute)
//                    {  ///nu merge sa schimb culoarea cand fac hover, nu stiu de ce
////                        if (casuta->isHovered(window, ev, view))
////                            casuta->changeBackround();
//                    }


                break;}

                        default:
                            break;
            }
        }
    }
}


///constructori destructori etc
Meniu::Meniu() {
    this->initializare_variabile();
    this->initializare_fereastra();
    this->initializare_text();
}

Meniu::~Meniu() {
    delete this->window;
}



bool Meniu::running()  {
    if(this->window != nullptr)
        return this->window->isOpen();
    return false;
}

void Meniu::addCasuta(Casuta_Joc *casuta) {
    casute.emplace_back(casuta);
}

void Meniu::initializare_casute() {
    float y_scale = 225;
    for (auto & casuta : casute)
    {
        casuta->initializare_variabile(y_scale);
        y_scale+=120;
    }
}

void Meniu::deleteJocuri() {
    for (auto & joc : jocuri)
        delete joc;
}

void Meniu::addJoc(Interfata_joc* joc) {
    jocuri.emplace_back(joc);
}
