#ifndef BoulderMobile_H
#define BoulderMobile_H
#include "Character.h"
#include <stdlib.h>
#include <iostream>


class BoulderMobile : public Character
{
public:
    BoulderMobile(std::string name, int chanceOfSuccess, int Health,int carnumber);
    virtual ~BoulderMobile();

    void SpecialAttack(Character& other);
    void PutupDefence (Character &other);

    sf::Sprite Image()
    {

        if (!texBoulderMobile.loadFromFile("textures/driver pictures/BoulderMobile.png"))
            std::cerr << "no Texture" << std::endl;

        BoulderMobilesp.setTexture(texBoulderMobile);
        return BoulderMobilesp;
    }

protected:

private:
    sf::Sprite BoulderMobilesp;
    sf::Texture texBoulderMobile;


};

#endif // BoulderMobile_H
