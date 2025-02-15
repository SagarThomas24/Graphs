#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>

using namespace std;

void expand(set<int> Q, set<int> CAND, set<int> FINI, const vector<vector<int>>& graph) 
{
    if (CAND.empty() && FINI.empty()) 
    {
        cout << "{ ";
        for (auto i : Q) {
            cout << i << " ";
        }
        cout << "}\n";
        return;
    }
    
    set<int> CAND_copy = CAND;
    
    for (auto q : CAND_copy) 
    {
        set<int> Q_new = Q;
        Q_new.insert(q);
        
        set<int> CAND_new, FINI_new;
        for (auto v : CAND) {
            if (find(graph[q].begin(), graph[q].end(), v) != graph[q].end()) {
                CAND_new.insert(v);
            }
        }
        for (auto v : FINI) {
            if (find(graph[q].begin(), graph[q].end(), v) != graph[q].end()) {
                FINI_new.insert(v);
            }
        }

        expand(Q_new, CAND_new, FINI_new, graph);

        CAND.erase(q);
        FINI.insert(q);
    }
}

void findMaximalCliques(int n, const vector<vector<int>>& graph) 
{
    set<int> Q, CAND, FINI;
    for (int i = 1; i <= n; i++) 
    {
        CAND.insert(i);
    }
    expand(Q, CAND, FINI, graph);
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1);  

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    findMaximalCliques(n, graph);

    return 0;
}
