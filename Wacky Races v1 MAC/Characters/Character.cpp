#include "Character.h"
#include <iostream>
#include <stdlib.h>
#include "Game.h"

Character::Character(std::string name_, int chanceOfSuccess_, int Health_, int carnumber):
    name(name_), chanceOfSuccess(chanceOfSuccess_), Health(Health_), carnumber(carnumber)
{
    if (!repairtex.loadFromFile("textures/repair.png"))
        std::cerr << "no Texture" << std::endl;

    repair.setTexture(repairtex);
    repair.setColor(sf::Color::Transparent);

    Healthbackup = Health;

}
Character::~Character()
{
}
void Character::TakeDamage(int damage)
{
    Health -= damage;
    if (Health <= 0)
    {
        IsAlive =false;
        moveamount = 0;
    }
}
void Character::Attack(Character& other, sf::Text *Comment)
{
    if(other.name == name)
    {
     //std::cout << "ERROR: " << name << " = " << other.name << std::endl;
    }
    else
    {
        Commentator_ = *Comment;
        if(other.fin() or finished)
            return;
        else
        {
            int random = rand() % 10;
            int random_2 = (rand() % 100+10);
            int random_3 = rand() % 2;
            int random_4 = rand() % 150+10;

            if(random < chanceOfSuccess)
            {
                if(random_3 == 0)
                {
                    shuffle_Upower();
                    DisplayString(name + Upower[0]);
                    addtoDistance(random_2);
                }
                else
                {
                    shuffle_Spower();
                    DisplayString(name + Spower[0] + " " + other.name);
                    other.subtractfromDistance(random_2);
                    other.TakeDamage(random_4);
                }
            }
            else
            {
                shuffle_Fpower();
                DisplayString(name + Fpower[0]);
                subtractfromDistance(random_2);
                TakeDamage(random_4);
            }
        }
        *Comment = Commentator_;
    }

}
void Character::ReportStatus()
{
    if (Health >= 1)
        std::cout << name << " has " << Health << " hit points left" << std::endl;
    else
        std::cout << name << " has broken down! They stop for repairs" << std::endl;
}
void Character::increasedist(int racelength) //call every loop
{
    if(frozen)
    {
        c++;
        if(c >= 10)
        {
            c=0;
            frozen = false;
        }
    }
    else
    {
        if (Health < 75)
        {
            moveamount = 3;
            Health--;
        }
        if (Health < 50)
        {
            moveamount = 2;
        }
        if (Health < 25)
        {
            moveamount = 1;
        }
        if (Health < 1)
        {
            Health = 0;
            repair.setColor(sf::Color::Red);
            //std::cout << name << " has broken down! They stop for repairs   " << Health << std::endl; //Debug
            broken = true;
            moveamount = 0;
            c++;
            if(c > 30)
            {
                moveamount = 4;
                Health = Healthbackup;
                c=0;
                broken = false;
                repair.setColor(sf::Color::Transparent);
            }
        }
    }
    if(!broken)
    {
        if(Distcount >  racelength)
            Distcount = racelength;
        if(Distcount <  0)
            Distcount = 0;
        if(Distcount >= racelength)
            finished = true;

        if(!finished && !frozen)
            Distcount+= moveamount;
    }
    else
        repair.setColor(sf::Color::Red);

    percentage = ((float)Distcount / (float)racelength) * 100 ;
}
