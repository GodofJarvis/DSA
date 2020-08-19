#include <bits/stdc++.h>

using namespace std;

//Breadth first search
void bfs(vector <vector<int>> edges, int startNode, int nodes, int visited[]){
    int que[nodes+1];
    int rr=0, frt=0;
    
    
    que[rr++] = startNode;
    visited[startNode] = 1;
    while (rr != frt){
        int curr = que[frt++];
        cout<<curr<<" ";
        for (int i=0; i<edges[curr].size(); i++){
            int edg = edges[curr][i];
            if (visited[edg] == 0){
                que[rr++] = edg;
                visited[edg] = 1;
            }
        }
    }
}

//Depth first search
int dfs(vector <vector<int>> edges, int currNode, int visited[]){
    cout<<currNode<<" ";
    visited[currNode] = 1;
    for (int i=0; i<edges[currNode].size(); i++){
        int edg = edges[currNode][i];
        if (visited[edg] == 0){
            visited[edg] = 1;
            dfs(edges, edg, visited);
        }

    }
    return 0;
}

int main()
{
    int nodes = 6;
    vector <vector <int>> edges(nodes+1);
    
    // make a copy of below edges with reverse of vertices,
    // for undirected graph
    edges[1].push_back(2);
    edges[1].push_back(3);
    edges[2].push_back(4);
    edges[4].push_back(1); //Adds a cycle
    edges[4].push_back(6);
    edges[3].push_back(5);
    
    int startNode = 1;
    int visited[nodes+1];
    memset (visited, 0, sizeof(int)*(nodes+1));
    cout<<"\nBFS: "; bfs(edges, startNode, nodes, visited);

    memset (visited, 0, sizeof(int)*(nodes+1));
    cout<<"\nDFS: "; dfs(edges, startNode, visited);
    return 0;
}
