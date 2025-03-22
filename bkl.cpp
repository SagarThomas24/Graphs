#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <chrono>

using namespace std;

unordered_map<int, unordered_set<int>> graph; // Adjacency list
int v,e;
set<int> P; // Candidate vertices
int totalCliques =0;
map<int,int> sizeCounts;
unordered_map<int, int> vertexMap;  // Old vertex -> New vertex mapping
int nextIndex = 0;  // Counter for new vertex index

int getMappedVertex(int original) {
    if (vertexMap.find(original) == vertexMap.end()) {
        vertexMap[original] = nextIndex++;
    }
    return vertexMap[original];
}

vector<int> computeDegeneracyOrder(unordered_map<int, unordered_set<int>>& graph, int v, int e) {
    vector<int> order;  
    order.reserve(v);

    vector<int> degree(v, 0);
    vector<bool> removed(v, false);
    vector<vector<int>> buckets(v);  // Buckets for vertices of each degree
    int maxDegree = 0;  // Track max degree to limit bucket processing

    // Initialize degrees and place vertices in buckets
    for (int i = 0; i < v; i++) {
        degree[i] = graph[i].size();  
        maxDegree = max(maxDegree, degree[i]);
        buckets[degree[i]].push_back(i);
    }

    int remainingVertices = v;  

    // Process vertices using bucket sort method
    for (int d = 0; d <= maxDegree; d++) {  
        while (!buckets[d].empty()) {  
            int u = buckets[d].back();  
            buckets[d].pop_back();  

            if (removed[u]) continue;  

            removed[u] = true;  
            order.push_back(u);  
            remainingVertices--;  

            // Update degrees of neighbors
            for (int neighbor : graph[u]) {
                if (!removed[neighbor]) {
                    int oldDegree = degree[neighbor];

                    // Move neighbor to lower degree bucket
                    if (oldDegree > 0) {
                        degree[neighbor]--;
                        buckets[degree[neighbor]].push_back(neighbor);
                    }
                }
            }
        }
    }

    return order;
}

// Bron-Kerbosch algorithm with pivoting
void BronKerbosch(set<int> R, set<int> P, set<int> X) {
    if (P.empty() && X.empty()) {
        totalCliques++;
        sizeCounts[R.size()]++;
        return;
    }

    // Choose pivot (first element in P ∪ X)
    int u = *P.begin();
    for (int v : X) {
        u = v;
        break;
    }

    // Iterate over non-neighbors of pivot
    set<int> P_copy = P;
    for (int v : P_copy) {
        if (graph[u].count(v)) continue;

        set<int> newR = R, newP, newX;
        newR.insert(v);

        // Intersect P and X with neighbors of v
        for (int w : P) if (graph[v].count(w)) newP.insert(w);
        for (int w : X) if (graph[v].count(w)) newX.insert(w);

        BronKerbosch(newR, newP, newX);

        // Remove v from P and add to X
        P.erase(v);
        X.insert(v);
    }
}

// Load graph from file
void loadGraph(const string &filename) {
    ifstream infile(filename);
    if (!infile) {
        cerr << "Error: Unable to open file " << filename << endl;
        exit(1);
    }

    string line;
    bool firstLine = true;  // To read the first line with v and e

    while (getline(infile, line)) {
        if (line[0] == '#') continue;  // Skip comments

        if (firstLine) {
            // Read the first line for vertices and edges
            sscanf(line.c_str(), "%d %d", &v, &e);
            cout << "Vertices: " << v << ", Edges: " << e << endl;
            firstLine = false;
            continue;
        }

        int u, w;
        if (sscanf(line.c_str(), "%d %d", &u, &w) == 2) {
            int mappedU = getMappedVertex(u);
            int mappedW = getMappedVertex(w);
            graph[mappedU].insert(mappedW);
            graph[mappedW].insert(mappedU);  // Undirected graph: add both directions
        }
    }
    cout << "Graph loaded" << endl;
    infile.close();
}

void BronKerboschDegen(set<int> R, set<int> P, set<int> X)
{
    vector<int> order = computeDegeneracyOrder(graph, v, e);
    for(int i=0; i<v;i++)
    {
        int currentVertex = order[i];
        set<int> RForPivot = {currentVertex};
        set<int> PForPivot, XForPivot;
        int j = i+1;
        while(j<v )
        {
            if( (graph[currentVertex].find(order[j]) != graph[currentVertex].end()))
            {PForPivot.insert(order[j]);}
            j++;
        }
        j = i-1;
        while(j>=0 )
        {
            if((graph[currentVertex].find(order[j]) != graph[currentVertex].end()))
            {XForPivot.insert(order[j]);}
            j--;
        }
        BronKerbosch(RForPivot, PForPivot, XForPivot);
    }
}

// Main function
int main() {
    string filename;
    cout << "Enter the dataset: ";
    cin >> filename;

    auto start = std::chrono::high_resolution_clock::now();  // Start timer
    loadGraph(filename);
    cout << "Version 1: Bron-Kerbosch with Pivot and Degeneracy" << endl;

    for (const auto &pair : graph) {
        P.insert(pair.first);
    }

    BronKerboschDegen(set<int>(), P, set<int>() );
    cout << "Total Cliques: " << totalCliques << endl;
    cout << "Size of Cliques: " << endl;
    for (auto it = sizeCounts.begin(); it != sizeCounts.end(); it++) {
        cout << it->first << " : " << it->second << endl;
    }
    auto stop = std::chrono::high_resolution_clock::now();   // Stop timer
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    std::cout << "Execution Time: " << duration.count() << " ms" << std::endl;
    return 0;
}
