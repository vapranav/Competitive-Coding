class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> result;
        vector<int> path;
        dfs(result, graph, path, 0, graph.size()-1);
        return result;
    }
    
    void dfs(vector<vector<int>> &result, vector<vector<int>>& graph, vector<int> path, int current, int destination) {
        if(current == destination) {
            path.push_back(current);
            result.push_back(path);
            return;
        }
        for(int i = 0; i<graph[current].size(); i++) {
            path.push_back(current);
            dfs(result, graph, path, graph[current][i], destination);
            path.pop_back();
        }
        return;
    }
};