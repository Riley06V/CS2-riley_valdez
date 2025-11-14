#include <iostream>
#include "Character.h"
#include "Jedi.h"
#include "Sith.h"
#include <filesystem>
#include "Darth.h"
#include "Acolyte.h"
#include "Consular.h"
#include "Guardian.h"
using namespace std;
//Now that classes are established, we work on file input and saving to file
//void saveToFile();
//void loadFromFile(); Belong in Jedi Class

void battleStage(starwars::character*, starwars::character*);
void menu();
void saveFileInfo();
void compareCharacters(starwars::character*, starwars::character*);
starwars::character* properEnemy(starwars::character*);
starwars::character* createCharacter();
starwars::character* createCustomCharacter();
starwars::character* loadCharacter();

int main(int argc, const char * argv[]) {
    cout << "Welcome to the Star Wars auto battler Minigame" << endl;
    menu();
    return 0;
}

starwars::character* createCharacter() {
    cout << "Choose a character type: "
         << "\n1. Jedi"
         << "\n2. Guardian"
         << "\n3. Consular"
         << "\n4. Sith"
         << "\n5. Darth"
         << "\n6. Acolyte"
         << endl;
    int choiceType;
    cin >> choiceType;
    cout << "Name your character: ";
    cin.ignore();
    string name;
    getline(cin, name);
    switch (choiceType) {
        case 1: return new starwars::Jedi(name);
        case 2: return new starwars::Guardian(name);
        case 3: return new starwars::Consular(name);
        case 4: return new starwars::Sith(name);
        case 5: return new starwars::Darth(name); //Error undefined reference to Darth
        case 6: return new starwars::Acolyte(name);
        default: cout << "Invalid type.\n"; return nullptr;
    }
}

starwars::character* properEnemy(starwars::character* player) {
    if (player->getType() == "Jedi" || player->getType() == "Guardian" || player->getType() == "Consular") {
        srand(time(nullptr));
        int enemyType = (rand() % 100 +1);
        if (enemyType < 33) {
            return new starwars::Acolyte("Unknown Acolyte");
        }
        else if ( enemyType >=33 && enemyType < 66){
            return new starwars::Darth("Unknown Darth");
        } else {
            return new starwars::Sith("Unknown Sith");
        }
    }
    else if (player->getType() == "Sith" || player->getType() == "Darth" || player->getType() == "Acolyte") {
        srand(time(nullptr));
        int randNum = (rand() % 100 +1);
        int enemyType = randNum/3;
        if (enemyType < 33) {
            return new starwars::Guardian("Unknown Guardian");
        }
        else if (enemyType >=33 && enemyType < 66) {
            return new starwars::Consular("Unknown Council Member");
        } else {
            return new starwars::Jedi("Unknown Jedi");
        }
    }
    return nullptr;
}

void battleStage(starwars::character* player, starwars::character* enemy) {
    //Using character class, from scratch
    cout << "\nYour Character:\n";
    //Operator Overload
    cout << *player << endl;

    cout << "\nEnemy Character:\n";
    //Operator Overlaod
    cout << *enemy << endl;

    compareCharacters(player, enemy);

    cout << "\n\nThe enemy provokes and attacks first!\n";

    do {
      	int damageToPlayer = enemy->attack();
        cout <<"\n" << enemy->getName() << " attacks for " << damageToPlayer << " damage to " << player->getName() << "!" << endl;
        *player - enemy->attack();
        cout << player->getName() << " takes damage!\n";
        cout << player->getName() << " has " << player->getHealth() << " health remaining!" << endl;

        if (player->getHealth() <= 0) {
            cout << enemy->getName() << " has won this battle..." << endl;
            *enemy + enemy->getLightsaberSkill();
            cout << enemy->getName() << " rests and recovers for " << enemy->getLightsaberSkill() << " health!" << endl;
            cout << enemy->getName() << "'s health is: " << enemy->getHealth();
            break;
        }

        int damageToEnemy = player->attack();
        cout << player->getName() << " attacks for " << damageToEnemy << endl;
        *enemy - player->attack();
        cout << enemy->getName() << "'s remaining health: " << enemy->getHealth() << endl;

        if (enemy->getHealth() <= 0) {
            if (player->getType() == "Sith" || player->getType() == "Acolyte" || player->getType() == "Darth") {
                cout << player->getName() << " has cleansed the weak light side..." << endl;
                *player + player->getLightsaberSkill();
                cout << player->getName() << " rests and recovers for " << player->getLightsaberSkill() << " health!" << endl;
				cout << player->getName() << "'s health is: " << player->getHealth();

            }

            if (player->getType() == "Jedi" || player->getType() == "Guardian" || player->getType() == "Consular") {
                cout << player->getName() << " has brought balance to the force!" << endl;
                *player + player->getLightsaberSkill();
                cout << player->getName() << " rests and recovers for " << player->getLightsaberSkill() << " health!" << endl;
                cout << player->getName() << "'s health is: " << player->getHealth();
            }
            break;
        }

    } while (player->getHealth() > 0 && enemy->getHealth() > 0);
    cout << endl;
}


void menu() {
    int menuChoice;
    bool run = true;
    while (run == true) {
        cout << "1. Create a new character and run game" << endl;
        cout << "2. Load character from file and run game" << endl;
        cout << "3. View available save files " << endl;
        cout << "4. Create a custom game " << endl;
        cout << "5. Exit " << endl;
        cout << "Enter your choice: ";
        cin >> menuChoice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << "Invalid input. Please enter a number;\n";
            continue;
        }
        switch (menuChoice) {
            case 1: {
                //Proper Enemy call
                starwars::character *player = createCharacter();
                std::string fileName;
                cout << endl;
                cout << "Create a Save File (Ex: saveFile.txt): " << endl;
                getline(cin, fileName);
                //cout << fileName << "File name entered" << endl;
                if (player->getType() == "Jedi" || player->getType() == "Guardian" || player->getType() == "Consular") {
                    player->saveToFile(fileName);
                } else if (player->getType() =="Sith" || player->getType() =="Darth" || player->getType() ==  "Acolyte") {
                    player->saveToFile(fileName);
                }
                starwars::character *enemy = properEnemy(player);
                battleStage(player, enemy);
                break;
            }
            case 2: {
                starwars::character *player;
                if (!(player = loadCharacter())) {
                    cerr << "Failed to load a character" << endl;
                    break;
                }
                starwars::character *enemy = properEnemy(player);
                battleStage(player, enemy);
                break;
            }
            case 3:  {
                saveFileInfo();
                break;
            }
            case 4: {
                cout << "1. Create your character: " << endl;
                starwars::character *customPlayer = createCustomCharacter();
                cout << "2. Save to a new file (Ex. saveFile.txt): ";
                string fileName;
                cin.clear();
                cin.ignore();
                getline(cin, fileName);
                customPlayer->saveToFile(fileName);
                cout << "3. Create your enemy: " << endl;
                starwars::character *customEnemy = createCustomCharacter();
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
        cout << endl;
    }
}

starwars::character* loadCharacter() {
    string fileName;
    starwars::character *player = nullptr;
    while (true) {
        cout << "Enter the name of the save file: (Ex: saveFile.txt)   ";
        cin.clear();
        cin.ignore();
        getline(cin, fileName);
        cout << endl;

        ifstream inFile("./saves/" + fileName);
        if (!inFile.is_open()) {
            cout << "Unable to open file. Please try again.\n" << endl;
            continue;
        }
        string line, type;
        while (getline(inFile, line)) {
            if (line.find("Type: ") != string::npos) {
                type = line.substr(line.find(":")+2); //Makes sure to return the correct type as stored.
                break;
            }
        }
        if (type == "Jedi") player = new starwars::Jedi();
        else if (type == "Guardian") player = new starwars::Guardian();
        else if (type == "Consular") player = new starwars::Consular();
        else if (type == "Sith") player = new starwars::Sith();
        else if (type == "Darth") player = new starwars::Darth();
        else if (type == "Acolyte") player = new starwars::Acolyte(); //Should create a character of the correct type.
        else {
            cout << "Unkown type in file. \n";
            return nullptr;
        }

        if (player) player->loadFromFile(fileName);
        return player;
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
        cout << endl;
    }
    if (!found) {
        std::cout << "\nNo save files found in: " << savePath << std::endl;
    }
}

starwars::character* createCustomCharacter() {
    //Use existing function to make type and name
    starwars::character* base = createCharacter();
    if (!base) return nullptr;
    string type = base->getType();
    string name = base->getName();
    delete base; //discard the default instance

    int health, skill;
    std::cout << "Enter custom health: ";
    std::cin >> health;
    std::cout << "Enter custom lightsaber skill: ";
    std::cin >> skill;

    if (type == "Jedi" || type == "Guardian" || type == "Consular") {
        int force;
        std::cout << "Enter Force power: ";
        std::cin >> force;

        if (type == "Jedi") return new starwars::Jedi(name, health, skill, force);
        if (type == "Guardian") return new starwars::Guardian(name, health, skill, force);
        if (type == "Consular") return new starwars::Consular(name, health, skill, force);
    }

    if (type == "Sith" || type == "Darth" || type == "Acolyte") {
        int rage;
        std::cout << "Enter Rage level: ";
        std::cin >> rage;

        if (type == "Sith") return new starwars::Sith(name, health, skill, rage);
        if (type == "Darth") return new starwars::Darth(name, health, skill, rage);
        if (type == "Acolyte") return new starwars::Acolyte(name, health, skill, rage);
    }

    std::cout << "Unknown type.\n";
    return nullptr;
}

void compareCharacters(starwars::character* c1, starwars::character* c2) {
   if(*c1 == *c2) {
       cout << "This is an equal battle..." << endl;
   } else if (*c1 < *c2) {
       cout << c2->getName() << " has more lightsaber training than " << c1->getName() << " and is looking dangerous..." << endl;
   } else if (*c1 > *c2) {
       cout << c1->getName() << " has more lightsaber training than " << c2->getName() << " and is looking dangerous..." << endl;
   }
}
