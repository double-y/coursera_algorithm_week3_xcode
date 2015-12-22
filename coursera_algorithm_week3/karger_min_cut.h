//
//  karger_min_cut.h
//  coursera_algorithm_week3
//
//  Created by 安田洋介 on 12/20/15.
//  Copyright © 2015 安田洋介. All rights reserved.
//

#ifndef karger_min_cut_h
#define karger_min_cut_h

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <sstream>
#include <string>
#include <fstream>

int count_min_cut(std::vector<std::pair<int, int>> graph_vec, std::set<int> node_set, int seed);
int exec_min_cut(std::string file_name);

#endif /* karger_min_cut_h */
