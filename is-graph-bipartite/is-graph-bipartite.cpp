class Solution {
public:
    // 0 - not color
    // 1 - blue
    // -1 - red
    bool isBipartite(vector<vector<int>>& graph)
    {
        vector<int> color(graph.size(), 0);
        
        for(int i = 0; i<graph.size(); i++)
        {
            if(color[i] == 0 &&!validColor(graph, color, 1, i))
            {
                return false;
            }
        }
        return true;

    }
    
    bool validColor(vector<vector<int>>& graph, vector<int>& color, int col, int node)
    {
        if(color[node] != 0)
        {
            return color[node] == col;
        }
        color[node] = col;
        
        for(int i = 0; i<graph[node].size(); ++i)
        {
            if(!validColor(graph, color, -col, graph[node][i]))
            {
                return false;
            }
        }
        return true;
    }
};