class Solution {
public:
    
    int coinChange(vector<int>& coins, int amount)
    {
        if(amount<1)
        {
            return 0;
        }
        vector<int> dp(amount, 0);
        return canChange(coins, amount, dp);
    }
    
    int canChange(vector<int>& coins, int amount, vector<int>& dp)
    {
        if(amount < 0)
        {
            return -1;
        }
        if(amount == 0)
        {
            return 0;
        }
        if(dp[amount-1]!=0)
        {
            return dp[amount-1];
        }
        int min = INT_MAX;
        for( auto coin: coins)
        {
            int result = canChange(coins, amount-coin, dp);
            if(result >= 0 && result < min)
            {
                min = 1 + result;
            }
        }
        dp[amount-1] = (min == INT_MAX)? -1: min;
        
        return dp[amount-1];
        
    }
    
};