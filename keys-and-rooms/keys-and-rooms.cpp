class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms)
    {
        vector<bool> visited(rooms.size(), false);
        // for(int i = 0; i<rooms.size(); ++i)
        // {
        //     if(visited[i] == false && )
        //     {
                dfs(visited, rooms, 0);
        //     }
        // }
        
        for(int i = 0; i<visited.size(); ++i)
        {
            if(!visited[i])
            {
                return false;
            }
        }
        return true;
        
    }
    
    void dfs(vector<bool>& visited, vector<vector<int>>& rooms, int num)
    {
        visited[num] = true;
        for(int i = 0; i<rooms[num].size(); ++i)
        {
            if(visited[rooms[num][i]] == false)
            {
                if(num != rooms[num][i])
                {
                    dfs(visited, rooms, rooms[num][i]);                    
                }
            }
        }
    }
};