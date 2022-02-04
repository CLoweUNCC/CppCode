//
//  Player.cpp
//  ECGR2104_HW5
//
//  Created by Christopher Lowe on 4/17/20.
//  Copyright © 2020 Christopher Lowe. All rights reserved.
//

#include "Player.hpp"

//Player class definitions
Player::Player() {
    
}

void Player::setDim(int num) {
    dim = num;
}

void Player::setEnergy() {
    energy = dim;
}

void Player::setX() {
    X = ((dim + 1) / 2) - 1;
}

void Player::setY() {
    Y = ((dim + 1) / 2) - 1;
}

int Player::getDim() {
    return dim;
}

int Player::getEnergy() {
    return energy;
}

int Player::getX() {
    return X;
}

int Player::getY() {
    return Y;
}

bool Player::treasureIsFound() {
    return treasureFound;
}

void Player::win() {
    treasureFound = 1;
}

void Player::incEnergy(int num) {
    energy = energy + num;
}

void Player::decEnergy(int num) {
    energy = energy - num;
}

void Player::moveNorth() {
    if (Player::getY() == (Player::getDim() - 1)) {
        cout << "You cannot move north\n";
    }
    else {
        Y = Y + 1;
    }
}

void Player::moveSouth() {
    if (Player::getY() == 0) {
        cout << "You cannot move south\n";
    }
    else {
        Y = Y - 1;
    }
}

void Player::moveEast() {
    if (Player::getX() == (Player::getDim() - 1)) {
        cout << "You cannot move east\n";
    }
    else {
        X = X + 1;
    }
}

void Player::moveWest() {
    if (Player::getX() == 0) {
        cout << "You cannot move west\n";
    }
    else {
        X = X - 1;
    }
}

void Player::displayRules() {
    cout << "This is a text-based game which takes character input (char) from the user\n";
    cout << "Your goal is to find the treasure before running out of energy\n";
    cout << "Your starting energy points will depend on the size of the map\n";
    cout << "Each \"turn\" consists of the following:\n";
    cout << "\tPhase 1: The descriptions of the areas in all four cardinal directions of the player are displayed to give the user an idea of what is around them\n";
    cout << "\tPhase 2: The user selects a direction to move in (n,s,e,w)\n";
    cout << "\tPhase 3: The outcome of the user's selection is displayed\n";
    cout << "If you run out of energy, its game over!\n\n";
    cout << "You can press 'q' at any time during a selection to quit\n";
}

