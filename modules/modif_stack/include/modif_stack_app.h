// Copyright 2019 Trubina Anastasia

#ifndef DEVTOOLS_MODIF_STACK_APP_H__
#define DEVTOOLS_MODIF_STACK_APP_H__

#include <sstream>
#include <string>
#include "include/modif_stack.h"

class ModifStackApp {
 private:
    std::string Help(const char *application);
    int ParseOperation(const char **argv);
    int ParseNumber(const char *s);
    ModifStack modstack_;
    std::stringstream out_;
 public:
    ModifStackApp();
    std::string operator()(int argc, const char** argv);
};

#endif  // DEVTOOLS_MODIF_STACK_APP_H__
