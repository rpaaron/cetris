//
// Created by cecco on 21/05/15.
//
#include <iostream>
#include <fstream>
#include "utils.h"

std::string data(const char*file) {

    std::string tmp1 = D_PATH;
    tmp1.append(file);

    printf("Looking for %s: ", tmp1.c_str());
    std::ifstream f(tmp1.c_str());
    if(f.good()) {
        printf("FOUND\n");
        return tmp1;
    }
    f.close();

    printf("NOT FOUND\n");

    std::string tmp2 = file;

    printf("Looking for %s: ", tmp2.c_str());
    std::ifstream f2(tmp2.c_str());

    if(f2.good()) {
        printf("FOUND\n");
        return tmp2;
    }
    f2.close();

    printf("NOT FOUND\n");
    return tmp2;
}
