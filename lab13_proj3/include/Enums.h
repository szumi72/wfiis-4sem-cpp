#pragma once
#include<string>

enum class Faction{
    NEW_CAMP,
    OLD_CAMP,
    NONE
};

inline std::string factionToString(Faction f){
    switch (f)
    {
    case Faction::NEW_CAMP: return "New Camp";
    case Faction::OLD_CAMP: return "Old Camp";
    case Faction::NONE: return "None";
    default: return "Unknown";
    }
}

enum class AI{
    NEUTRAL,
    ALLY,
    ENEMY
};

inline std::string AIToString(AI ai){
    switch (ai)
    {
    case AI::NEUTRAL: return "Neutral";
    case AI::ALLY: return "Ally";
    case AI::ENEMY: return "Enemy";
    default: return "Unknown";
    }
}

