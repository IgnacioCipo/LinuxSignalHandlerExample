#include <gtest/gtest.h>
#include "signalHandler.hpp"

TEST(SignalHandlerTest, ConstructionAndExitFlag) {
    SignalHandler handler;
    EXPECT_FALSE(handler.shouldExit());
}

TEST(SignalHandlerTest, HandleSIGINTSignal) {
    SignalHandler handler;
    handler.handleSignal(SIGINT);
    EXPECT_TRUE(handler.shouldExit());
}

TEST(SignalHandlerTest, HandleSIGTERMSignal) {
    SignalHandler handler;
    handler.handleSignal(SIGTERM);
    EXPECT_TRUE(handler.shouldExit());
}

TEST(SignalHandlerTest, HandleSIGUSR1Signal) {
    SignalHandler handler;
    handler.handleSignal(SIGUSR1);
    EXPECT_FALSE(handler.shouldExit());
}

TEST(SignalHandlerTest, HandleSIGUSR2Signal) {
    SignalHandler handler;
    handler.handleSignal(SIGUSR2);
    EXPECT_FALSE(handler.shouldExit());
}