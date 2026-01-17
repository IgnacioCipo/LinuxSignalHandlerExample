#include <csignal>
#include <atomic>

class SignalHandler
{
    public:
        SignalHandler();
        ~SignalHandler();

        void setupSignalHandlers();
        static void signalHandlerFunction(int signal);
        void handleSignal(int signal);
        bool shouldExit() const;
        
    private:
        static SignalHandler* instance;
        std::atomic<bool> exitFlag;
};