class Solution {
public:
    // recursive solution
    // bool canPartitionKSubsets(vector<int>& nums, int k)
    // {
    //     int sum = accumulate(nums.begin(), nums.end(),0);
    //     if(sum%k != 0)
    //     {
    //         return false;
    //     }else
    //     {
    //         int targetSum = sum/k;
    //         vector<bool> usedArr(nums.size(), false);
    //         return canPartition(nums, 0, usedArr, k, 0, targetSum);
    //     }
    // }
    
    
    // dynamic programming approach with bit masking
    bool canPartitionKSubsets(vector<int>& nums, int k)
    {
        int sum = accumulate(nums.begin(), nums.end(),0);
        if(sum%k != 0)
        {
            return false;
        }else
        {
            sum = sum/k;
            int n = nums.size();
            vector<int> dp( (1<<n)+1 , -1);
            dp[0] = 0;
            
            for(int i = 0; i< (1<<n); ++i)
            {
                if(dp[i] == -1)
                {
                    continue;
                }
                for(int j = 0; j<n; ++j)
                {
                    int isNot =  ( (i&(1<<j)) == 0 ) ; 
                    if(isNot)
                    {
                        if(dp[i]+nums[j] <= sum)
                        {
                            int newSubset = i|(1<<j) ; 
                            dp[newSubset] = (dp[i]+nums[j])==sum ? 0 : (dp[i]+nums[j]) ;  
                        }
                    }
                }
            }
            return dp[(1<<n)-1] == 0;
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