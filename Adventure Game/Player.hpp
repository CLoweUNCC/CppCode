//
//  Player.hpp
//  ECGR2104_HW5
//
//  Created by Christopher Lowe on 4/17/20.
//  Copyright © 2020 Christopher Lowe. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp
#include <iostream>
#include <iomanip>

using namespace std;

class Player {
    //Private members
    int X;
    int Y;
    int energy;
    bool treasureFound = 0;
    int dim = 7;
    
public:
    Player();
    void setEnergy();
    int getEnergy();
    void setDim(int);
    int getDim();
    void incEnergy(int);
    void decEnergy(int);
    void setX();
    int getX();
    void setY();
    int getY();
    bool treasureIsFound();
    void win();
    void moveNorth();
    void moveSouth();
    void moveEast();
    void moveWest();
    void displayRules();
    
};

#endif /* Player_hpp */
