class Solution {
public:
//     int longestValidParentheses(string s)
//     {
//         if(s.length()<=1)
//         {
//             return 0;
//         }
        
//     }
    
    //using 2 variables approache
    int longestValidParentheses(string s)
    {
        if(s.length()<=1)
        {
            return 0;
        }

        int left = 0;
        int right = 0;
        int maximum = 0;
        for(int i = 0; i<s.length(); ++i)
        {
            if(s[i] == '(')
            {
                left ++;
            }else
            {
                right ++;
            }

            if(left == right)
            {
                maximum = max(maximum, 2*right);

            }else if(right > left)
            {
                right = 0;
                left = 0;  
            }
        }
        right = 0;
        left = 0;
        for(int i = s.length()-1; i>=0; --i)
        {
            if(s[i] == '(')
            {
                left ++;
            }else
            {
                right ++;
            }

            if(left == right)
            {
                maximum = max(maximum, 2*left);

            }else if(left > right)
            {
                right = 0;
                left = 0;  
            }
        }
        return maximum;
    }
    
};