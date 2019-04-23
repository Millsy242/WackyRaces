#include "MeanMachine.h"
#include <iostream>

MeanMachine::MeanMachine(std::string name_, int chanceOfSuccess_, int Health_,  int carnumber):
    Character(name_, chanceOfSuccess_, Health_, carnumber)
{
    std::ifstream Spowers;
    Spowers.open("Characters/Power/SpecialPower/MeanMachine.txt");
    int i{1};
    while(!Spowers.eof())
    {
        pushback_S(Getline(i,Spowers));
        i++;
    }

    Spowers.close();

    std::ifstream Fpowers;
   Fpowers.open("Characters/Power/FailedPower/MeanMachine.txt");
    int b{1};
    while(!Fpowers.eof())
    {
        pushback_F(Getline(b,Fpowers));
        b++;
    }
    Fpowers.close();

    std::ifstream Upowers;
   Upowers.open("Characters/Power/PowerUP/MeanMachine.txt");
    int a{1};
    while(!Upowers.eof())
    {
        pushback_U(Getline(a,Upowers));
        a++;
    }
    Upowers.close();
}

MeanMachine::~MeanMachine()
{
}

void MeanMachine::SpecialAttack(Character &other)
{

}
void MeanMachine::PutupDefence(Character &other)
{
    std::cout << " but " << name << " defends using a spell";

    int defendAmount = rand() % 50 + 1;

    std::cout << " and gains " << defendAmount << " Health" << std::endl;

    defendAmount = defendAmount * -1;

    other.TakeDamage(defendAmount);
}
