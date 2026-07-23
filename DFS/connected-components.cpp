// using dfs to get count the number of connected components

#include <iostream>
#include <vector>
#include <unordered_map>
#include "../Graph Node/node.h"

using namespace std;

struct FunctionRes{
    int componentCount;
    vector<int> componentArray;
};

FunctionRes countDiffComponents(unordered_map<int, vector<int>> &g);
void dfs(vector<int> &visited, unordered_map<int, vector<int>> &g, int at, vector<int> &components, int count);

int main(){
    unordered_map<int, vector<int>> g = {
        {1, {5}},
        {2, {15, 9}},
        {3, {9}},
        {4, {0, 8}},
        {5, {1,16,17}},
        {8, {4, 0, 14}},
        {9, {2, 3, 15}},
        {10, {15}},
        {13, {0, 14}},
        {14, {8, 0, 13}},
        {15, {2, 9, 10}},
        {16, {5}},
        {17, {5}},
    };

    FunctionRes res = countDiffComponents(g);

    cout << "There are total " << res.componentCount << " components in the graph.\n" << endl;
    for (int i = 0; i < 1000; i++){
        if (res.componentArray[i] == -1) continue;
        cout << i << " -> " << res.componentArray[i] << "th group\n";
    }

    return 0;
}

FunctionRes countDiffComponents(unordered_map<int, vector<int>> &g){
    int n = g.size();
    int count = 0;
    vector<int> components(1000, -1);   // this is done in order to account for missing node values
    vector<int> visited(1000, 0);       // assuming there are a maximum of 1000 nodes in the graph

    for (int i = 1; i <= n; i++){
        if ((g.find(i) != g.end()) && !visited[i]){
            count++;
            dfs(visited, g, i, components, count);
        }
    }

    return {count, components};
}

void dfs(vector<int> &visited, unordered_map<int, vector<int>> &g, int at, vector<int> &components, int count){
    if (visited[at]) return;

    visited[at] = true;
    components[at] = count;
    for (int next : g[at]){
        dfs(visited, g, next, components, count);
    }
}
