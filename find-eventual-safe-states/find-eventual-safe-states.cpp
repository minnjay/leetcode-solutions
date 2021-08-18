class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph)
    {
        vector<int> ans;
        vector<int> color(graph.size(),0);
        
        for(int i = 0; i<graph.size(); i++)
        {
            if(dfs(i, color, graph))
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
    
    // 0(white) 1(gray) 2(black)
    bool dfs(int num, vector<int>& color, vector<vector<int>>& graph)
    {
        if(color[num]>0)
        {
            return color[num] == 2;
        }
        
        color[num] = 1;
        
        for(int i = 0; i<graph[num].size(); ++i)
        {
            // if(color[num] == 2)
            // {
            //     continue;
            // }
            if(color[graph[num][i]] == 1 || !dfs(graph[num][i], color, graph))
            {
                return false;
            }
        }
        
        
        
        
        color[num] = 2;
        return true;
        
    }
    
};