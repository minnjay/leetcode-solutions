class Solution {
public:
    int maxHist(vector<int>& h, int n)
    {
        int maximum = 0;
        int result, counter;

        for(int i = 0; i<n; ++i)
        {
            if(i == 0)
            {
                int a = i+1;
                counter = 0;
                while( a<n && h[a]>=h[i])
                {
                    counter++;
                    a++;
                }
                result = (counter+1)*h[i];
                if(result>maximum)
                {
                    maximum = result;
                }
            }else if(i == n-1)
            {
                int a = i-1;
                counter = 0;
                while(a >= 0 && h[a]>=h[i])
                {
                    counter++;
                    a--;
                }
                result = (counter+1)*h[i];
                if(result>maximum)
                {
                    maximum = result;
                }
            }else
            {
                int a = i-1;
                counter = 0;
                while(a >= 0 && h[a]>=h[i])
                {
                    counter++;
                    a--;
                }
                a = i+1;
                while( a<n && h[a]>=h[i])
                {
                    counter++;
                    a++;
                }
                result = (counter+1)*h[i];
                if(result>maximum)
                {
                    maximum = result;
                }
            }
        }
        return maximum;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix)
    {       
        int numRow = matrix.size();
        if(numRow == 0)
        {
            return 0;
        }
        int numCol = matrix[0].size();
        vector<int> dp(numCol, 0);
        
        for(int a = 0; a<numCol; ++a)
        {
            dp[a] = 0;
        }
        
        int maximum = 0;
        for(int i = 0; i<numRow; ++i)
        {
            for(int j = 0; j<numCol; ++j)
            {
                if(matrix[i][j] == '1')
                {
                    dp[j] ++;
                }
                else if(matrix[i][j] == '0')
                {
                    dp[j] = 0;
                }
            }
            // calculate rectangle area;
            maximum = max(maximum, maxHist(dp, numCol));
        }
        return maximum;
    }
};