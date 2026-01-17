#include "main.h"
#include "signalHandler.hpp"
#include <iostream>
#include <unistd.h>

using namespace std;

int main(int argc, char* argv[])
{
    cout << "========================================" << endl;
    cout << "  Linux Signal Handling Example" << endl;
    cout << "========================================" << endl;
    cout << "Process PID: " << getpid() << endl;
    cout << endl;
    
    SignalHandler signalHandler;
    signalHandler.setupSignalHandlers();
    
    cout << "\nProgram running. Press Ctrl+C to exit." << endl;
    cout << "Try sending signals from another terminal:" << endl;
    cout << "  - kill -SIGUSR1 " << getpid() << endl;
    cout << "  - kill -SIGUSR2 " << getpid() << endl;
    cout << "  - kill -SIGTERM " << getpid() << endl;
    cout << "  - kill -SIGINT " << getpid() << endl;
    cout << endl;
    
    // Main loop - waits for signals
    while (!signalHandler.shouldExit()) {
        cout << "." << flush;
        sleep(1);
    }
    
    cout << "\nProgram terminated successfully." << endl;
    return 0;
}