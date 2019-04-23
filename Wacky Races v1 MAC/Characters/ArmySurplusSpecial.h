#ifndef ArmySurplusSpecial_H
#define ArmySurplusSpecial_H
#include "Character.h"
#include <stdlib.h>
#include <iostream>


class ArmySurplusSpecial : public Character
{
public:
    ArmySurplusSpecial(std::string name, int chanceOfSuccess, int Health,int carnumber);
    virtual ~ArmySurplusSpecial();

    void SpecialAttack(Character& other);
    void PutupDefence (Character &other);
    sf::Sprite Image()
    {

        if (!texArmySurplusSpecial.loadFromFile("textures/driver pictures/ArmySurplusSpecial.png"))
            std::cerr << "no Texture" << std::endl;

        ArmySurplusSpecialsp.setTexture(texArmySurplusSpecial);
        return ArmySurplusSpecialsp;
    }


protected:

private:
    sf::Sprite ArmySurplusSpecialsp;
    sf::Texture texArmySurplusSpecial;


};

#endif // ArmySurplusSpecial_H
