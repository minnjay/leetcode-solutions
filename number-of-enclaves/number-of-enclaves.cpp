class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid)
    {
        int ans = 0;
        bool track =false;
        for(int i = 0; i<grid.size(); ++i)
        {
            for(int j = 0; j<grid[i].size(); ++j)
            {
                if(grid[i][j] == 1)
                {
                    ans += dfs(grid, i, j, track);
                    track = false;
                }
            }
        }
        return ans;
    }
    
    int dfs(vector<vector<int>>& grid, int i, int j, bool& track)
    {
        int ans = 1;
        if(i == 0 || i == grid.size()-1 || j == 0 || j == grid[0].size()-1)
        {
            if(grid[i][j] == 1)
            {
                track = true;
            }
        }
        grid[i][j] = 0;
        
        if(i != grid.size()-1)
        {
            if(grid[i+1][j] == 1)
            {
                ans += dfs(grid, i+1, j, track);
            }
           
        }
        if(i != 0)
        {
            if(grid[i-1][j] == 1)
            {
                ans += dfs(grid, i-1, j, track);
            }
            
        }
        if(j != grid[0].size()-1)
        {
            if(grid[i][j+1] == 1)
            {
                ans += dfs(grid, i, j+1, track);
            }
            
        }
        if(j != 0)
        {
            if(grid[i][j-1] == 1)
            {
                ans += dfs(grid, i, j-1, track);
            }
            
        }
        
        if(track)
        {
            ans = 0;
        }            
        return ans;
    }
};