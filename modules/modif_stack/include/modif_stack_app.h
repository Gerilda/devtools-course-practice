// Copyright 2019 Trubina Anastasia

#ifndef MODULES_MODIF_STACK_INCLUDE_MODIF_STACK_APP_H_
#define MODULES_MODIF_STACK_INCLUDE_MODIF_STACK_APP_H_

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

#endif  // MODULES_MODIF_STACK_INCLUDE_MODIF_STACK_APP_H_
