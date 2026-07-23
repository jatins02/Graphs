// using dfs to get count the number of connected components

#include <iostream>
#include <vector>
#include <unordered_map>
#include "../Graph Node/node.h"

using namespace std;

int countDiffComponents(unordered_map<int, vector<int>> &g);

int main(){

    unordered_map<int, vector<int>> g = {
        {1, {5}},
        {2, {15, 9}},
        {3, {9}},
        {4, {0, 8}},
        {5, {1,16,17}},
        {6, {7, 11}},
        {7, {6, 11}},
        {8, {4, 0, 14}},
        {9, {2, 3, 15}},
        {10, {15}},
        {11, {6, 7}},
        {12, {}},
        {13, {0, 14}},
        {14, {8, 0, 13}},
        {15, {2, 9, 10}},
        {16, {5}},
        {17, {5}},
    };

    cout << countDiffComponents(g) << endl;
    return 0;
}

int countDiffComponents(unordered_map<int, vector<int>> &g){
    return 0;
}
