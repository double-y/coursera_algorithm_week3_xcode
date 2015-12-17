//
//  karger_min_cut.cpp
//  coursera_algorithm_week3
//
//  Created by 安田洋介 on 12/20/15.
//  Copyright © 2015 安田洋介. All rights reserved.
//

#include "karger_min_cut.h"

using namespace std;

int count_min_cut(vector<pair<int, int>> graph_vec, set<int> node_set){
    
    int min_nodenum_abs = 0;
    
    while(node_set.size()>2){
        min_nodenum_abs++;
        node_set.insert(-min_nodenum_abs);
        
        int index = rand()%graph_vec.size();
        int first_node = graph_vec[index].first;
        int second_node = graph_vec[index].second;
        
        node_set.erase(node_set.find(first_node));
        node_set.erase(node_set.find(second_node));
        
        vector<pair<int, int>> new_graph;
        
        for (int i=0; i<graph_vec.size(); i++){
            pair<int, int> edge = graph_vec[i];
            pair<int, int> new_edge;
            if(edge.first == first_node || edge.first == second_node){
                new_edge.first = -min_nodenum_abs;
            }else{
                new_edge.first = first_node;
            }
            if(edge.second == first_node || edge.second == second_node){
                new_edge.second = -min_nodenum_abs;
            }else{
                new_edge.second = second_node;
            }
            
            if(edge.first != edge.second){
                new_graph.push_back(new_edge);
            }
            graph_vec = new_graph;
        }
    }
    
    return graph_vec.size();
}

int exec_min_cut(string file_name){
    ifstream inFile(file_name);
    string line;
    
    vector<pair<int, int>> graph_vec;
    set<int> node_set;
    
    while (inFile){
        istringstream iss(line);
        int from_node;
        iss >> from_node;
        node_set.insert(from_node);
        int to_node;
        while (iss >> to_node){
            if(from_node < to_node){
                pair<int, int> edge (from_node, to_node);
                graph_vec.push_back(edge);
                node_set.insert(to_node);
            }
        }
    }
    
    return count_min_cut(graph_vec, node_set);
    
}
