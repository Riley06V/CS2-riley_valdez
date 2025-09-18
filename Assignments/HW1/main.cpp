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
    starwars::Jedi player;
    
    //Way to get something different than default health/forcePower/LightsaberSkill
    char choice;
    cout << "Is " << jediName << " a master? Y|N : ";
    cin >> choice;
    choice = toupper(choice);
    if (choice == 'Y') {
        player = starwars::Jedi (jediName, 110, 65, 85);
    } else {
        player = starwars::Jedi (jediName);
    }

    string fileName;
    cout << "Enter the name of the file you want to save to: "; //moved this line to main as it makes more sense
    cin >> fileName;
    player.saveToFile(fileName);
    player.loadFromFile(fileName);
    //Print out information
    cout << "\n You're Jedi:\n";
    cout << "Name: " << player.getName() << "\n";
    cout << "Health: " << player.getHealth() << "\n";
    cout << "LightsaberSkill: " << player.getLightsaberSkill() << "\n";
    cout << "ForcePower: " << player.getForcePower() << "\n";

    cout << jediName << " will be fighting an unknown Sith!" << endl;
    starwars::Sith enemy = starwars::Sith();

    cout << "\nSith Opponent:\n";
    cout << "Name: " << enemy.getName() << '\n';
    cout << "Health: " << enemy.getHealth() << '\n';
    cout << "Lightsaber Skill: " << enemy.getLightsaberSkill() << endl;


    cout << "The Sith provokes and attacks first!";
    //Auto Battler, Do While loop? As one is alive make them attack, use force power, based on user input
    do {
        // //Sith provokes, so they attack first This wouldn't have worked because calling funcitons instead of members.functions
        // starwars::Jedi takeDamage(starwars::Sith attack());
        // cout << jediName << "'s remaining health: " << starwars::Jedi::getHealth;
        // cout << "Unknown Sith's remaining health: " << starwars::Sith::getHealth;
        // cout << endl;
        // cout << jediName << "'s turn to attack! Please put an attack value: ";
        cout << "Sith's Attack: " << endl;
        int damageToJedi = enemy.attack();
        player.takeDamage(damageToJedi);
        cout <<player.getName() << "'s remaining health: " << player.getHealth() << "\n";

        //Jedi attacks
        cout << player.getName() << "'s attack: " << endl;
        int damageToSith = player.attack();
        enemy.takeDamage(damageToSith);
        cout << enemy.getName() << "'s remaining health: " << enemy.getHealth() << endl;

    } while (player.getHealth() > 0 || enemy.getHealth() > 0);




    return 0;
}

