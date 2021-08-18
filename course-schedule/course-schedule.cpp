class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        vector<int> color(numCourses, 0);
        vector<vector<int>> graph(numCourses);
        for(int i = 0; i<prerequisites.size(); ++i)
        {
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        
        for(int i = 0; i<graph.size(); ++i)
        {
            if(color[i] == 0)
            {
                if(isCyclic(color, graph, i))
                {
                    return false;
                }
            }
        }
        return true;
    }
    
    // 0(unvisited), 1(processing), 2(processed)
    bool isCyclic(vector<int>& color, vector<vector<int>>& graph, int num)
    {
        if(color[num]>0)
        {
            return color[num] == 1;
        }
        color[num] = 1;
        
        for(int i = 0; i<graph[num].size(); ++i)
        {
            if(isCyclic(color, graph, graph[num][i]) || color[graph[num][i]] == 1)
            {
                return true;
            }
        }
        
        color[num] = 2;
        return false;
    }
    
    
};