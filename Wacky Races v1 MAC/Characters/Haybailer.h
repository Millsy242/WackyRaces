#ifndef Haybailer_H
#define Haybailer_H
#include "Character.h"
#include <stdlib.h>
#include <iostream>

class Haybailer : public Character
{
public:
    Haybailer(std::string name, int chanceOfSuccess, int Health,int carnumber );
    virtual ~Haybailer();

    void SpecialAttack(Character& other);
    void PutupDefence (Character &other);

    sf::Sprite Image()
    {

        if (!texHaybailer.loadFromFile("textures/driver pictures/Haybailer.png"))
            std::cerr << "no Texture" << std::endl;

        Haybailersp.setTexture(texHaybailer);
        return Haybailersp;
    }


protected:

private:
    sf::Sprite Haybailersp;
    sf::Texture texHaybailer;

};

#endif // Haybailer_H
