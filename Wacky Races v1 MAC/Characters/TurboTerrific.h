#ifndef TurboTerrific_H
#define TurboTerrific_H
#include "Character.h"
#include <stdlib.h>
#include <iostream>

class TurboTerrific : public Character
{
public:
    TurboTerrific(std::string name, int chanceOfSuccess, int Health,int carnumber);
    virtual ~TurboTerrific();

    void SpecialAttack(Character& other);
    void PutupDefence (Character &other);

    sf::Sprite Image()
    {

        if (!texTurboTerrific.loadFromFile("textures/driver pictures/TurboTerrific.png"))
            std::cerr << "no Texture" << std::endl;

        TurboTerrificsp.setTexture(texTurboTerrific);
        TurboTerrificsp.setPosition(0,0);
        return TurboTerrificsp;
    }

protected:

private:
    sf::Sprite TurboTerrificsp;
    sf::Texture texTurboTerrific;

};

#endif // TurboTerrific_H
