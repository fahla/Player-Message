// functions.cpp (inside src/ folder)
#include "functions.h"
#include "Player.h"
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>


void sameprocess(const Player& player1, const Player& player2) {
    for (int i = 0; i < 10; i++) {
        player1.sendMessage(player2, "Hello, Player2!");
        player2.sendReply(player1, "Hi, Player1!");
    }

    std::cout << "Process ID for player1: " << getpid() << std::endl;
    std::cout << "Process ID for player2: " << getpid() << std::endl;
}

int differentprocess() {

    int pipefd[2]; // File descriptors for pipe
    if (pipe(pipefd) == -1) {
        std::cerr << "Pipe creation failed!" << std::endl;
        return 1;
    }

    pid_t pid = fork(); // Create a new process

    if (pid < 0) {
        std::cerr << "Fork failed!" << std::endl;
        return 1;
    }
    else if (pid > 0) {
        // Parent process (player1)
        close(pipefd[0]); // Close the read end of the pipe in the parent process

        Player player1("Player1"); // Initiator

        for (int i = 0; i < 10; i++) {
            player1.sendMessagePipe(Player("Player2"), "Hello, Player2!", pipefd[1]);
            usleep(1000); // Sleep to give the other process a chance to print
        }
        close(pipefd[1]); // Close the write end of the pipe in the parent process
        std::cout << "Process ID for player1: " << getpid() << std::endl;
        wait(NULL); // Wait for the child process to finish
    }
    else {
        // Child process (player2)
        close(pipefd[1]); // Close the write end of the pipe in the child process

        Player player2("Player2"); // Receiver

        for (int i = 0; i < 10; i++) {
            player2.sendReplyPipe(Player("Player1"), "Hi, Player1!", pipefd[0]);
            usleep(1000); // Sleep to give the other process a chance to print
        }
        close(pipefd[0]); // Close the read end of the pipe in the child process
        std::cout << "Process ID for player2: " << getpid() << std::endl;
    }
    return 0;
}
