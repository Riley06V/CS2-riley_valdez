//
// Created by riley on 12/1/2025.
//

#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>


class character {
protected:
	//player info
	std::string name;
	int health;
	int atkPower;
	//position
	int x;
	int y;
public:
  	//constructor
  	character(std::string name, int health, int atkPower, int xPos, int yPos);
	//Deconstructor
	virtual ~character();

	//setters
	void setName();
	void setHealth();
	void setAtkPower();
	void setX();
	void setY();
	//getters
	std::string getName();
	int getHealth();
	int getAtkPower();
	int getX();
	int getY();
	//helpers
	void takeDamage(int damage);
	bool isAlive();
};




#endif //CHARACTER_H
