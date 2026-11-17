
#pragma once

#include <string>

class Level;

class Player {
private:
    std::string name;
    Level* level;

public:
    Player(const std::string& name, Level* level);
    void print() const;
};
