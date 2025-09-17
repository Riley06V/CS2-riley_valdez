#include <iostream>
#include "Jedi.h"
#include "Sith.h"
using namespace std;
//Now that classes are established, we work on file input and saving to file
//void saveToFile();
//void loadFromFile(); Belong in Jedi Class

int main(char argc, const char * argv[]) {
    string jediName;
    cout << "Welcome to the Star Wars auto battler Minigame" << endl;
    cout << "Enter your Jedi's Name: ";
    getline(cin, jediName);
    
    //Way to get something different than default health/forcePower/LightsaberSkill
    char choice;
    cout << "Is " << jediName << " a master? Y|N";
    cin >> choice;
    choice = toupper(choice);
    if (choice == 'Y') {
        starwars::Jedi Jedi(jediName, 110, 65, 85);
    } else {
        starwars::Jedi Jedi(jediName);
    }

    string fileName;
    cout << "Enter the name of the file you want to save to: "; //moved this line to main as it makes more sense
    cin >> fileName;
    starwars::Jedi saveToFile(fileName);
    starwars::Jedi loadFromFile(fileName);

    cout << jediName << " will be fighting an unknown Sith!" << endl;
    starwars::Sith Sith();

    //Auto Battler, Do While loop? As one is alive make them attack, use force power, based on user input
    do {
        //Sith provokes, so they attack first
        starwars::Jedi takeDamage(starwars::Sith attack());
        cout << jediName << "'s remaining health: " << starwars::Jedi::getHealth;
        cout << "Unknown Sith's remaining health: " << starwars::Sith::getHealth;
        cout << endl;
        cout << jediName << "'s turn to attack! Please put an attack value: ";

    } while (starwars::Jedi::getHealth() > 0 || starwars::Sith::getHealth > 0);




    return 0;
}

