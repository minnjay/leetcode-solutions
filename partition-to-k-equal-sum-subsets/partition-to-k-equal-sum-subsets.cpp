class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k)
    {
        int sum = accumulate(nums.begin(), nums.end(),0);
        if(sum%k != 0 || k == 0)
        {
            return false;
        }else
        {
            int targetSum = sum/k;
            vector<bool> usedArr(nums.size(), false);
            return canPartition(nums, 0, usedArr, k, 0, targetSum);
        }
    }
    
    bool canPartition(vector<int>& nums, int start, vector<bool>& used, int k, int progressSum, int targetSum)
    {
        if(k == 1)
        {
            return true;
        }
        if(progressSum > targetSum)
        {
            return false;
        }
        if(progressSum == targetSum)
        {
            return canPartition(nums, 0,used, k-1,0, targetSum);
        }
        
        for(int i = start; i<nums.size(); ++i)
        {
            if(!used[i])
            {
                used[i] = true;
                if(canPartition(nums, start+1, used, k, progressSum+nums[i],targetSum))
                {
                    return true;
                }
                used[i] = false;
            }
        }
        return false;
    }
};