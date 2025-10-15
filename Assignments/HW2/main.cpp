#include <iostream>
#include "Jedi.h"
#include "Sith.h"
#include <filesystem>
using namespace std;
//Now that classes are established, we work on file input and saving to file
//void saveToFile();
//void loadFromFile(); Belong in Jedi Class

void battleStage(starwars::character, starwars::character);
void menu();
void saveFileInfo();
starwars::Jedi createCustomJedi();
starwars::Sith createCustomSith();
starwars::Jedi loadJedi();

int main(int argc, const char * argv[]) {
    cout << "Welcome to the Star Wars auto battler Minigame" << endl;
    menu();
    return 0;
}

starwars::Jedi createCustomJedi() {
    string name;
    int health, skill, force;
    cout << "Enter Jedi name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Health: ";
    cin >> health;
    cout << "Lightsaber Skill: ";
    cin >> skill;
    cout << "Force Power: ";
    cin >> force;
    starwars::Jedi customeJedi(name, health, skill, force);
    return customeJedi;
}

starwars::Sith createCustomSith() {
    string name;
    int health, skill;
    cout << "Enter Sith name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Health: ";
    cin >> health;
    cout << "Lightsaber Skill: ";
    cin >> skill;
    starwars::Sith customSith(name, health, skill);
    return customSith;
}

void battleStage(starwars::character* player, starwars::character* enemy) { //Using character class, from scratch
    cout << "\nYour Character:\n";
    cout << "Name: " << player->getName() << "\n";
    cout << "Type: " << player->getType() << "\n";
    cout << "Health: " << player->getHealth() << "\n";

    cout << "\nEnemy Character:\n";
    cout << "Name: " << enemy->getName() << "\n";
    cout << "Type: " << enemy->getType() << "\n";
    cout << "Health: " << enemy->getHealth() << "\n";

    cout << "\n\nThe enemy provokes and attacks first!\n";

    do {
        int damageToPlayer = enemy->attack();
        cout << enemy->getName() << " attacks for " << damageToPlayer << " damage to" << player->getName() << "!" << endl;
        player->takeDamage(damageToPlayer);
        cout << player->getName() << " takes damage!\n";
        cout << player->getName() << " has " << player->getHealth() << " health remaining!" << endl;

        if (player->getHealth() <= 0) {
            cout << enemy->getName() << " has won this battle..." << endl;
            break;
        }

        int damageToEnemy = player->attack();
        cout << player->getName() << " attacks for " << damageToEnemy << endl;
        enemy->takeDamage(damageToEnemy);
        cout << enemy->getName() << "'s remaining health: " << enemy->getHealth() << endl;

        if (enemy->getHealth() <= 0) {
            if (player->getType() == "Sith" || player->getType() == "Acolyte" || player->getType() == "Darth") {
                cout << player->getName() << " has cleansed the weak light side..." << endl;
            }

            if (player->getType() == "Jedi" || player->getType() == "Guardian" || player->getType() == "Consular") {
                cout << player->getName() << " has brought balance to the force!" << endl;
            }
        break;
    }

} while (player->getHealth() > 0 && enemy->getHealth() > 0);


starwars::Jedi loadJedi() {
    string fileName;
    cout << "Enter the name of the save file: (Ex: saveFile.txt)   ";
    cin.ignore();
    getline(cin, fileName);
    starwars::Jedi player;
    player.loadFromFile(fileName);
    cout << player.getName() << " from file: " << fileName << " is stepping in..." << endl;
    return player;
}


void menu() {
    int menuChoice;
    bool run = true;
    while (run == true) {
        cout << "1. Create a new Jedi and run game" << endl;
        cout << "2. Load Jedi from file and run game" << endl;
        cout << "3. View available save files " << endl;
        cout << "4. Create a modified game " << endl;
        cout << "5. Exit " << endl;
        cout << "Enter your choice: ";
        cin >> menuChoice;
        switch (menuChoice) {
            case 1: {
                string jediName;
                cout << "Enter your Jedi's Name: ";
                cin.ignore();
                getline(cin, jediName);
                starwars::Jedi player;

                //Way to get something different than default health/forcePower/LightsaberSkill
                char choice;
                cout << "Is " << jediName << " a master? Y|N : ";
                cin >> choice;
                choice = toupper(choice);
                if (choice == 'Y') {
                    player = starwars::Jedi (jediName, 115, 70, 90);
                } else {
                    player = starwars::Jedi (jediName);
                }

                starwars::Sith enemy = starwars::Sith();


                string fileName;
                cout << "Enter the name of the file you want to save to: (Ex: saveFile.txt)   "; //moved this line to main as it makes more sense
                cin >> fileName;
                player.saveToFile(fileName);
                player.loadFromFile(fileName);

                battleStage(player, enemy);
                break;
            }
            case 2: {
                starwars::Jedi loadedJedi = loadJedi();
                starwars::Sith defaultEnemy;
                battleStage(loadedJedi, defaultEnemy);
                break;
            }
            case 3:  {//To be worked on
                saveFileInfo();
                break;
            }
            case 4: {
                starwars::Jedi customPlayer = createCustomJedi();
                starwars::Sith customEnemy = createCustomSith();
                battleStage(customPlayer, customEnemy);
                break;
            }
            case 5: {
                cout << "Exiting... May the Force be with you." << endl;
                run = false;
                break;
            }
            default: {
                cout << "Invalid choice... Try again." << endl;
                break;
            }
        }
    }
}

void saveFileInfo() {
    cout << "\nAvailable Save Files: ";
    string savePath = "./saves"; //creates string variable for directory "saves"
    if (!filesystem::exists(savePath)) { //checks to make sure savePath exists
        filesystem::create_directory(savePath); //makes sure to create it with same name
        return;
    }
    bool found = false;
    for (const auto& entry : filesystem::directory_iterator(savePath)) { //iterates through single directory with name of savePath
        if (entry.path().extension() == ".txt") { //opens only files saved as .txt
            std::cout << " - " << entry.path().filename().string() << endl; //used cppreference.com
            found = true;
        }
    }
    if (!found) {
        std::cout << "No save files found in: " << savePath << std::endl;
    }
}

