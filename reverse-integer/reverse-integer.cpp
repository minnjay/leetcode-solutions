class Solution {
public:
    int reverse(int x) {
        string temp = to_string(x);
        string res = "";
        long a;

        
        for(int i = temp.length()-1; i>= 0; --i)
        {
            res += temp[i];
        }
        
        a = stol(res);
        
        if(x<0)
        {
            if( a - 2147483648 >0)
            {
                return 0;
            }
            a = -a;
        }else
        {
            if( a - 2147483647 >0)
            {
                return 0;
            }
        }
        
        return (int)a;
        
    }
};