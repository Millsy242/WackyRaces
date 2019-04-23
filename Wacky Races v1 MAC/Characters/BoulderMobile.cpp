#include "BoulderMobile.h"
#include <iostream>

BoulderMobile::BoulderMobile(std::string name_, int chanceOfSuccess_, int Health_,  int carnumber):
    Character(name_, chanceOfSuccess_, Health_, carnumber)
{
    std::ifstream Spowers;
    Spowers.open("Characters/Power/SpecialPower/BoulderMobile.txt");
    int i{1};
    while(!Spowers.eof())
    {
        pushback_S(Getline(i,Spowers));
        i++;
    }

    Spowers.close();

    std::ifstream Fpowers;
   Fpowers.open("Characters/Power/FailedPower/BoulderMobile.txt");
    int b{1};
    while(!Fpowers.eof())
    {
        pushback_F(Getline(b,Fpowers));
        b++;
    }
    Fpowers.close();

    std::ifstream Upowers;
   Upowers.open("Characters/Power/PowerUP/BoulderMobile.txt");
    int a{1};
    while(!Upowers.eof())
    {
        pushback_U(Getline(a,Upowers));
        a++;
    }
    Upowers.close();
}

BoulderMobile::~BoulderMobile()
{
    //dtor
}

void BoulderMobile::SpecialAttack(Character &other)
{


}
void BoulderMobile::PutupDefence(Character &other)
{

}

