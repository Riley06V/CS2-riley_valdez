//
// Created by riley on 9/3/2025.
//

#ifndef TRUCK_H
#define TRUCK_H

#include <string>
using namespace std;



class truck {
  private:
	string make;
    string model;
    string color;
    int numOfTires;
  public:
	//Default Constructur
	truck();
	//Paramerterized Constructor
	truck(string make, string model, int numOfTires);
};



#endif //TRUCK_H
