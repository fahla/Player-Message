// Player.cpp (inside src/ folder)
#include "Player.h"
#include <iostream>
#include <unistd.h> //for fork

Player::Player(const std::string& playerName) : name(playerName), counter(0) {}

void Player::sendMessage(const Player& receiver, const std::string& message) const {
    std::cout << name << " sends message to " << receiver.getName() << ": " << message << std::endl;
}

void Player::sendReply(const Player& initiator, const std::string& message) const {
    counter++; // Incrementing counter
    std::cout << name << " replies to " << initiator.getName() << ": " << message << counter << std::endl;
}

void Player::sendMessagePipe(const Player& receiver, const std::string& message, int pipefd) const {
    std::cout << name << " sends message to " << receiver.getName() << ": " << message << std::endl;
    write(pipefd, "1", 1); // Write to the pipe to signal message sent
}

void Player::sendReplyPipe(const Player& initiator, const std::string& message, int pipefd) const {
    char buf;
    read(pipefd, &buf, 1); // Wait until message is sent
    counter++; //Incrementing Counter
    std::cout << name << " replies to " << initiator.getName() << ": " << message << counter << std::endl;
}

std::string Player::getName() const {
    return name;
}
