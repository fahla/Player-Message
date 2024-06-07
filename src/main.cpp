// main.cpp (inside src/ folder)
#include "Player.h"
#include "functions.h"
#include <iostream>

int main() {

    Player player1("Player1"); // Initiator
    Player player2("Player2"); // Receiver

    std::cout << "Players in same process:" << std::endl;
    sameprocess(player1, player2);

    std::cout << "\nPlayers in different process:" << std::endl;
    differentprocess();

    return 0;
}
