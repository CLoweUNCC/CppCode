//
//  GameEngine.cpp
//  ECGR2104_HW5
//
//  Created by Christopher Lowe on 4/22/20.
//  Copyright © 2020 Christopher Lowe. All rights reserved.
//

#include "Treasure.hpp"

using namespace std;

void gameEngine(Player& obj) {
    int userDim = 0;
    char userInput = ' ';
    
    while ((userInput != 'b') && (userInput != 'q')) {
        obj.displayRules();
        cout << "Press 'b' to begin\n";
        cin >> userInput;
    }
    
    cout << "Please enter the size of the map: ";
    cin >> userDim;
    cout << endl;
    obj.setDim(userDim);
    obj.setEnergy();
    obj.setX();
    obj.setY();

    //Random number generator
    random_device dev;
    mt19937 twist (dev()); //Pseudo random number generator
    uniform_int_distribution<size_t> u(0, (obj.getDim() - 1));     //Distributor
    
    //create a map
    const int numLands = 6;
    Land* map[obj.getDim()][obj.getDim()];    //This is an array
    
    for (int i = 0; i < obj.getDim(); ++i) {
        for (int j = 0; j < obj.getDim(); ++j) {
            switch(u(twist)% (numLands)) {
                case 0:
                    map[i][j] = new Forest;
                    break;
                case 1:
                    map[i][j] = new Desert;
                    break;
                case 2:
                    map[i][j] = new Lake;
                    break;
                case 3:
                    map[i][j] = new Orchard;
                    break;
                case 4:
                    map[i][j] = new Tundra;
                    break;
                case 5:     //rare terrain roll
                    switch(u(twist)% (numLands - 1)) {      //rare roll
                        case 0:
                            map[i][j] = new Timelost;
                            break;
                        case 1:
                            map[i][j] = new Electric;
                            break;
                        case 2:
                            map[i][j] = new Canyon;
                            break;
                        case 3:
                            map[i][j] = new SaltLake;
                            break;
                        case 4:
                            map[i][j] = new Unfinished;
                            break;
                        case 5:
                            map[i][j] = new Cubic;
                            break;
                    }
                    break;
            }
        }
    }
    
    int xPlay = obj.getX();
    int yPlay = obj.getY();
    
    while((xPlay == obj.getX()) && (yPlay == obj.getY())) {
        xPlay = u(twist);
        yPlay = u(twist);
    }
    
    delete map[xPlay][yPlay];
    map[xPlay][yPlay] = new Ruins;
    
    while((obj.getEnergy() > 0) && (obj.treasureIsFound() == 0) && (userInput != 'q')) {
        cout << "Energy remaining: " << obj.getEnergy() << endl;
        cout << "Current coordinates: X: " << obj.getX() << " Y: " << obj.getY() << endl;
        cout << "To the north ";
        if (obj.getY() < (obj.getDim()) - 1) {
            cout << map[obj.getX()][obj.getY()+1]->description() << endl;
        }
        else {
            cout << "you see an impassible mountain range.\n";
        }
        cout << "To the south ";
        if (obj.getY() > 0) {
            cout << map[obj.getX()][obj.getY()-1]->description() << endl;
        }
        else {
            cout << "you see the ocean.\n";
        }
        cout << "To the east ";
        if (obj.getX() < (obj.getDim()) - 1) {
            cout << map[obj.getX()+1][obj.getY()]->description() << endl;
        }
        else {
            cout << "you see nothing.\n";
        }
        cout << "To the west ";
        if (obj.getX() > 0) {
            cout << map[obj.getX()-1][obj.getY()]->description() << endl;
        }
        else {
            cout << "you see an endless wasteland.\n";
        }
        cin >> userInput;
        cout << endl;
        switch(userInput) {
            case 'n':
                if (obj.getY() == (obj.getDim() - 1)) {
                    obj.moveNorth();
                }
                else {
                    obj.moveNorth();
                    map[obj.getX()][obj.getY()]->visit(obj);
                }
                break;
            case 's':
                if (obj.getY() == 0) {
                    obj.moveSouth();
                }
                else {
                    obj.moveSouth();
                    map[obj.getX()][obj.getY()]->visit(obj);
                }
                break;
            case 'e':
                if (obj.getX() == (obj.getDim() - 1)) {
                    obj.moveEast();
                }
                else {
                    obj.moveEast();
                    map[obj.getX()][obj.getY()]->visit(obj);
                }
                break;
            case 'w':
                if (obj.getX() == 0) {
                    obj.moveWest();
                }
                else {
                    obj.moveWest();
                    map[obj.getX()][obj.getY()]->visit(obj);
                }
                break;
            case 'q':
                break;
            default:
                cout << "Invalid input\n";
                break;
        }
        if (obj.getEnergy() <= 0) {
            cout << endl;
            cout << "You ran out of energy and collapsed.\n";
            cout << "Better luck next time!\n";
        }
        else if ((userInput != 'q') && (obj.treasureIsFound() != 1)) {
            cout << "Press 'c' to continue\n";
            cin >> userInput;
            cout << endl;
        }
        else if (userInput == 'q'){
            cout << "Successfully quit the game." << endl;
        }
        else {
            cout << "Congratulations, you win!" << endl;
            cout << "Thank you for playing." << endl;
        }
    }
}
