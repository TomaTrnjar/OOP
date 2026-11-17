
#include <iostream>
#include "Player.h"
#include "Level.h"

Player::Player(const std::string& name, Level* level) {
    this->name = name;
    this->level = level;
}

void Player::print() const {
    std::cout << "Igrac: " << name << '\n';

    std::cout << "Level: neprijatelja "
              << level->enemy_count()
              << ", oruzja "
              << level->weapon_count()
              << '\n';
}
