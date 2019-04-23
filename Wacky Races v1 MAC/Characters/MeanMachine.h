#ifndef MeanMachine_H
#define MeanMachine_H
#include "Character.h"
#include <stdlib.h>
#include <iostream>

class MeanMachine : public Character
{
public:
    MeanMachine(std::string name, int chanceOfSuccess, int Health,int carnumber);
    virtual ~MeanMachine();

    void SpecialAttack(Character& other);
    void PutupDefence (Character &other);

    sf::Sprite Image()
    {


        if (!texMeanMachine.loadFromFile("textures/driver pictures/MeanMachine.png"))
            std::cerr << "no Texture" << std::endl;

        MeanMachinesp.setTexture(texMeanMachine);
        return MeanMachinesp;
    }


protected:

private:
    sf::Texture texMeanMachine;
    sf::Sprite MeanMachinesp;


};

#endif // MeanMachine_H
