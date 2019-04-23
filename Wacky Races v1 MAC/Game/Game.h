#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <chrono>
#include <thread>
#include <cstdlib>
#include "Character.h"
#include "BoulderMobile.h"
#include "CreepyCoupe.h"
#include "Convert_a_Car.h"
#include "Haybailer.h"
#include "CompactPussycat.h"
#include "ArmySurplusSpecial.h"
#include "BulletproofBomb.h"
#include "ArkansasChugabug.h"
#include "TurboTerrific.h"
#include "Buzzwagon.h"
#include "MeanMachine.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <tgmath.h>
#include <fstream>
#include <sstream>
#include <locale>
#include <iomanip>
#include<string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
template <typename T> std::string ToString(const T& val)
{
    std::ostringstream strm;
    strm << val;
    return strm.str();
}
class Game
{
public:
    Game();
    void Standings();
    void Menu(sf::RenderWindow& window);
    void Run(sf::RenderWindow& window);
    void Update(sf::RenderWindow& window);
    void SpecialEvent();
    void changePOS(unsigned int index_1, unsigned int index_2);
    void ordercharacters();
    bool iseven(int n);
    const std::string currentDateTime();
    std::string Getline(int lineno, std::ifstream& file_)
    {

        std::string value;
        for(int temp{0}; temp <= lineno; temp++)
        {
            std::getline(file_,value);
        }
        return value;
    }
     int iGetline(int lineno, std::ifstream& file_)
    {
        std::string value;
        for(int temp{0}; temp < lineno; temp++)
            {
                std::getline(file_,value);
            }

    int value1{0};
    if ( ! (std::istringstream(value) >> value1) ) value1 = 9999;

    return value1;
    }
    void switchPOS()
    {
        int change_1 = rand() % (characters.size()-1) + 1;
        int number = rand() % 1 + (-1);
        int change_2 = change_1 + number;
        changePOS(change_1,change_2);
    }
    void displayString(std::string Stringy)
    {
        if(Stringy == "clear" or Stringy == "Clear")
            Commentator.setString(" ");
        else
        {
            if(Stringy.size() > 78)
                Stringy.insert(78,"\n");
            Commentator.setString(ToString(Stringy));
        }
    }

protected:

private:
    std::vector <sf::Sprite> images;
    std::vector <Character*> characters;
    std::vector <sf::Text> lineup;
    std::vector <sf::Text> numbers;
    std::vector <sf::Text> numbers_2;
    bool paused {false};
    bool raceover{false};
    bool randomevent{false};
    unsigned int numfinished{0};
    int percentlinelength;
    int percentlinelengthy;
    int racelength{4000};
    sf::Vector2i mousePOS;
    sf::RectangleShape percentageline;
    sf::Font font;
    sf::Font font1;
    int delay{200};
    int delaybackup;
    sf::Text delaytext;
    sf::Text Commentator;
    sf::Text CommentatorPost;
    sf::Text Time;

    BoulderMobile *BoulderMobile_;
    CreepyCoupe *CreepyCoupe_;
    Convert_a_Car *Convert_a_Car_;
    Haybailer *Haybailer_;
    CompactPussycat *CompactPussycat_ ;
    ArmySurplusSpecial *ArmySurplusSpecial_;
    BulletproofBomb *BulletproofBomb_;
    TurboTerrific *TurboTerrific_;
    ArkansasChugabug *ArkansasChugabug_;
    Buzzwagon *Buzzwagon_;
    MeanMachine *MeanMachine_;
};

#endif // GAME_H
