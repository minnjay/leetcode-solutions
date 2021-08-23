class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k)
    {
        vector<vector<pair<int, int>>> graph(n+1);
        vector<bool> visited(n+1, false);
        vector<int> value(n+1, INT_MAX);
        value[k] = 0;
        value[0] = 0;
        vector<int> parent(n+1, -1);
        for(int i = 0; i<times.size(); ++i)
        {
            graph[times[i][0]].push_back(make_pair(times[i][1], times[i][2]));
        }
        
        for(int i = 1; i<=n; ++i)
        {
            int U = selectMinVertex(value, visited);
            visited[U] = true;
            for(int j = 0; j <graph[U].size(); ++j)
            {
                if(visited[graph[U][j].first] == false && value[U] != INT_MAX && value[U] + graph[U][j].second < value[graph[U][j].first])
                {
                    value[graph[U][j].first] = value[U] + graph[U][j].second;
                    parent[graph[U][j].first] = U;
                }
            }
        }
        for(int i = 1; i<value.size(); ++i)
        {
            if(value[i] == INT_MAX)
            {
                return -1;
            }
        }
        return *max_element(value.begin(), value.end());
    }
    
    int selectMinVertex(vector<int>& value, vector<bool>& visited)
    {
        int minimum = INT_MAX;
        int vertex;
        for(int i = 1; i<value.size(); ++i)
        {
            if(!visited[i] && value[i]<minimum)
            {
                minimum = value[i];
                vertex = i;
            }
        }
        return vertex;
        
    }
};