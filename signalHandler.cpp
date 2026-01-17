#include "signalHandler.hpp"
#include <csignal>
#include <iostream>
#include <unistd.h>

SignalHandler* SignalHandler::instance = nullptr;

/** 
 * Constructor
 */
SignalHandler::SignalHandler() : exitFlag(false)
{
    instance = this;
}

/**
 * Destructor
 */
SignalHandler::~SignalHandler()
{
    instance = nullptr;
}

/**
 * Sets up handlers for multiple signals
 */
void SignalHandler::setupSignalHandlers()
{
    struct sigaction sa;
    sa.sa_handler = signalHandlerFunction;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    // Register SIGINT (Ctrl+C)
    if (sigaction(SIGINT, &sa, nullptr) == -1) {
        std::cerr << "Error registering SIGINT" << std::endl;
    }

    // Register SIGTERM (graceful termination)
    if (sigaction(SIGTERM, &sa, nullptr) == -1) {
        std::cerr << "Error registering SIGTERM" << std::endl;
    }

    // Register SIGUSR1 (user-defined signal)
    if (sigaction(SIGUSR1, &sa, nullptr) == -1) {
        std::cerr << "Error registering SIGUSR1" << std::endl;
    }

    // Register SIGUSR2 (user-defined signal)
    if (sigaction(SIGUSR2, &sa, nullptr) == -1) {
        std::cerr << "Error registering SIGUSR2" << std::endl;
    }

    std::cout << "Signal handlers configured successfully" << std::endl;
    std::cout << "You can send signals with: kill -SIGUSR1 " << getpid() << std::endl;
}

/**
 * Static handler that delegates to the instance method
 */
void SignalHandler::signalHandlerFunction(int signal)
{
    if (instance != nullptr) {
        instance->handleSignal(signal);
    }
}

/**
 * Handles the received signal
 */
void SignalHandler::handleSignal(int signal)
{
    switch(signal) {
        case SIGINT:
            std::cout << "\n[SIGNAL] SIGINT received (Ctrl+C). Exiting..." << std::endl;
            exitFlag = true;
            break;
        case SIGTERM:
            std::cout << "\n[SIGNAL] SIGTERM received. Graceful termination..." << std::endl;
            exitFlag = true;
            break;
        case SIGUSR1:
            std::cout << "\n[SIGNAL] SIGUSR1 received. User-defined signal 1." << std::endl;
            break;
        case SIGUSR2:
            std::cout << "\n[SIGNAL] SIGUSR2 received. User-defined signal 2." << std::endl;
            break;
        default:
            std::cout << "\n[SIGNAL] Unknown signal: " << signal << std::endl;
            break;
    }
}

/**
 * Checks if the program should exit
 */
bool SignalHandler::shouldExit() const
{
    return exitFlag;
}