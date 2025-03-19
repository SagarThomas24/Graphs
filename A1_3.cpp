#include <iostream>
#include <unordered_map>
#include <set>
#include <fstream>
#include <vector>
#pragma GCC optimize("O3,unroll-loops,fast-math,tree-vectorize,omit-frame-pointer,inline-functions")

int c=1;
using namespace std;

void expand(set<int> Q, set<int> CAND, set<int> FINI, const unordered_map<int, set<int>>& graph) 
{
    if (CAND.empty() && FINI.empty()) 
    {
        cout << "{ ";
        for (auto i : Q) {
            cout << i << " ";
        }
        cout << "}\n";
        cout<<c<<endl;
        c++;
        return;

    }
    
    set<int> CAND_copy = CAND;
    
    for (auto q : CAND_copy) 
    {
        set<int> Q_new = Q;
        Q_new.insert(q);
        
        set<int> CAND_new, FINI_new;
        for (auto v : CAND) {
            if (graph.at(q).count(v)) {
                CAND_new.insert(v);
            }
        }
        for (auto v : FINI) {
            if (graph.at(q).count(v)) {
                FINI_new.insert(v);
            }
        }

        expand(Q_new, CAND_new, FINI_new, graph);

        CAND.erase(q);
        FINI.insert(q);
    }
}

void findMaximalCliques(int n, const unordered_map<int, set<int>>& graph) 
{
    set<int> Q, CAND, FINI;
    for (const auto& node : graph) 
    {
        CAND.insert(node.first);
    }
    expand(Q, CAND, FINI, graph);
}

int main()
{
    ifstream inputFile("input.txt"); 
    if (!inputFile) 
    {
        cerr << "Error: Could not open input.txt" << endl;
        return 1;
    }

    int n, m;
    inputFile >> n >> m;  

    unordered_map<int, set<int>> graph;  

    for (int i = 0; i < m; i++)
    {
        int u, v;
        inputFile >> u >> v;
        graph[u].insert(v);
        graph[v].insert(u);
    }

    inputFile.close();  

    findMaximalCliques(n, graph);  

    return 0;
}
