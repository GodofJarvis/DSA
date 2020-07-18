// Number of nodes in nth Degree of connection in graph

#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
	int nodes, edges;
	cin>>nodes>>edges;
 
	int i, j, m;
	vector <int> edgeVector[nodes+1];
	for (i=0; i < edges; i++){
		int x, y;
		cin>>x>>y;
		edgeVector[x].push_back(y);
		if (x != y){
		    edgeVector[y].push_back(x);
		}
	}
 
	cin>>m;
	for (i=0; i<m; i++){
		int u, degree;
		cin>>u>>degree;
 
    	int queue[nodes+1];
    	int frt=0, rr=0;
    	int x;
		int visited[nodes+1];
		memset(visited, 0, sizeof(int)*(nodes+1));
 
		queue[frt++]= u;
		visited[u] = 1;
		while (degree--) {
 
			int count = frt - rr;
 
			for (x=0; x < count; x++){
				
				int curr = queue[rr++];
				int count = edgeVector[curr].size();
 
				for (j=0; j < count; j++){
 
					if (visited[edgeVector[curr][j]] == 0) {
						queue[frt++] = edgeVector[curr][j];
						visited[edgeVector[curr][j]] = 1;
					}
				}
			}
		}
		cout<<frt-rr<<"\n";
	}
}
