#include "Game.h"

const std::string Game::currentDateTime()
{
    time_t now = time(0);
    struct tm  tstruct;
    char buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
    return buf;
}
bool Game::iseven(int n)
{
    if(n%2 == 0)
        return true;
    else
        return false;
}
Game::Game()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 16;
    sf::RenderWindow window(sf::VideoMode(1920,1080), "Wacky Races Alpha 0.6",sf::Style::Default, settings);
    srand(time(NULL));
    Menu(window);
    return;
}
void Game::Standings()
{
    if(raceover == false)
    {
        float posonline;
        ordercharacters();
        for(unsigned int i{0}; i<characters.size(); i++)
        {
            lineup[i].setString(ToString(characters[i]->name)  +  "   -   " + ToString(characters[i]->carnumber) + "   -   " + ToString(trunc(characters[i]->getpercentage())) + "% ");
            posonline = (float)((characters[i]->getDistance() / racelength) * percentlinelength);
            numbers_2[i].setString(ToString(characters[i]->carnumber) );
            if(iseven(i))
                numbers_2[i].setPosition(posonline,percentlinelengthy-30);
            else
                numbers_2[i].setPosition(posonline,percentlinelengthy+10);

            if(i == 1 or i == 4 or i==5 or i==8 or i==9)
                numbers_2[i].setFillColor(sf::Color::Black);
            else
                numbers_2[i].setFillColor(sf::Color::White);

            characters[i]->repair.setPosition((lineup[i].getPosition().x+lineup[i].getLocalBounds().width+5),lineup[i].getPosition().y );
        }
    }
}
void Game::ordercharacters()
{
    float temp = racelength * 2.2;

    for (auto &p: characters)
    {
        if((characters[0]->getDistance() - p->getDistance()) > temp )
            p->setDistance(characters[0]->getDistance()-temp);
    }
    unsigned int count{0};
    while(count != characters.size())
    {
        unsigned int temp;
        unsigned int temp_2;
        for(unsigned int i{0}; i<characters.size()-1; i++)
        {
            temp = characters[i]->getDistance();

            temp_2 = characters[i+1]->getDistance();

            if(temp_2 > temp)
            {
                characters[i+1]->setDistance(temp);
                characters[i]->setDistance(temp_2);
            }
        }
        count++;
    }
    count = 0;
}
void Game::Menu(sf::RenderWindow& window)
{
    window.setActive(true);
    bool Start{false};
    sf::Music Theme;
    if (!Theme.openFromFile("Music/Wacky Races Theme.wav"))
        std::cout << "fail" << std::endl;
    Theme.play();

    sf::Texture playTexture;
    if (!playTexture.loadFromFile("textures/Play.png"))
        std::cerr << "no Texture" << std::endl;
    sf::Sprite playSprite;
    playSprite.setTexture(playTexture);
    playSprite.setOrigin(100,50);

    sf::Texture exitTexture;
    if (!exitTexture.loadFromFile("textures/Exit.png"))
        std::cerr << "no Texture" << std::endl;
    sf::Sprite exitSprite;
    exitSprite.setTexture(exitTexture);
    exitSprite.setOrigin(100,50);

    //time each character appears in music - initials of driver/car
    sf::Time TT = sf::seconds(17);
    sf::Time RR= sf::seconds(20);
    sf::Time ASS= sf::seconds(22);
    sf::Time BBB= sf::seconds(25);
    sf::Time CAC= sf::seconds(29);
    sf::Time  PP= sf::seconds(33);
    sf::Time  BB= sf::seconds(39);
    sf::Time   CC= sf::seconds(41);
    sf::Time  RM= sf::seconds(44);
    sf::Time  AC= sf::seconds(47);
    sf::Time  MM= sf::seconds(50);
    sf::Time  END= sf::seconds(60);



    std::ifstream BoulderMobile_file;
    BoulderMobile_file.open("Characters/BoulderMobile.txt");
    std::ifstream CreepyCoupe_file;
    CreepyCoupe_file.open("Characters/CreepyCoupe.txt");
    std::ifstream Convert_a_Car_file;
    Convert_a_Car_file.open("Characters/Convert_a_Car.txt");
    std::ifstream Haybailer_file;
    Haybailer_file.open("Characters/Haybailer.txt");
    std::ifstream CompactPussycat_file;
    CompactPussycat_file.open("Characters/CompactPussycat.txt");
    std::ifstream ArmySurplusSpecial_file;
    ArmySurplusSpecial_file.open("Characters/ArmySurplusSpecial.txt");
    std::ifstream BulletproofBomb_file;
    BulletproofBomb_file.open("Characters/BulletproofBomb.txt");
    std::ifstream TurboTerrific_file;
    TurboTerrific_file.open("Characters/TurboTerrific.txt");
    std::ifstream ArkansasChugabug_file;
    ArkansasChugabug_file.open("Characters/ArkansasChugabug.txt");
    std::ifstream Buzzwagon_file;
    Buzzwagon_file.open("Characters/Buzzwagon.txt");
    std::ifstream MeanMachine_file;
    MeanMachine_file.open("Characters/MeanMachine.txt");


    // Create the characters
    // Character *Character_name = new Character("Character_name",chance_of_success, health, Car Number);
    BoulderMobile_ = new BoulderMobile(Getline(2,BoulderMobile_file),iGetline(1,BoulderMobile_file), iGetline(1,BoulderMobile_file), iGetline(1,BoulderMobile_file));
    CreepyCoupe_ =new CreepyCoupe(Getline(2,CreepyCoupe_file),iGetline(1, CreepyCoupe_file ), iGetline(1,CreepyCoupe_file ), iGetline(1,CreepyCoupe_file ));
    Convert_a_Car_ = new Convert_a_Car(Getline(2,Convert_a_Car_file),iGetline(1,Convert_a_Car_file ), iGetline(1,Convert_a_Car_file ), iGetline(1,Convert_a_Car_file ));
    Haybailer_ = new Haybailer(Getline(2,Haybailer_file),iGetline(1,Haybailer_file ), iGetline(1,Haybailer_file ), iGetline(1,Haybailer_file ));
    CompactPussycat_ = new CompactPussycat(Getline(2,CompactPussycat_file),iGetline(1,CompactPussycat_file ), iGetline(1,CompactPussycat_file ), iGetline(1,CompactPussycat_file ));
    ArmySurplusSpecial_ = new ArmySurplusSpecial(Getline(2,ArmySurplusSpecial_file),iGetline(1,ArmySurplusSpecial_file ), iGetline(1,ArmySurplusSpecial_file ), iGetline(1,ArmySurplusSpecial_file ));
    BulletproofBomb_ =new BulletproofBomb(Getline(2,BulletproofBomb_file),iGetline(1,BulletproofBomb_file ), iGetline(1,BulletproofBomb_file ), iGetline(1,BulletproofBomb_file ));
    TurboTerrific_ = new TurboTerrific(Getline(2,TurboTerrific_file),iGetline(1, TurboTerrific_file), iGetline(1,TurboTerrific_file ), iGetline(1,TurboTerrific_file ));
    ArkansasChugabug_ = new ArkansasChugabug(Getline(2,ArkansasChugabug_file),iGetline(1,ArkansasChugabug_file ), iGetline(1,ArkansasChugabug_file ), iGetline(1,ArkansasChugabug_file ));
    Buzzwagon_ =new Buzzwagon(Getline(2,Buzzwagon_file),iGetline(1, Buzzwagon_file), iGetline(1,Buzzwagon_file ), iGetline(1,Buzzwagon_file ));
    MeanMachine_ = new MeanMachine(Getline(2,MeanMachine_file),iGetline(1,MeanMachine_file ), iGetline(1,MeanMachine_file ), iGetline(1,MeanMachine_file ));


    BoulderMobile_file.close();
    CreepyCoupe_file.close();
    Convert_a_Car_file.close();
    Haybailer_file.close();
    CompactPussycat_file.close();
    ArmySurplusSpecial_file.close();
    BulletproofBomb_file.close();
    TurboTerrific_file.close();
    ArkansasChugabug_file.close();
    Buzzwagon_file.close();
    MeanMachine_file.close();

    Theme.stop();
    Run(window);
    /*
    while(!Start)
    {

        mousePOS = sf::Mouse::getPosition(window);
        if((mousePOS.x < (playSprite.getPosition().x + 100) && mousePOS.x > (playSprite.getPosition().x -100) ) && (mousePOS.y < (playSprite.getPosition().y+50) && mousePOS.y > (playSprite.getPosition().y -50) ) )
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                Theme.stop();
                Run(window);
            }
        if((mousePOS.x < exitSprite.getPosition().x + 100 && mousePOS.x > (exitSprite.getPosition().x -100) ) && (mousePOS.y < exitSprite.getPosition().y +100 && mousePOS.y > (exitSprite.getPosition().y -50) ) )
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                Start=true;
                Theme.stop();
            }
        window.clear(sf::Color::Black);
        exitSprite.setPosition(window.getSize().x - 200,window.getSize().y/2);
        playSprite.setPosition(window.getSize().x - 200,window.getSize().y/4);

        if(Theme.getPlayingOffset() >TT && Theme.getPlayingOffset() < RR )
            window.draw(TurboTerrific_->Image());
        if(Theme.getPlayingOffset() > RR && Theme.getPlayingOffset() < ASS)
            window.draw(Buzzwagon_->Image());
        if(Theme.getPlayingOffset() > ASS && Theme.getPlayingOffset() < BBB)
            window.draw( ArmySurplusSpecial_->Image());
        if(Theme.getPlayingOffset() > BBB && Theme.getPlayingOffset() < CAC)
            window.draw(BulletproofBomb_->Image());
        if(Theme.getPlayingOffset() > CAC && Theme.getPlayingOffset() < PP)
            window.draw(Convert_a_Car_->Image());
        if(Theme.getPlayingOffset() > PP && Theme.getPlayingOffset() < BB)
            window.draw(CompactPussycat_->Image());
        if(Theme.getPlayingOffset() > BB && Theme.getPlayingOffset() < CC)
            window.draw(BoulderMobile_->Image());
        if(Theme.getPlayingOffset() > CC && Theme.getPlayingOffset() < RM)
            window.draw(CreepyCoupe_->Image());
        if(Theme.getPlayingOffset() > RM && Theme.getPlayingOffset() < AC)
            window.draw(Haybailer_->Image());
        if(Theme.getPlayingOffset() > AC && Theme.getPlayingOffset() < MM)
            window.draw(ArkansasChugabug_->Image());
        if(Theme.getPlayingOffset() > MM && Theme.getPlayingOffset() < END)
            window.draw(MeanMachine_->Image());

        window.draw(playSprite);
        window.draw(exitSprite);

        window.display();
    }
     */
}
void Game::Update(sf::RenderWindow& window)
{
    sf::Clock countdown;
    sf::Time stop = sf::seconds(4);
    sf::Time sec1 = sf::seconds(3);
    sf::Time sec2 = sf::seconds(2);
    sf::Time sec3 = sf::seconds(1);

    sf::Text onesec;
    sf::Text twosec;
    sf::Text threesec;
    sf::Text zerosec;

    onesec.setFont(font);
    twosec.setFont(font);
    threesec.setFont(font);
    zerosec.setFont(font);

    onesec.setCharacterSize(800);
    twosec.setCharacterSize(800);
    threesec.setCharacterSize(800);
    zerosec.setCharacterSize(800);

    onesec.setString("3");
    twosec.setString("2");
    threesec.setString("1");
    zerosec.setString("0");

    onesec.setPosition(window.getSize().x/2,0);
    twosec.setPosition(window.getSize().x/2,0);
    threesec.setPosition(window.getSize().x/2,0);
    zerosec.setPosition(window.getSize().x/2,0);

    while(countdown.getElapsedTime()< (stop+sec3))
    {
        window.clear();
        if(countdown.getElapsedTime()< sec3)
            window.draw(onesec);
        if(countdown.getElapsedTime()< sec2 && countdown.getElapsedTime() > sec3)
            window.draw(twosec);
        if(countdown.getElapsedTime()< sec1 && countdown.getElapsedTime()> sec2)
            window.draw(threesec);
        if(countdown.getElapsedTime()< stop && countdown.getElapsedTime()> sec1)
            window.draw(zerosec);
        window.display();
    }
    sf::Clock RaceTime;

    for(int i{0}; i<characters.size(); i++)
        {
            float pos = rand()%500+10;
             characters[i]->setDistance(pos);
        }



    while (numfinished < characters.size())
    {
        Time.setString("Time: " + ToString(trunc(RaceTime.getElapsedTime().asSeconds())));
        raceover = false;
        //controls
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
                switch(event.type)
                {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    switch(event.key.code)
                    {
                    case sf::Keyboard::Escape: //For debugging Only
                        window.close();
                        return;
                        break;
                    case sf::Keyboard::Space: //For debugging Only
                        randomevent = false;
                        SpecialEvent();
                        break;
                    case sf::Keyboard::Q: //For debugging Only
                        characters[0]->makebroken();
                        break;
                    case sf::Keyboard::Right:
                        if (!paused)
                        {
                            delay+=10;
                            delaytext.setFillColor(sf::Color::Blue);
                        }
                        break;
                    case sf::Keyboard::Left:
                        if (!paused)
                        {
                            delay-= 10;
                            delaytext.setFillColor(sf::Color::Yellow);
                        }
                        break;
                    case sf::Keyboard::Up:
                        if (!paused)
                            delay+=50;
                        delaytext.setFillColor(sf::Color::Blue);
                        break;
                    case sf::Keyboard::Down:
                        if (!paused)
                        {
                            delay-=50;
                            delaytext.setFillColor(sf::Color::Yellow);
                        }
                        break;
                    case sf::Keyboard::R:
                        if (!paused)
                        {
                            delay = delaybackup;
                            delaytext.setFillColor(sf::Color::White);
                        }
                        break;
                    case sf::Keyboard::P:
                        paused = !paused;
                        break;
                    default:
                        break;
                    }
                default:
                    break;
                }
            }
        }
        if(!paused)
        {
            ordercharacters();
            if(delay <= 0)
            {
                delay = 10;
                paused = true;
            }
            // A delay
            std::this_thread::sleep_for(std::chrono::milliseconds(delay));

            delaytext.setString(ToString(delay));
            Standings();
            int changes = rand() % 2;
            int i{0};
            while(i < changes)
            {
                switchPOS();
                i++;
            }
            for (auto &p: characters)
            {
                p->increasedist(racelength);
                if( p->fin())
                    numfinished++;
            }
            int index = rand() % characters.size();
            int index_0 = rand() % characters.size();
            int index_1 = rand() % 100;

            if(index_1 > 89)
                characters[index]->Attack(*characters[index_0], &Commentator);

            if(characters[0]->getpercentage() >= 30 && characters[0]->getpercentage() <= 75)
            {
                int randevent1 = rand() % 50;
                if(randevent1  <= 10)
                    SpecialEvent();
            }
            ordercharacters();
        }

        window.clear(sf::Color(44, 176, 55));
        window.draw(Time);
        window.draw(Commentator);
        window.draw(percentageline);
        window.draw(delaytext);
        for (auto &p: lineup)
            window.draw(p);
        for (auto &p: numbers)
            window.draw(p);
        for (auto &p: numbers_2)
            window.draw(p);
        for (auto &p: characters)
        {
            if(p->getbroken() == true)
                window.draw(p->repair);
        }
        window.display();
    }
}
void Game::changePOS(unsigned int index_1, unsigned int index_2)
{
    if(characters[index_1]->fin() or characters[index_2]->fin())
        switchPOS();
    else
    {
        if(((characters[index_1]->getpercentage() - characters[index_2]->getpercentage() <= 5) && (characters[index_1]->getpercentage() - characters[index_2]->getpercentage() >= 0)) or  ((characters[index_2]->getpercentage() - characters[index_1]->getpercentage() <= 5) && characters[index_2]->getpercentage() - characters[index_1]->getpercentage() >= 0 ))
        {
            std::vector <Character*> Temp;
            if(index_1 > characters.size()-1 or index_2 > characters.size()-1)
                std::cout << "ERROR: index 1 or 2 is outside the bounds of the vector: characters" << std::endl;
            else
            {
                Temp.push_back(characters[index_1]);
                characters[index_1] = characters[index_2];
                characters[index_2] = Temp[0];

                int dist = characters[index_1]->getDistance();

                characters[index_1]->setDistance(dist);
                characters[index_2]->setDistance(dist++);

                for(unsigned int i{0}; i<Temp.size(); i++)
                    Temp.pop_back();
            }
        }
        else
            switchPOS();
    }
}
void Game::Run(sf::RenderWindow& window)
{
    //setup game
    {
        //characters.push_back(name);
        characters.push_back(BoulderMobile_);
        characters.push_back(CreepyCoupe_);
        characters.push_back(Convert_a_Car_);
        characters.push_back(Haybailer_);
        characters.push_back(CompactPussycat_);
        characters.push_back(ArmySurplusSpecial_);
        characters.push_back(BulletproofBomb_);
        characters.push_back(ArkansasChugabug_);
        characters.push_back(TurboTerrific_);
        characters.push_back(Buzzwagon_);
        characters.push_back(MeanMachine_);
        std::random_shuffle ( characters.begin(), characters.end()-1 );

        font.loadFromFile("fonts/Rodfellows wacky.ttf");
        if(!font.loadFromFile("fonts/Rodfellows wacky.ttf"))
            std::cout<<"ERROR: Cant find font"<<std::endl;

        font1.loadFromFile("fonts/baveuse.ttf");
        if(!font1.loadFromFile("fonts/baveuse.ttf"))
            std::cout<<"ERROR: Cant find font1"<<std::endl;

        delaytext.setFont(font);
        delaytext.setCharacterSize(20);

        delaybackup = delay;

        sf::Text First;
        sf::Text Second;
        sf::Text Third;
        sf::Text Fourth;
        sf::Text Fifth;
        sf::Text Sixth;
        sf::Text Seventh;
        sf::Text Eighth;
        sf::Text Ninth;
        sf::Text Tenth;
        sf::Text Eleventh;
        lineup.push_back(First);
        lineup.push_back(Second);
        lineup.push_back(Third);
        lineup.push_back(Fourth);
        lineup.push_back(Fifth);
        lineup.push_back(Sixth);
        lineup.push_back(Seventh);
        lineup.push_back(Eighth);
        lineup.push_back(Ninth);
        lineup.push_back(Tenth);
        lineup.push_back(Eleventh);

        for (auto &p: lineup)
        {
            p.setFont(font);
            p.setCharacterSize(20);
        }
        sf::Text one;
        sf::Text two;
        sf::Text three;
        sf::Text four;
        sf::Text five;
        sf::Text six;
        sf::Text seven;
        sf::Text eight;
        sf::Text nine;
        sf::Text ten;
        sf::Text eleven;
        numbers.push_back(one);
        numbers.push_back(two);
        numbers.push_back(three);
        numbers.push_back(four);
        numbers.push_back(five);
        numbers.push_back(six);
        numbers.push_back(seven);
        numbers.push_back(eight);
        numbers.push_back(nine);
        numbers.push_back(ten);
        numbers.push_back(eleven);

        for(unsigned int b{0}; b<numbers.size(); b++)
        {
            numbers[b].setFont(font);
            numbers[b].setCharacterSize(20);
        }
        numbers_2 = numbers;
        for(unsigned int b{0}; b<numbers.size(); b++)
        {
            int c = b+1;
            numbers[b].setString(ToString(c));
        }
        int xname = 50;
        int xnum = 20;
        int y= 20;
        for (auto &p: lineup)
        {
            p.setPosition(sf::Vector2f(xname,y));
            y+=20;
        }
        y=20;
        for (auto &p: numbers)
        {
            p.setPosition(sf::Vector2f(xnum,y));
            y+=20;
        }
        percentlinelengthy =  window.getSize().y-100;
        percentlinelength =  window.getSize().x-40;
        percentageline.setSize((sf::Vector2f(percentlinelength, 6)));
        percentageline.setOrigin(sf::Vector2f(percentlinelength/2, 0 ));
        percentageline.setPosition( sf::Vector2f(window.getSize().x/2, percentlinelengthy ));

        delaytext.setPosition(sf::Vector2f(window.getSize().x - 50, window.getSize().y - 50));

        Commentator.setFont(font);
        Commentator.setPosition(window.getSize().x/4 + 300, 20);
        Commentator.setCharacterSize(25);

        Time.setFont(font1);
        Time.setPosition(window.getSize().x/2, window.getSize().y - 50 );
        Time.setCharacterSize(20);

        displayString("Wacky Races - Text Commentary");
        //displayString("0123456789112345678921234567893123456789412345678951234567896123456789712345678981234567899");

    }
    //Game Loop + render
    while(window.isOpen())
    {
        Update(window);
        window.close();
    }
    //saving
    {
        raceover = true;
        std::cout << std::endl << "Race over\nWriting results to file..." <<std::endl;
        std::ofstream Results;
        Results.open ("Results.txt", std::ios::app);
        Results << "Race Results      " + currentDateTime() +"\n\n";
        int abcde{1};
        for (auto &p: characters)
        {
            Results << ToString(abcde) + ". " + p->name + "\n";
            abcde++;
        }
        Results << "\n\n";
        Results.close();
        std::cout << "Saving Complete" << std::endl;
    }
    Game();
}
void Game::SpecialEvent()
{
    if(!randomevent)
    {
        switch (rand() % 2 + 1)
        {
        case 1:
            displayString("Oh no! An Avalanche blocks the road! The Drivers are all mixed up\nExcept for " + characters[0]->name + " who got away scot free!");

            for(unsigned int i{1}; i < characters.size(); i++)
            {
                characters[i]->setDistance(characters[0]->getDistance() - (racelength * 0.05)); //make all drivers 5%  behind first
                characters[i]->makefrozen();
            }
            std::random_shuffle ( characters.begin()+1, characters.end());
            std::this_thread::sleep_for(std::chrono::milliseconds(3000));
            for(int i{1}; i<characters.size(); i++)
        {
            float pos = rand()%200+10;
             characters[i]->addtoDistance(pos);
        }
        characters[0]->addtoDistance(100);
            randomevent = true;
            break;
        case 2:
            for(unsigned int i{0}; i < characters.size(); i++)
            {
                characters[i]->setDistance(characters[0]->getDistance());
                characters[i]->makefrozen();
            }
            std::random_shuffle ( characters.begin(), characters.end() );
            displayString("A Bridge has collapsed!\nThe drivers are all mixed up!");
            std::this_thread::sleep_for(std::chrono::milliseconds(3000));
            for(int i{0}; i<characters.size(); i++)
        {
            float pos = rand()%200+10;
             characters[i]->addtoDistance(pos);
        }
            randomevent = true;
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            break;
        case 10:
            break;
        case 11:
            break;
        default:
            std::cout << "\n\n\nERROR: switch statement in SpecialEvent() went to default!\n\n\n\n\n" << std::endl;
            break;
        }
    }
}
