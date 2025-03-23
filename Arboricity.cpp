#include<bits/stdc++.h>
using namespace std;

unordered_map<int, int> vertexMap;  // Old vertex -> New vertex mapping
int nextIndex = 0;  // Counter for new vertex index

vector<int> T;
vector<int> S;

int totalCliques =0;
map<int,int> sizeCounts;

int getMappedVertex(int original) {
    if (vertexMap.find(original) == vertexMap.end()) {
        vertexMap[original] = nextIndex++;
    }
    return vertexMap[original];
}

void update(int index, int vertices, vector<vector<int>> &graph, vector<int> &currentClique)
{
    cout << "update called with index " << index << endl;

    if(index == vertices)//base case
    {
        int cliqueSize = 0;
        for(int i=0; i<vertices; i++)
        {
            if(currentClique[i] == 1)
            {
                cliqueSize++;
            }
        }
        totalCliques++;
        sizeCounts[cliqueSize]++;
        return;
    }

    vector<int> originalT = T;
    vector<int> originalS = S;

    vector<int> CMinusN;

    for(int i=0; i< vertices; i++)
    {
        if(currentClique[i] == 1)
        {
            if(!binary_search(graph[index].begin(), graph[index].end(), i))
            {
                CMinusN.push_back(i);
            }
        }
    }

    if(CMinusN.size() != 0)
    {
        update(index+1, vertices, graph, currentClique);
        T = originalT;
        S = originalS;
    }

    for(int i=0; i<vertices; i++)
    {
        if(currentClique[i] == 0)
        {
            T[i] = 0;
            S[i] = 0;
        }
    }

    vector<int> CAndN;
    for(int i: graph[index])
    {
        if(i<vertices && currentClique[i] == 1)
        {
            CAndN.push_back(i);
        }
    }
    sort(CAndN.begin(), CAndN.end());
    int CandNSize = CAndN.size();
    for(int i: CAndN)
    {
        for(int j: graph[i])
        {
            if(j!=index && j < vertices && currentClique[j]==0)
            {
                T[j]++;
            }
        }
    }

    for(int i: CMinusN)
    {
        for(int j: graph[i])
        {
            if(j<vertices && currentClique[j] == 0)
            {
                S[j]++;
            }
        }
    }

    bool FLAG = true;

    for(int i: graph[index])
    {
        if(i < vertices && currentClique[i] == 0 && i < index && T[i] ==  CandNSize)
        {
            FLAG = false;
            break;
        }
    }
    
    vector<int> sortedCMinusN = CMinusN;
    sort(sortedCMinusN.begin(), sortedCMinusN.end());

    if(FLAG && sortedCMinusN.size()!=0)
    {
        for(int i=0; i< index; i++)
        {
            if(currentClique[i]==0)
            {
                if(T[i] == CandNSize)
                {
                    int count =0;
                    int iCMinusN = 0;
                    int iGraph = 0;

                    while(iCMinusN < sortedCMinusN.size()&&iGraph<graph[i].size())
                    {
                        if(sortedCMinusN[iCMinusN] < graph[i][iGraph])
                        {
                            iCMinusN++;
                        }
                        else if(sortedCMinusN[iCMinusN] > graph[i][iGraph])
                        {
                            iGraph++;
                        }
                        else
                        {
                            count++;
                            iCMinusN++;
                            iGraph++;
                        }
                    }
                    S[i] -= count;
                }
            }
        }
    }

    if(CAndN.size()!=0)
    {
        if(sortedCMinusN.size()!=0)
        {
            int x = sortedCMinusN.back();
            for(int i: CAndN)
            {
                if(i < index && (int)graph[index].size()==T[i]&&S[i]==0)
                {
                    if(x<i || x<index-1)
                    {
                        FLAG=false;
                        break;
                    }
                }
            }
        }
    }

    if(FLAG)
    {
        vector<int> removedNodes;
        for(int i=0; i<vertices; i++)
        {
            if(currentClique[i] == 1)
            {
                if(i!=index && !binary_search(CAndN.begin(), CAndN.end(), i))
                {
                    removedNodes.push_back(i);
                    currentClique[i] = 0;
                }
            }
        }
        currentClique[index] = 1;
        update(index+1, vertices, graph, currentClique);
        for(int i: removedNodes)
        {
            currentClique[i] = 1;
        }
        currentClique[index] = 0;
    }

    T = originalT;
    S = originalS;

}

void clique(vector<vector<int>> &graph, int v, int e)
{
    cout << "Clique called" << endl;
    for(int i=0; i<v; i++)
    {
        sort(graph[i].begin(), graph[i].end());
    }
    cout << "Graph sorted" << endl;
    for (int i = 0; i < v; i++) {
        T.push_back(0);
        S.push_back(0);
    }
    cout << "T and S initialized" << endl;
    vector<int> currentClique;
    for(int i=0; i<v; i++)
    {
        currentClique.push_back(0);
    }
    cout << "Current clique initialized" << endl;
    cout << "initial update called" << endl;
    update(0, v, graph, currentClique);

}

int main()
{
    auto start = std::chrono::high_resolution_clock::now();  // Start timer
    ifstream infile("input1.txt");

    int v,e;
    infile>>v>>e;
    vector<vector<int>> graph(v);

    string line;
    while(getline(infile, line))
    {
        if(line[0] == '#')
        {
            continue;
        }
        int u, w;
        if (sscanf(line.c_str(), "%d %d", &u, &w) == 2) {
            int mappedU = getMappedVertex(u);
            int mappedW = getMappedVertex(w);
            graph[mappedU].push_back(mappedW);
            graph[mappedW].push_back(mappedU);  // Undirected graph: add both directions
        }
    }

    cout << "Graph loaded" << endl;
    cout << "the graph is:-" << endl;
    for(int i=0; i<v; i++)
    {
        cout << i << ":- ";
        for(int j: graph[i])
        {
            cout << j << " ";
        }
        cout << endl;
    }
    infile.close();
    cout << "calling clique" << endl;
    clique(graph, v,e);

    cout << "Total cliques: " << totalCliques << endl;
    cout << "Clique size distribution: " << endl;
    for(auto i: sizeCounts)
    {
        cout << i.first << " " << i.second << endl;
    }

    auto stop = std::chrono::high_resolution_clock::now();   // Stop timer
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    
    std::cout << "Execution Time: " << duration.count() << " ms" << std::endl;
    return 0;
}
