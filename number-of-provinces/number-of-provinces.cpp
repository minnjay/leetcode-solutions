class Solution
{
public:
    void dfs(vector<vector<int>>& isConnected, int num, int track)
    {
        isConnected[track][num] = 0;
        for(int i = 0; i<isConnected[track].size(); ++i)
        {
            if(isConnected[num][i] == 1)
            {   
                dfs(isConnected, i, num);
            }
        }
        return;
        
    }
    
    int findCircleNum(vector<vector<int>>& isConnected)
    {
        int counter = 0;
        for(int i = 0; i<isConnected.size(); ++i)
        {
            if(isConnected[i][i] == 1)
            {
                counter++;
                dfs(isConnected, i, i);
            }
        }
        return counter;
    }
};