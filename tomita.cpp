#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>

#pragma GCC optimize("O3")
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")

using namespace std;

map<int, int> sizeCounts;
unordered_map<int, unordered_set<int>> graph;
unordered_set<int> Q;
int n, m;
int c = 1;


int findPivot(const unordered_set<int>& CAND) {
    int pivot = -1, max_intersection = -1;
    for (int u : CAND) {
        int intersection_count = 0;
        for (int neighbor : graph.at(u)) {
            if (CAND.count(neighbor)) {  
                intersection_count++;
            }
        }
        if (intersection_count > max_intersection) {  
            max_intersection = intersection_count;
            pivot = u;
        }
    }
    return pivot;  
}

void expand(unordered_set<int> subg, unordered_set<int> CAND) {
    if (subg.empty()) {
        sizeCounts[Q.size()]++;
        c++;
        return;
    }

    int pivot = findPivot(CAND);
    unordered_set<int> EXT;
    for (int v : CAND) {
        if (!graph[pivot].count(v)) {
            EXT.insert(v);
        }
    }

    while (!EXT.empty()) {
        int q = *EXT.begin();
        EXT.erase(q);

        Q.insert(q);
        unordered_set<int> newSUBG, newCAND;

        for (int neighbor : graph[q]) {
            if (subg.count(neighbor)) {
                newSUBG.insert(neighbor);
            }
            if (CAND.count(neighbor)) {
                newCAND.insert(neighbor);
            }
        }

        expand(newSUBG, newCAND);
        Q.erase(q);
        CAND.erase(q);
    }
}

void findMaximalCliques() {
    unordered_set<int> V;
    for (auto& node : graph) {
        V.insert(node.first);
    }
    expand(V, V);
}

int main() {
    string filename;
    cout << "Enter the input file name: ";
    cin >> filename;

    ifstream inputFile(filename);
    if (!inputFile) {
        cerr << "Error: Could not open " << filename << endl;
        return 1;
    }

    cout << "Graph Loaded" << endl;
    cout << "Tomita Research Paper Implementation" << endl;

    inputFile >> n >> m;
    cout << "Vertices: " << n << " , Edges: " << m << endl;

    for (int i = 0; i < m; i++) {
        int u, v;
        inputFile >> u >> v;
        graph[u].insert(v);
        graph[v].insert(u);
    }

    inputFile.close();
    findMaximalCliques();

    cout << "Total Cliques: " << c - 1 << endl;
    cout << "Size of Cliques: " << endl;

    for (auto it = sizeCounts.begin(); it != sizeCounts.end(); it++) {
        cout << it->first << " : " << it->second << endl;
    }

    return 0;
}
