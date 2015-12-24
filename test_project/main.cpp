//
//  main.cpp
//  test_project
//
//  Created by 安田洋介 on 12/20/15.
//  Copyright © 2015 安田洋介. All rights reserved.
//

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "karger_min_cut.h"

using namespace std;

TEST_CASE("tests"){
    REQUIRE(exec_min_cut("test1.txt") == 1);
}

TEST_CASE("exec"){
    REQUIRE(exec_min_cut("kargerMinCut.txt") == 17);
}