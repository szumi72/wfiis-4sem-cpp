
#include <iostream>
#include <string>

#include "EventBus.h"
#include "Enemy.h"
#include "Player.h"
#include "ScoreSystem.h"
#include "LootSystem.h"
#include "SoundSystem.h"

int main() {

    EventBus bus;

    bus.subscribe(&ScoreSystem::handleEvent);
    bus.subscribe(&LootSystem::handleEvent);
    bus.subscribe(&SoundSystem::handleEvent);

    Enemy enemy1(1, 50, bus);
    Enemy enemy2(2, 30, bus);
    Player player(1, 100, bus);

    enemy1.takeDamage(20);
    enemy2.takeDamage(40);

    player.heal(25);
    player.pickItem("Łomotacz");

    enemy1.takeDamage(40);


    bus.processEvents();

    return 0;
}

