class Solution {
public:
    
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges)
    {
        int n = edges.size();
        vector<int> answer(2,-1);
        vector<int> parent(n+1,0);
        for(int i = 0; i<n+1; ++i)
        {
            parent[i] = i;
        }
        
        for(int i = 0; i<n; ++i)
        {
            int a = edges[i][0];
            int b = edges[i][1];
            
            while(a != parent[a])
            {
                a = parent[a];
            }
            while(b != parent[b])
            {
                b = parent[b];
            }
            
            if(a != b)
            {
                parent[a] = b;
            }
            else
            {
                answer[0] = edges[i][0];
                answer[1] = edges[i][1];
            }
        }
        return answer;
    }
};
