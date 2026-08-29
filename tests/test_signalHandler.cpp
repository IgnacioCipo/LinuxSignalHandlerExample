#include <gtest/gtest.h>
#include "signalHandler.hpp"

class SignalHandlerTest : public ::testing::Test {
    protected:
        void SetUp() override {

        }
        void TearDown() override {

        }
        SignalHandler handler;
};

TEST_F(SignalHandlerTest, ConstructionAndExitFlag) {
    SignalHandler handler;
    EXPECT_FALSE(handler.shouldExit());
}

TEST_F(SignalHandlerTest, HandleSIGINTSignal) {
    SignalHandler handler;
    handler.handleSignal(SIGINT);
    EXPECT_TRUE(handler.shouldExit());
}

TEST_F(SignalHandlerTest, HandleSIGTERMSignal) {
    SignalHandler handler;
    handler.handleSignal(SIGTERM);
    EXPECT_TRUE(handler.shouldExit());
}

TEST_F(SignalHandlerTest, HandleSIGUSR1Signal) {
    SignalHandler handler;
    handler.handleSignal(SIGUSR1);
    EXPECT_FALSE(handler.shouldExit());
}

TEST_F(SignalHandlerTest, HandleSIGUSR2Signal) {
    SignalHandler handler;
    handler.handleSignal(SIGUSR2);
    EXPECT_FALSE(handler.shouldExit());
}

TEST_F(SignalHandlerTest, HandleSIGPIPESignal) {
    SignalHandler handler;
    handler.handleSignal(SIGPIPE);
    EXPECT_FALSE(handler.shouldExit());
}

TEST_F(SignalHandlerTest, HandleSIGSEGVSignal) {
    SignalHandler handler;
    handler.handleSignal(SIGSEGV);
    EXPECT_TRUE(handler.shouldExit());
}