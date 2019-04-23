#ifndef BulletproofBomb_H
#define BulletproofBomb_H
#include "Character.h"
#include <stdlib.h>
#include <iostream>


class BulletproofBomb : public Character
{
public:
    BulletproofBomb(std::string name, int chanceOfSuccess, int Health,int carnumber);
    virtual ~BulletproofBomb();

    void SpecialAttack(Character& other);
    void PutupDefence (Character &other);

    sf::Sprite Image()
    {

        if (!BulletProofBomb.loadFromFile("textures/driver pictures/Bullet-ProofBomb.png"))
            std::cerr << "no Texture" << std::endl;

        BulletProofBombsp.setTexture(BulletProofBomb);
        return BulletProofBombsp;
    }

protected:

private:
    sf::Sprite BulletProofBombsp;
    sf::Texture BulletProofBomb;

};

#endif // BulletproofBomb_H
