//
// Created by david on 4/15/2023.
//

#include "Meniu.h"
#include "EndlessMaze.h"
#include "Interfata_joc.h"
#include "FallingBlocks.h"
#include "GuessTheNumber.h"
///functii private
void Meniu::initializare_text() {

    font.loadFromFile(R"(C:\Users\david\CLionProjects\PROIECT-POO1\arial.ttf)");

    titlu.setString("Choose your game!");
    titlu.setFont(font);
    titlu.setCharacterSize(24);
    titlu.setPosition(300, 100);
    titlu.setFillColor(sf::Color::White);

    maze.setString("EndlessMaze");
    maze.setFont(font);
    maze.setCharacterSize(24);
    maze.setPosition(200, 250);
    maze.setFillColor(sf::Color::Black);

    blocks.setString("FallingBlocks");
    blocks.setFont(font);
    blocks.setCharacterSize(24);
    blocks.setPosition(450, 250);
    blocks.setFillColor(sf::Color::Black);

    guess.setString("GuessTheNumber");
    guess.setFont(font);
    guess.setCharacterSize(24);
    guess.setPosition(291, 410);
    guess.setFillColor(sf::Color::Black);
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
        this->window->draw(EndlessMaze);
        this->window->draw(FallingBlocks);
        this->window->draw(GuessTheNumber);
        this->window->draw(titlu);
        this->window->draw(maze);
        this->window->draw(guess);
        this->window->draw(blocks);
    }

}

void Meniu::initializare_casuta() {
    this -> EndlessMaze.setPosition(170.f, 225.f);
    this -> EndlessMaze.setSize(sf::Vector2f(200.f, 100.f));
    this -> EndlessMaze.setFillColor(sf::Color::Green);
    this -> EndlessMaze.setOutlineColor(sf::Color::Black);
    this -> EndlessMaze.setOutlineThickness(5.f);

    this -> FallingBlocks.setPosition(420.f, 225.f);
    this -> FallingBlocks.setSize(sf::Vector2f(200.f, 100.f));
    this -> FallingBlocks.setFillColor(sf::Color::Green);
    this -> FallingBlocks.setOutlineColor(sf::Color::Black);
    this -> FallingBlocks.setOutlineThickness(5.f);


    this -> GuessTheNumber.setPosition(290.f, 380.f);
    this -> GuessTheNumber.setSize(sf::Vector2f(200.f, 100.f));
    this -> GuessTheNumber.setFillColor(sf::Color::Green);
    this -> GuessTheNumber.setOutlineColor(sf::Color::Black);
    this -> GuessTheNumber.setOutlineThickness(5.f);
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
                }break;
                case sf::Event::MouseButtonPressed: {
                    sf::FloatRect rectBounds = EndlessMaze.getGlobalBounds();
                    sf::FloatRect rectBounds2 = FallingBlocks.getGlobalBounds();
                    sf::FloatRect rectBounds3 = GuessTheNumber.getGlobalBounds();
                    sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
                    if (rectBounds.contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                        // Do something when the rectangle is clicked

                            class EndlessMaze Maze;

                            //game loop
                            while (Maze.running()) {

                                try {Maze.update();}

                                catch (const eroare_endless_maze& err) {
                                    std::cout<<err.what();
                                }

                                Maze.render();
                            }

                        }
                    if (rectBounds2.contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {

                            Interfata_joc* InterfataPtr = new class FallingBlocks();

                            //game loop
                            while (InterfataPtr->running()) {
                                try{InterfataPtr->update();}
                                    catch (eroare_falling_blocks &err) {
                                        std::cout << "Eroarea este: " << err.what() << "\n";
                                    }
                                InterfataPtr->render();


                        }

                    }


                    if (rectBounds3.contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                        // Do something when the rectangle is clicked

                         Interfata_joc* game = new  class GuessTheNumber(10);
                        for (int i = 0; i < 10; i++) {

                            try {game->update();}
                            catch(const eroare_GuessTheNumber& err) {
                                std::cout<<"Eroarea este "<<err.what()<<"\n";
                            }
                        }
                        dynamic_cast<class GuessTheNumber*>(game)->afisare_nr_jocuri();
                    }

                }break;
                case sf::Event::MouseMoved: {
                    // Check if the mouse is within the bounds of the rectangle
                    sf::FloatRect rectBounds = EndlessMaze.getGlobalBounds();
                    sf::FloatRect rectBounds2 = FallingBlocks.getGlobalBounds();
                    sf::FloatRect rectBounds3 = GuessTheNumber.getGlobalBounds();

                    sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
                    if (rectBounds.contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                        // Do something when the mouse is over the rectangle
                        EndlessMaze.setFillColor(sf::Color::Blue);
                    } else {
                        // Reset the color of the rectangle when the mouse is not over it
                        EndlessMaze.setFillColor(sf::Color::Green);
                    }
                    if (rectBounds2.contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                        FallingBlocks.setFillColor(sf::Color::Blue);
                    } else {
                        FallingBlocks.setFillColor(sf::Color::Green);
                    }

                    if (rectBounds3.contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                        GuessTheNumber.setFillColor(sf::Color::Blue);
                    } else {
                        GuessTheNumber.setFillColor(sf::Color::Green);
                    }
                }break;
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
    this->initializare_casuta();
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