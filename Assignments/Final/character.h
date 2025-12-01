//
// Created by riley on 12/1/2025.
//

#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>


class character {
protected:
	//player info
	std::string _name;
	int _health;
	int _atkPower;
	//position
	int _x;
	int _y;
public:
  	//constructor
  	character(std::string name, int health, int atkPower, int xPos, int yPos);
	//Deconstructor
	virtual ~character();

	//setters
	void setName(std::string name);
	void setHealth(int health);
	void setAtkPower(int atkPower);
	void setX(int xPos);
	void setY(int yPos);
	//getters
	std::string getName();
	int getHealth();
	int getAtkPower();
	int getX();
	int getY();
	//helpers
	void takeDamage(int damage);
    void attack();
	bool isAlive();
};




#endif //CHARACTER_H
