#ifndef ArkansasChugabug_H
#define ArkansasChugabug_H
#include "Character.h"
#include <stdlib.h>
#include <iostream>


class ArkansasChugabug : public Character
{
public:
    ArkansasChugabug(std::string name, int chanceOfSuccess, int Health,int carnumber);
    virtual ~ArkansasChugabug();

    void SpecialAttack(Character& other);
    void PutupDefence (Character &other);

    sf::Sprite Image()
    {

        if (!ArkansasChuggabug.loadFromFile("textures/driver pictures/ArkansasChuggabug.png"))
            std::cerr << "no Texture" << std::endl;

        ArkansasChuggabugsp.setTexture(ArkansasChuggabug);
        return ArkansasChuggabugsp;
    }


protected:

private:

    sf::Sprite ArkansasChuggabugsp;
    sf::Texture ArkansasChuggabug;

};

#endif // ArkansasChugabug_H
