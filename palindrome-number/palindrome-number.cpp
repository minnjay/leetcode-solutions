class Solution {
public:
    bool isPalindrome(int x)
    {
        if(x<0)
        {
            return false;
        }
        else
        {
            string res = "";
            string compare = to_string(x);
            for(int i = compare.length()-1; i>=0; --i)
            {
                res += compare[i];
            }
            if(res == compare)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
            
        
    }
};