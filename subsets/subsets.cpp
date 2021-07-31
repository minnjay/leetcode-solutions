class Solution {
public:
    
    //Approach 1: Cascading
    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<vector<int>> result;
        vector<int> temp;
        result.push_back(temp);
        for(int i = 0; i< nums.size(); ++i)
        {
            int length = result.size();
            for(int a = 0; a <length; ++a)
            {
                result[a].push_back(nums[i]);
                result.push_back(result[a]);
                result[a].pop_back();
            }
        }
        
        return result;
    }
};