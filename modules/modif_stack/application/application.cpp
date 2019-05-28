// Copyright 2019 Trubina Anastasia

#include <iostream>
#include "include/modif_stack_app.h"

int main(int argc, char const **argv) {
    ModifStackApp application;
    std::cout << application(argc, argv) << std::endl;
    return 0;
}
