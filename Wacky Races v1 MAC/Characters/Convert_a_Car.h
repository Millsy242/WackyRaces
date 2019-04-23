#ifndef Convert_a_Car_H
#define Convert_a_Car_H
#include "Character.h"
#include <stdlib.h>
#include <iostream>

class Convert_a_Car : public Character
{
public:
    Convert_a_Car(std::string name, int chanceOfSuccess, int Health,int carnumber);
    virtual ~Convert_a_Car();

    void SpecialAttack(Character &other);
    void PutupDefence (Character &other);

    sf::Sprite Image()
    {

        if (!ConvertACar.loadFromFile("textures/driver pictures/Convert-A-Car.png"))
            std::cerr << "no Texture" << std::endl;

        ConvertACarsp.setTexture(ConvertACar);
        return ConvertACarsp;

    }


protected:

private:
    sf::Sprite ConvertACarsp;
    sf::Texture ConvertACar;
};


#endif // Convert_a_Car_H
