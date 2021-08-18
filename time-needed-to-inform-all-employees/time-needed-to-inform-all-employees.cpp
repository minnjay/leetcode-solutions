class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime)
    {
        int res = 0;
        for(int i = 0; i<manager.size(); ++i)
        {
            res = max(res, dfs(manager, informTime, i));
        }
        return res;
        
    }
    
    int dfs(vector<int>& manager, vector<int>& informTime, int num)
    {
        if(manager[num] != -1)
        {
            informTime[num] += dfs(manager, informTime, manager[num]);
            manager[num] = -1;
        }
        return informTime[num];
    }
    

};