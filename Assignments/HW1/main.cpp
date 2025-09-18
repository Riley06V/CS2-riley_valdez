#include <iostream>
#include "Jedi.h"
#include "Sith.h"
using namespace std;
//Now that classes are established, we work on file input and saving to file
//void saveToFile();
//void loadFromFile(); Belong in Jedi Class

void battleStage(starwars::Jedi, starwars::Sith);
void menu();
void saveFileInfo();
starwars::Jedi createCustomJedi();

int main(int argc, const char * argv[]) {
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
    cout << "\nYour Jedi:\n";
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

    battleStage(player, enemy);

    return 0;
}

starwars::Jedi createCustomJedi() {
    std::string name;
    int health, skill, force;
    std::cout << "Enter Jedi name: ";
    std::cin >> name;
    std::cout << "Health: ";
    std::cin >> health;
    std::cout << "Lightsaber Skill: ";
    std::cin >> skill;
    std::cout << "Force Power: ";
    std::cin >> force;
    return starwars::Jedi(name, health, skill, force);
}

void battleStage(starwars::Jedi player, starwars::Sith enemy) {
    cout << "\n\nThe Sith provokes and attacks first!";
    //Auto Battler, Sith attacks first, Jedi Goes second. Completely based on class attributes.
    do {

        cout << "Sith's Attack: " << enemy.attack() << endl;
        int damageToJedi = enemy.attack();
        player.takeDamage(damageToJedi);
        cout <<player.getName() << "'s remaining health: " << player.getHealth() << "\n";

        if (player.getHealth() <= 0) {
            cout << "The Sith has Won this time..." << endl;
            break;
        }

        //Jedi attacks
        cout << player.getName() << "'s attack: " << player.attack() << endl;
        int damageToSith = player.attack();
        enemy.takeDamage(damageToSith);
        cout << enemy.getName() << "'s remaining health: " << enemy.getHealth() << endl;

        if (enemy.getHealth() <= 0) {
            cout << player.getName() << " has brought balance to the force!" << endl;
            break;
        }

    } while (player.getHealth() > 0 || enemy.getHealth() > 0);
}