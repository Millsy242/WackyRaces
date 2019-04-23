#ifndef Buzzwagon_H
#define Buzzwagon_H
#include "Character.h"
#include <stdlib.h>
#include <iostream>


class Buzzwagon : public Character
{
public:
    Buzzwagon(std::string name, int chanceOfSuccess, int Health,int carnumber);
    virtual ~Buzzwagon();

    void SpecialAttack(Character& other);
    void PutupDefence (Character &other);

    sf::Sprite Image()
    {

        if (!texBuzzWagon.loadFromFile("textures/driver pictures/BuzzWagon.png"))
            std::cerr << "no Texture" << std::endl;
        BuzzWagonsp.setTexture(texBuzzWagon);
        return BuzzWagonsp;
    }

protected:

private:
    sf::Sprite BuzzWagonsp;
    sf::Texture texBuzzWagon;



};

#endif // Buzzwagon_H
