#ifndef CreepyCoupe_H
#define CreepyCoupe_H
#include "Character.h"
#include <stdlib.h>
#include <iostream>

class CreepyCoupe : public Character
{
public:
    CreepyCoupe(std::string name, int chanceOfSuccess, int Health,int carnumber);
    virtual ~CreepyCoupe();

    void SpecialAttack(Character &other);
    void PutupDefence (Character &other);

    sf::Sprite Image()
    {

        if (!texCreepyCoupe.loadFromFile("textures/driver pictures/CreepyCoupe.png"))
            std::cerr << "no Texture" << std::endl;
        CreepyCoupesp.setTexture(texCreepyCoupe);
        return CreepyCoupesp;
    }



protected:

private:
    sf::Sprite CreepyCoupesp;
    sf::Texture texCreepyCoupe;


};


#endif // CreepyCoupe_H
