class Solution {
public:
    int maxCoins(vector<int>& nums)
    {
        int n = nums.size();
        int dp[n][n];
        for(int a = 0; a<n; ++a)
        {
            for(int b = 0; b<n; ++b)
            {
                dp[a][b] = 0;
            }
        }
        // window size
        for(int len = 1; len <=n; ++len)
        {
            // left pointer position
            for(int i = 0; i<n-len+1; ++i)
            {
                // right pointer position
                int j = i+len-1;
                //pointer to loop through the window
                for(int k = i; k <= j; ++k)
                {
                    // deal with out of bound value (array)
                    int leftValue = 1;
                    int rightValue = 1;
                    if(i != 0)
                    {
                        leftValue = nums[i-1];
                    }
                    if(j != n-1)
                    {
                        rightValue = nums[j+1];
                    }
                    
                    // deal with left and right values of the current position within a window
                    int before = 0;
                    int after = 0;
                    if(k != i)
                    {
                        before = dp[i][k-1];
                    }
                    if(k != j)
                    {
                        after = dp[k+1][j];
                    }
                    
                    dp[i][j] = max(dp[i][j], before+after+(leftValue*nums[k]*rightValue) );
                }
                
            }
        }
        return dp[0][n-1];
    }
};