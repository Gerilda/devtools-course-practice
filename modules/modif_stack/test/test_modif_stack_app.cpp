// Copyright 2019 Trubina Anastasia

#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "include/modif_stack_app.h"

class ModifStackAppTest : public ::testing::Test {
protected:
    void Act(std::vector<std::string> args_) {
        std::vector<const char*> options;

        options.push_back("application");
        for (size_t i = 0; i < args_.size(); ++i) {
            options.push_back(args_[i].c_str());
        }

        const char** argv = &options.front();
        int argc = static_cast<int>(args_.size()) + 1;

        output_ = app_(argc, argv);
    }
    void Assert(std::string expected) {
        EXPECT_TRUE(::testing::internal::RE::PartialMatch(output_,
                ::testing::internal::RE(expected)));
    }
private:
    ModifStackApp app_;
    std::string output_;
};

TEST_F(ModifStackAppTest, Do_Print_Help_Without_Arguments) {
    // Arrange
    std::vector<std::string> args = {};

    Act(args);

    Assert("This is application for modific stack class");
}

TEST_F(ModifStackAppTest, Recognize_Unknown_Operation) {
    // Arrange
    std::vector<std::string> args = {"push", "1"};

    Act(args);

    Assert("Unknown operation: push");
}

TEST_F(ModifStackAppTest, Can_Check_Size_Of_Empty_Stack) {
    // Arrange
    std::vector<std::string> args = {"Size"};

    Act(args);

    Assert("0 is the size of modific stack.");
}

TEST_F(ModifStackAppTest, Can_Push_Number) {
    // Arrange
    std::vector<std::string> args = {"Push", "1", "Top"};

    Act(args);

    Assert("1 is the top stack element extracted of.");
}

TEST_F(ModifStackAppTest, Can_Check_Size) {
    // Arrange
    std::vector<std::string> args = {"Push", "1", "Push", "2", "Size"};

    Act(args);

    Assert("2 is the size of modific stack.");
}

TEST_F(ModifStackAppTest, Can_Top_Element) {
    // Arrange
    std::vector<std::string> args = {"Push", "1", "Top", "Push", "3", "Top"};

    Act(args);

    Assert("1 is the top stack element extracted of.\\3 is the top stack element extracted of.");
}




