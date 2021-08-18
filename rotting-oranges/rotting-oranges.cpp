class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid)
    {
        int ans = 0;
        queue<pair<int,int>> q;
        
        for(int i = 0; i<grid.size(); ++i)
        {
            for(int j = 0; j<grid[0].size(); ++j)
            {
                if(grid[i][j] == 2)
                {
                    q.push(make_pair(i,j));
                }
            }
        }
        
        int count = q.size();
        while(!q.empty())
        {
            
            if(count == 0)
            {
                count = q.size();
                ans ++;
            }
            
            pair<int,int> a = q.front();
            q.pop();
            
            if(a.first != 0)
            {
                if(grid[a.first-1][a.second] == 1)
                {
                    q.push(make_pair(a.first-1, a.second));
                    grid[a.first-1][a.second] = 2;
                }
            }
            if(a.first != grid.size()-1)
            {
                if(grid[a.first+1][a.second] == 1)
                {
                    q.push(make_pair(a.first+1, a.second));
                    grid[a.first+1][a.second] = 2;
                }
            }
            if(a.second != 0)
            {
                if(grid[a.first][a.second-1] == 1)
                {
                    q.push(make_pair(a.first, a.second-1));
                    grid[a.first][a.second-1] = 2;
                }
            }
            if(a.second != grid[0].size()-1)
            {
                if(grid[a.first][a.second+1] == 1)
                {
                    q.push(make_pair(a.first, a.second+1));
                    grid[a.first][a.second+1] = 2;
                }
            }
            count --;
            
        }
        
        for(int i = 0; i<grid.size(); ++i)
        {
            for(int j = 0; j<grid[0].size(); ++j)
            {
                if(grid[i][j] == 1)
                {
                    return -1;
                }
            }
        }
        return ans;
        
    }
};