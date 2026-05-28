
#include <iostream>
#include <memory>

#include "World.h"
#include "Player.h"
#include "AI.h"
#include "Tree.h"

int main() {

    World world;

    world.addEntity(std::make_unique<Player>("", Faction::NEW_CAMP, 100, 20, std::make_unique<Warrior>()));
    world.addEntity(std::make_unique<NPC>("Milten", Faction::OLD_CAMP, AI::NEUTRAL, 20, 100, std::make_unique<Mage>()));
    world.addEntity(std::make_unique<NPC>("Diego", Faction::OLD_CAMP, AI::ALLY, 50, 50, std::make_unique<Archer>()));
    world.addEntity(std::make_unique<NPC>("Kretoszczur", Faction::NONE, AI::ENEMY, 20, 0, std::make_unique<Creature>()));
    world.addEntity(std::make_unique<Tree>("Dąb Bartek"));


    for (auto it = world.begin(); it != world.end(); ++it) { // Odtrutka na to wyżej :)
        it->debugInfo();
    }

    world.clear();
}

/*
Oczekiwany output

Player:

    EntityID: 0
    Name: 
    Faction: New Camp
    Health: 100
    Mana: 20
    Class: Warrior

AI:

    EntityID: 1
    Name: Milten 
    Faction: Old Camp
    AI: Neutral
    Health: 20
    Mana: 100
    Class: Mage

AI:

    EntityID: 2
    Name: Diego 
    Faction: Old Camp
    AI: Ally
    Health: 50
    Mana: 50
    Class: Archer

AI:

    EntityID: 3
    Name: Kretoszczur
    Faction: None
    AI: Enemy
    Health: 20
    Mana: 0
    Class: Creature

Tree:

    EntityID: 4
    Name: Dąb Bartek

*/