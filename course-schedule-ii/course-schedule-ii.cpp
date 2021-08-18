class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
    {
        vector<int> answer;
        vector<int> color(numCourses, 0);
        vector<bool> visited(numCourses, false);
        
        vector<vector<int>> graph(numCourses);
        for(int i = 0; i < prerequisites.size(); ++i)
        {
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        bool track = false;
        for(int i = 0; i<graph.size(); i++)
        {
            if(color[i] == 0)
            {
                
                if(isCyclic(graph, color, i))
                {
                    track = true;
                }
            }
            if(visited[i] == false)
            {
                dfs(graph, visited, i, answer);
            }
        }
        if(track)
        {
            answer.clear();
            return answer;
        }
        return answer;
    }
    
    void dfs(vector<vector<int>>& graph, vector<bool>& visited, int num, vector<int>& answer)
    {
        visited[num] = true;
        for(int i = 0; i<graph[num].size(); ++i)
        {
            if(!visited[graph[num][i]])
            {
                dfs(graph, visited, graph[num][i], answer);
            }
        }
        answer.push_back(num);
    }
    
    bool isCyclic(vector<vector<int>>& graph, vector<int>& color, int num)
    {
        if(color[num]>0)
        {
            return color[num] == 1;
        }
        color[num] = 1;
        
        for(int i = 0; i<graph[num].size(); ++i)
        {
            if(color[graph[num][i]] == 1 || isCyclic(graph, color, graph[num][i]) )
            {
                return true;
            }
            
        }
        
        
        color[num] = 2;
        return false;
    }
};