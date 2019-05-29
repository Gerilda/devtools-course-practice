// Copyright 2019 Trubina Anastasia

#include <cstring>
#include <limits>
#include <iostream>
#include <stdexcept>
#include <string>
#include <utility>
#include "include/modif_stack.h"
#include "include/modif_stack_app.h"

ModifStackApp::ModifStackApp() : out_("") {}

std::string ModifStackApp::Help(const char *application) {
    return "This is application for modific stack class\n"
           "Please provide arguments in the following format:\n"
           " $ " + std::string(application) + " actions that described below\n"
           "Actions:\n"
           "Push - add the element in the stack"
           "Pop - removes the element on top of the stack\n"
           "Top - extract the value of the top stack element\n"
           "Size - show size of the stack\n";
}

std::string ModifStackApp::operator()(int argc, const char** argv) {
    if (argc == 1) {
        return Help(*argv);
    }
    try {
        for (int i = 1; i < argc;) {
            int offset = ParseOperation(argv + i);
            i += offset;
        }
        return out_.str();
    } catch (std::runtime_error &re) {
        return re.what();
    }
}

int ModifStackApp::ParseOperation(const char **argv) {
    if (std::strcmp(*argv, "Push") == 0) {
        int value = ParseNumber(*(argv + 1));
        modstack_.Push(value);
        return 2;
    }
    if (std::strcmp(*argv, "GetMin") == 0) {
        int val = modstack_.GetMinEl();
        out_ << "Minimum element: " << val;
        return 1;
    }
    if (std::strcmp(*argv, "Size") == 0) {
        std::size_t val = modstack_.Size();
        out_ << "Size of modific stack: "<< val;
        return 1;
    }
    if (std::strcmp(*argv, "Top") == 0) {
        std::pair<int, int> val = modstack_.Top();
        out_ << "Top element: " << std::get<0>(val) << ". ";
        return 1;
    }
    if (std::strcmp(*argv, "Pop") == 0) {
        modstack_.Pop();
        return 1;
    }
    throw std::runtime_error(std::string("Unknown operation: ") +
                             std::string(*argv));
    return 0;
}


int ModifStackApp::ParseNumber(const char *s) {
    int len = strlen(s);
    if ((s[0] != '-' && !isdigit(s[0])) || (s[0] == '-' && len == 1))
        throw std::runtime_error(std::string(s) + " is not the number");
    int64_t result = std::strtol(s, nullptr, 10);
    if (result <= static_cast<int64_t>(std::numeric_limits<int>::min()) ||
        result >= static_cast<int64_t>(std::numeric_limits<int>::max())) {
        throw std::runtime_error("Number overflows");
    }
    return static_cast<int>(result);
}

