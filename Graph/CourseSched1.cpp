/* https://leetcode.com/problems/course-schedule/submissions/
*
* Course schedule - DFS approach
*/

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int pre = prerequisites.size();
        if (pre <= 1)
            return true;
        
        map <int, vector<int>> graphMap;
        for (int i=0; i<pre; i++){
            int in = prerequisites[i][0];
            int out = prerequisites[i][1];
            
            graphMap[in].push_back(out);
        }
        
        vector <int> taken(numCourses, 0);
        for (int i=0; i<numCourses; i++){
            vector <int> visited(numCourses, 0);
            if (!isPath(graphMap, i, taken, visited))
                return false;
            
            for (int j=0; j<numCourses; j++)
                if (visited[j])
                    taken[j] = 1;
        }
        return true;
    }
    
    bool isPath(map<int, vector<int>> &graph, int node, vector<int>& taken, vector<int>& visited){
        if (taken[node] || graph.find(node) == graph.end()){
            taken[node] = 1;
            return true;
        }
        if (visited[node])
            return false;
        
        visited[node] = 1;
        bool path = true;
        auto ptr = graph.find(node);
        for (auto connected: ptr->second){
            path = isPath(graph, connected, taken, visited);
            if (!path)
                return false;
        }
        if (path)
            taken[node]=1;
        return path;
    }
};
