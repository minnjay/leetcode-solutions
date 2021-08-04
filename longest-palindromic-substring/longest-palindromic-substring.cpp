class Solution {
public:
    string longestPalindrome(string s)
    {
        if(s.length() == 1)
        {
            return s;
        }
        int n = s.length();
        bool dp[n][n];
        
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j<n; ++j)
            {
                if(i == j)
                {
                    dp[i][j] = true;
                }else
                {
                    dp[i][j] = false;
                }
            }
        }
        
        int longestStart = 0, longestLength = 1;
        for(int start = n-1; start >=0; --start)
        {
            for(int end = start + 1; end < n; ++end)
            {
                if(s[start] == s[end])
                {
                    if(end-start == 1 || dp[start+1][end-1])
                    {
                        dp[start][end] = true;
                        if(longestLength < end-start+1)
                        {
                            longestLength = end-start+1;
                            longestStart = start;
                        }
                    }
                }
            }
        }
        return s.substr(longestStart, longestLength);
        
    }
};