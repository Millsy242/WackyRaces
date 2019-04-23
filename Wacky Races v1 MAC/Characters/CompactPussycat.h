#ifndef CompactPussycat_H
#define CompactPussycat_H
#include "Character.h"
#include <stdlib.h>
#include <iostream>

class CompactPussycat : public Character
{
public:
    CompactPussycat(std::string name, int chanceOfSuccess, int Health,int carnumber);
    virtual ~CompactPussycat();

    void SpecialAttack(Character& other);
    void PutupDefence (Character &other);

    sf::Sprite Image()
    {

        if (!texCompactPussycat.loadFromFile("textures/driver pictures/CompactPussycat.png"))
            std::cerr << "no Texture" << std::endl;

        CompactPussycatsp.setTexture(texCompactPussycat);
        return CompactPussycatsp;
    }

protected:

private:
    sf::Texture texCompactPussycat;
    sf::Sprite CompactPussycatsp;

};

#endif // CompactPussycat_H
