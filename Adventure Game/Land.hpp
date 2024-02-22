//
//  Land.hpp
//  ECGR2104_HW5
//
//  Created by Christopher Lowe on 4/20/20.
//  Copyright © 2020 Christopher Lowe. All rights reserved.
//

#ifndef Land_hpp
#define Land_hpp
#include <iostream>
#include <string>
#include "Player.hpp"

class Land {
public:
    virtual string description() = 0;
    virtual void visit(Player&) = 0;
};

class Desert : public Land {
  string description() {
      return "you see an expansive desert.";
  }
  void visit(Player& obj) {
      cout << "You trek through the arid desert that seems to go on for miles.\n" << "You lost 2 energy points!\n";
      obj.decEnergy(2);
  }
};

class Tundra : public Land {
    string description() {
        return "you see a frozen tundra.";
    }
    void visit(Player& obj) {
        cout << "You hike through the tundra. It is extremely cold, especially with the wind blowing.\n" << "You lost 3 energy points!\n";
        obj.decEnergy(3);
    }
};

class Forest : public Land {
  string description() {
      return "you see a large forest.";
}
  void visit(Player& obj) {
      cout << "You trek through the dense forest.\n" << "You lost 1 energy point!\n";
      obj.decEnergy(1);
  }
};

//FIXME: rare generations go here, a "rare" land will only generate upon the PRNG rolling a specified number, and then a second number will be rolled (between 11 and ??) to determine which one is generated. These are meant to be the incredibly odd/interesting generations such as the ones shown below

class Timelost : public Land {
//NOTE: this is a rare generation (rare roll: 0)
    string description() {
        return "the land is strangely still.";
    }
    void visit(Player& obj) {
        cout << "As you walk, you realize that everything is completely frozen. Not in ice or snow, but just completely still, as if time had suddenly stopped. Even the leaves that were falling from the trees are merely suspended in midair\n" << "In this strange land, you neither gained nor lost energy. Odd\n";
    }
};

//class Volcano : public Land {
//NOTE: this is a rare generation (rare roll: 12)
//description: you see ash falling from the sky.
//outcome: "As you walk through the ash-covered land, you suddenly see the source of both the ash and the immense heat you have been feeling. Its a volcano!\n" << "It seems to be inactive at the moment, but who knows when it could erupt? Not wanting to wait around and see, you quickly run through the area.\n" << "You lost [] energy points!\n";

class Electric : public Land {
//NOTE: this is a rare generation (rare roll: 1)
    string description() {
        return "you see dark hills with what appears to be lightning channeling through the...ground?";
    }
    void visit(Player& obj) {
        cout << "You walk towards the strange electrified land. Curiously, even though there is clearly high amounts of electricity coursing through the deep black ground beneath you, you are not hurt. In fact, you actually feel slightly energized.\n" << "You gained 2 energy points!\n";
        obj.incEnergy(2);
    }
};

class Canyon : public Land {
//NOTE: this is a rare generation (rare roll: 2)
    string description() {
        return "you see a deep canyon.";
    }
    void visit(Player& obj) {
        cout << "You head towards the canyon. It is too wide to expect to find anything to cross over it with. You trek downwards deeper into the canyon, reach the bottom, and then hike back up on the other side. You feel incredibly tired afterwards.\n" << "You lost 3 energy points!\n";
        obj.decEnergy(3);
    }
};

class SaltLake : public Land {
//NOTE: this is a rare generation (rare roll: 3)
    string description() {
        return "you see a lake that is surrounded by sand, and the land is barren. An oasis perhaps?";
    }
    void visit(Player& obj) {
        cout << "While passing the lake, you take a small drink to quench your thirst.\n" << "You immediately spit out the water. Its full of salt! Afterwards, you continue on past the salt lake.\n" << "You lost 1 energy point!\n";
        obj.decEnergy(1);
    }
};

//class Darkness : public Land {
//NOTE: this is a rare generation (rare roll: 15)
//description: it is very dark
//outcome: "You trek towards the darkness. It is absolutely pitch-black, to the point where you cannot even see your hand in front of your face, or anything for that matter. After stumbling around in the dark for quite some time, you eventually make it out, but not before tripping numerous times and walking into trees\n" << "You lost 3 energy points!\n";

class Unfinished : public Land {
//NOTE: this is a rare generation (rare roll: 4)
    string description() {
        return "you see [description]";
    }
    void visit (Player& obj) {
        cout << "You walk towards a blank, white land consisting of nothing more than a few hills. It appears the developer either accidently added another generation, or forgot to add to it.\n" << "Because of the developer's incompetance and for letting unfinished content slip into the final game, he has been fired, and a replacement has been hired in his place.\n" << "Because the new developer is still in training and does not know how to fix this yet, you did not lose any energy\n";
    }
};

class Cubic : public Land {
//NOTE: this is a rare generation (rare roll: 5)
    string description() {
        return "everything looks incredibly cubic.";
    }
    void visit(Player& obj) {
        cout << "You hike towards the cubic land. Nothing much to say here, its just as if someone took your regular, generic grassland and made everything cubic. [Insert Minecraft-related easter egg here]\n" << "[Energy gain/loss neutral]\n";
    }
};

//FIXME: add more rare generations
//FIXME: end of rare generations

class Lake : public Land {
  string description() {
      return "you see a lake that is surrounded by lush green grass and other vegetation.";
}
  void visit(Player& obj) {
      cout << "While passing the lake, you take a small drink to quench your thirst.\n" << "You gained 1 energy point!\n";
      obj.incEnergy(1);
  }
};

class Orchard : public Land {
  string description() {
      return "you see what appears to be an orchard.";
  }
  void visit(Player& obj) {
      cout << "The orchard you are passing through is full of apples. Nobody seems to be watching, and you are sure that the owner would be able to part with a single apple, so you take an apple from a nearby tree.\n" << "You gained 2 energy points!\n";
      obj.incEnergy(2);
  }
};

class Ruins : public Land {
    string description() {
          return "you see the outline of a strange structure...";
    }
    void visit(Player& obj) {
        cout << "You approach the strange structure. The structure appears to be the ruins you were looking for, and, after searching around for a bit, you found the treasure!\n";
        obj.win();
    }
};

#endif /* Land_hpp */

