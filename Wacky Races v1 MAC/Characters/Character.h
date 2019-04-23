#ifndef CHARACTER_H
#define CHARACTER_H
#include <fstream>
#include <sstream>
#include <locale>
#include <iomanip>
#include<string>
#include <SFML/Graphics.hpp>

class Character
{
protected:
    int Health;
    int Healthbackup;
    int chanceOfSuccess; // higher value = less chance of successful attackGame();
    int damageInflicted{100};
    bool alive {true};
    bool finished{false};
    float Distcount{0}; //distance counter
    float moveamount{4};
    int c{0};
    float percentage{0};
    bool frozen{false};
    bool broken{false};
    std::vector <std::string> Spower; //special successful power
    std::vector <std::string> Fpower; //special failed power
    std::vector <std::string> Upower; //powerup
    sf::Text Commentator_;
public:
    Character(std::string name, int chanceOfSuccess, int Health, int carnumber );
    virtual ~Character();
    bool IsAlive{true};
    void Attack(Character& other, sf::Text *Comment);
    void ReportStatus();
    void TakeDamage(int damage);
    virtual void SpecialAttack(Character &other) = 0;
    virtual void PutupDefence(Character &other) = 0;
    virtual sf::Sprite Image() = 0;
    void pushback_S(std::string specialpower)
    {
        Spower.push_back(specialpower);
    }
    void pushback_F(std::string specialpower)
    {
        Fpower.push_back(specialpower);
    }
     void pushback_U(std::string specialpower)
    {
        Upower.push_back(specialpower);
    }
    std::string Getline(int lineno, std::ifstream& file_)
    {
        std::string value;
        for(int temp{0}; temp <= lineno; temp++)
        {
            std::getline(file_,value);
        }
        return value;
    }
    void shuffle_Spower()
    {
        std::random_shuffle(Spower.begin(), Spower.end());
    }
    void shuffle_Fpower()
    {
        std::random_shuffle(Fpower.begin(), Fpower.end());
    }
    void shuffle_Upower()
    {
        std::random_shuffle(Upower.begin(), Upower.end());
    }
    std::string name {"default_name"};
    sf::Sprite repair;
    sf::Texture repairtex;
    float getDistance()
    {
        return Distcount;
    }
    void setDistance(float temp)
    {
        Distcount = temp;
    }
    void addtoDistance(float add)
    {
        Distcount += add;
    }
    void subtractfromDistance(float rem)
    {
        Distcount -= rem;
    }
    void increasedist(int racelength); //call every loop
    bool fin()
    {
        return finished;
    }
    float getpercentage()
    {
        return percentage;
    }
    int carnumber;
    void makefrozen()
    {
        frozen = true;
    }
    bool getbroken()
    {
        return broken;
    }
    void makebroken()
    {
        broken = true;
    }
    void DisplayString(std::string Stringy)
    {
        if(Stringy == "clear" or Stringy == "Clear")
            Commentator_.setString(" ");
        else
        {
            Commentator_.setString(Stringy);
        }
    }
private:
};
#endif // CHARACTER_H
