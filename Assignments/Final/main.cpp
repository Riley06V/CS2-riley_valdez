#include <iostream>
#include <ctime> //for timed enemy attacks
#include <cstdlib>
#include <termios.h> // capture single keypresses without enter
#include <unistd.h> //capture for single keypresses
#include "dungeon.h"
#include "room.h"
#include "player.h"
#include "enemy.h"
#include "item.h"

using namespace std;

void draw(const room* rm, const player* p, dungeon& dungeon);
char getch(); //from stack overflow: https://stackoverflow.com/questions/421860/capture-characters-from-standard-input-without-waiting-for-enter-to-be-pressed
void movement(dungeon& dungeon, player& player);
void combatLoop(player& player, enemy* enemy);
bool askMathProblem(const enemy* e);
void openInventory(player& player);
void linkRooms(room* currentRoom, room* nextRoom, int doorX, int doorY);
player* createPlayer();
bool startMenu();


int main(int argc, char *argv[]) {
    srand(time(nullptr));

    if (!startMenu()) {
        std::cout << "Goodbye!\n";
        return 0;
    }
    // Build dungeon
    dungeon dungeonGame;
    // Room 1: Entry Hall
    std::vector<std::string> grid1 = {
        "##########",
		"#........#",
		"#..###...#",
		"#....#...#",
		"#....##..#",
		"#.....#.D#",
		"##.......#",
		"###.....!#",
		"####.....#",
		"##########"


    };

	std::vector<std::string> grid2 = {
		"##########",
		"#P.......#",
		"#..#!#...#",
		"#........#",
		"#..#.....#",
		"#..#.###.#",
		"#..###...#",
		"#.D......#",
		"#........#",
		"##########"
	};


    std::vector<std::string> grid3 = {
		"##########",
		"#P.......#",
		"#........#",
		"#..#####.#",
		"#..#.....#",
		"#..#.....#",
		"#..#####.#",
		"#........#",
		"#..D.....#",
		"##########"

    };

    std::vector<std::string> grid4 = {
        "##########",
		"#P.......#",
		"#........#",
		"#..###...#",
		"#..#..D..#",
		"#..###...#",
		"#........#",
		"#........#",
		"#........#",
		"##########"
    };

    std::vector<std::string> grid5 = {
		"##########",
		"#P.......#",
		"#........#",
		"#..###...#",
		"#..#.....#",
		"#..###...#",
		"#........#",
		"#........#",
		"#.......D#",
		"##########"
    };
    std::vector<std::string> grid6 = {
		"##########",
		"#P.......#",
		"#........#",
		"#........#",
		"#........#",
		"#........#",
		"#........#",
		"#........#",
		"#........#",
		"##########"
    };

    room* r1 = new room("A damp stone chamber", grid1, false);
    dungeonGame.addRoom(r1);
    // Room 2: Armory Maze

    room* r2 = new room("Rusty weapons line the walls", grid2, false);
    dungeonGame.addRoom(r2);

    // Room 3: Arcane Library
    room* r3 = new room("Dusty tomes and broken shelves litter the floor", grid3, false);
    dungeonGame.addRoom(r3);

    // Room 4: Barracks Crossroads
    room* r4 = new room("Old bunks and broken armor scattered around", grid4, false);
    dungeonGame.addRoom(r4);

    // Room 5: Treasury Antechamber
    room* r5 = new room("A grand hall with cracked marble pillars", grid5, false);
    dungeonGame.addRoom(r5);

    // Room 6: Trophy Room (Victory)
    room* r6 = new room("The final chamber, glowing with victory", grid6, true);
    dungeonGame.addRoom(r6);

    // Link rooms
    linkRooms(r1, r2, 5, 8);
    linkRooms(r2, r3, 2, 7);
    linkRooms(r3, r4, 8, 3);
    linkRooms(r4, r5, 4,6);
    linkRooms(r5, r6, 8, 8);

    // Create player
    player* hero = createPlayer();
    hero->setCurrentRoom(r1);
    hero->setX(1);
    hero->setY(1);

    // Add enemies/items
    r1->setEnemy(new goblin(2,2));
    r1->addHiddenEnemy(2,2);
    r2->setEnemy(new goblin(3,3));
    r2->addHiddenEnemy(3,3);
    r3->setEnemy(new skeleton(5,5));
    r3->addHiddenEnemy(5,5);
    r4->setEnemy(new skeleton(6,6));
    r4->addHiddenEnemy(6,6);
    r5->setEnemy(new mage(4,4));
    r5->addHiddenEnemy(4,4);

    consumable_Item* potion = new consumable_Item("Potion", "Restores Health", 7,8, 25);
    r1->addItem(potion);
    damage_Boost_Item* rustySword = new damage_Boost_Item("Rusty Sword", "Pulled off the walls of the armory", 5, 2, 5, 100);
    r2->addItem(rustySword);

    // Main loop
    while (true) {
        draw(dungeonGame.getCurrentRoom(), hero, dungeonGame);
        movement(dungeonGame, *hero);

        if (hero->getHealth() <= 0) {
            cout << "You have fallen...\n";
            break;
        }
        if (dungeonGame.getCurrentRoom()->isTreasureRoom()) {
            cout << "You reached the trophy room! Victory!\n";
            break;
        }
    }
    return 0;
}


void draw(const room* rm, const player* p, dungeon& dungeon) {
  system("clear"); // clear terminal for fresh redraw

  if (!rm) {
    cout << "No room loaded." << endl;
    return;
  }

  // Print room description first
  cout << "\t\t\tWelcome to the Dungeon of Basic Mathematics!" << endl;
  cout << "\t\t\t\t\tRoom: " << dungeon.getCurrentRoomLevel() << " of " << dungeon.size() << endl;

  cout << "\t\t\tControls: W/A/S/D = Move | E = Inventory | Q = Quit\n";
  cout << "\t\t\t---------------------------------------------------\n";

  cout << rm->getDescription() << "\n\n";
  // Render ASCII grid with player overlay
  const auto& lines = rm->renderAscii(p);
  for (const auto& line : lines) {
    cout << line << "\n";
  }

  // Print player stats
  cout << "\n" << p->getName()
            << " | HP: " << p->getHealth()
            << " | ATK: " << p->getAtkPower()
            << " | DEF: " << p->getDefense()
            << "\n";
}

char getch() { //for movement keys
  char buf = 0;
  struct termios old = {0};
  if (tcgetattr(0, &old) < 0)
    perror("tcsetattr()");
  old.c_lflag &= ~ICANON;
  old.c_lflag &= ~ECHO;
  old.c_cc[VMIN] = 1;
  old.c_cc[VTIME] = 0;
  if (tcsetattr(0, TCSANOW, &old) < 0)
    perror("tcsetattr ICANON");
  if (read(0, &buf, 1) < 0)
    perror ("read()");
  old.c_lflag |= ICANON;
  old.c_lflag |= ECHO;
  if (tcsetattr(0, TCSADRAIN, &old) < 0)
    perror ("tcsetattr ~ICANON");
  return (buf);
}

void movement(dungeon& dungeon, player& player) {
  char ch = getch();
  int nx = player.getX();
  int ny = player.getY();

  if (ch == 'w' || ch == 'W') ny--;
  else if (ch == 's' || ch == 'S') ny++;
  else if (ch == 'a' || ch == 'A') nx--;
  else if (ch == 'd' || ch == 'D') nx++;
  else if (ch == 'e' || ch == 'E') openInventory(player);
  else if (ch == 'q' || ch == 'Q') {
    cout << "Are you sure you want to quit? Y|N" << endl;
    char quitChoice;
    cin >> quitChoice;
    if (quitChoice == 'N' || quitChoice == 'n') {
      return;
    } else if (quitChoice == 'Y' || quitChoice == 'y') {
      exit(0);
    }
  }

  room* rm = dungeon.getCurrentRoom();
  if(!rm) return;

  if(rm->canMoveTo(nx, ny)) {
    player.setX(nx);
    player.setY(ny);

    if (rm->isItem(nx, ny)) {
      char askPickupItem;
      cout << "You found an item...\n";
      cout << "Would you like to pick it up? Y|N";
      cin >> askPickupItem;
      if (askPickupItem == 'N' || askPickupItem == 'n') {
        return;
      } else if (askPickupItem == 'Y' || askPickupItem == 'y') {
        item* found = rm->getItems()[0];
        player.addItem(found);
        rm->pickupItemAt(nx, ny);
        cout << "You picked up an item!\n";
      }
    }
    if(rm->isEnemy(nx, ny)) {
      if (rm->revealEnemyAt(nx, ny)) {
        combatLoop(player, rm->getEnemy());
      }
    }
    if(rm->isDoor(nx, ny)) {
      if(dungeon.moveNext()) {
        player.setX(1);
        player.setY(1);
      } else {
        cout << "No more rooms.";
      }
    }
    else if (rm->isPrevDoor(nx, ny)) {
      if(dungeon.movePrevious()) {
        room* prev = dungeon.getCurrentRoom();
        if(prev) {
          auto [px, py] = prev->getDoor();
          player.setX(px);
          player.setY(py);
        }
      } else {
        cout << "No previous rooms.";
      }
    }
  }
}

bool askMathProblem(const enemy* enemy) {
  int a = rand() % 10 + 1;
  int b = rand() % 10 + 1;
  int ans;

  switch (enemy->getDifficultyLevel()) {
  case 1: // addition
    cout << "Solve: " << a << " + " << b << " = ";
    cin >> ans;
    return ans == a + b;
  case 2: // subtraction
    cout << "Solve: " << a << " - " << b << " = ";
    cin >> ans;
    return ans == a - b;
  case 3: // multiplication
    cout << "Solve: " << a << " * " << b << " = ";
    cin >> ans;
    return ans == a * b;
  case 4: // division
    cout << "Solve: " << a*b << " / " << a << " = ";
    cin >> ans;
    return ans == b; // ensures integer division
  default:
    return false;
  }
}

void combatLoop(player& player, enemy* enemy) {
  system("clear");
  cout<< "Surprise!" << endl;
  cout << "Starting combat against: " << enemy->getName() << "\n\n\n\n" << endl;
  time_t lastAttack = time(nullptr);
  room* rm = player.getCurrentRoom();

  while (player.getHealth() > 0 && enemy->getHealth() > 0) {
    time_t now = time(nullptr);

    // Enemy attack timer
    if (difftime(now, lastAttack) >= 5.0) {
      int edmg = enemy->attack();
      player.takeDamage(edmg);
      cout << enemy->getName() << " strikes for "
                << edmg << " damage! "
                << player.getName() << " HP: "
                << player.getHealth() << "\n";
      lastAttack = now;
    }

    // Player input (math problem)
    if (askMathProblem(enemy)) {
      int dmg = player.attack();
      enemy->takeDamage(dmg);
      cout << "You hit for " << dmg << " damage! "
                << enemy->getName() << " HP: "
                << enemy->getHealth() << "\n";
    } else {
      cout << "Wrong answer! Enemy counter-attacks!\n";
      int edmg = enemy->attack();
      player.takeDamage(edmg);
      cout << enemy->getName() << " punishes you for "
                << edmg << " damage! "
                << player.getName() << " HP: "
                << player.getHealth() << "\n";
    }
  }

  if (player.getHealth() <= 0) {
    cout << "You were defeated...\n";
  } else {
    cout << "Enemy defeated!\n";
    item* drop = enemy->createDrop();
    if (drop) {
      rm->addItem(drop);
      cout << enemy->getName() << " dropped "
                << drop->getName() << "!\n";
    }
  }
}


void openInventory(player& player) {
  bool done = false;
  while (!done) {
    system("clear"); // WSL/Linux
    player.showInventory();

    cout << "\nOptions:\n";
    cout << "  U: Use/Equip an item\n";
    cout << "  W: Unequip weapon\n";
    cout << "  A: Unequip armor\n";
    cout << "  Q: Close inventory\n";
    cout << "Choice: ";

    char choice = getch();
    if (choice == 'q' || choice == 'Q') {
      done = true;
    } else if (choice == 'u' || choice == 'U') {
      cout << "Enter item number: ";
      int idx;
      cin >> idx;
      if (idx >= 0 && idx < player.getCurrentItemCount()) {
        item* it = player.getItemAt(idx); // direct access
        if (it) {
          it->use(player); // polymorphic call
        }
      }
    } else if (choice == 'w' || choice == 'W') {
      player.unequipWeapon(player.getCurrentRoom());
    } else if (choice == 'a' || choice == 'A') {
      player.unequipArmor(player.getCurrentRoom());
    }
  }
}

void linkRooms(room* currentRoom, room* nextRoom, int doorX, int doorY) {
  if (!currentRoom || !nextRoom) return;
  currentRoom->setDoor(doorX, doorY);
  nextRoom->setPrevDoor(1, 1);
}

player* createPlayer() {
  string name;
  cout << "Enter your hero's name: ";
  getline(cin, name);
  //basic stats
  int hp = 50;
  int atk = 1;
  int def = 0;

  cout << "Welcome, " << name << "! Your adventure begins... \n";
  return new player(name, 1,1, hp, atk, def);
}

bool startMenu() {
    cout << "=============================\n";
    cout << "   Dungeon of Basic Math\n";
    cout << "=============================\n";
    cout << "1. Begin Adventure\n";
    cout << "2. Quit\n";
    cout << "Choose an option: ";

    int choice;
    cin >> choice;
    cin.ignore();

    return(choice == 1);
}
