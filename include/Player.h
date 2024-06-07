// Player.h (inside include/ folder)
#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {
private:
    std::string name;
    mutable int counter = 0; // mutable Counter

public:
    Player(const std::string& playerName);

    void sendMessage(const Player& receiver, const std::string& message) const;
    void sendReply(const Player& initiator, const std::string& message) const;
    void sendMessagePipe(const Player& receiver, const std::string& message, int pipefd) const;
    void sendReplyPipe(const Player& initiator, const std::string& message, int pipefd) const;
    std::string getName() const;
};

#endif // PLAYER_H
