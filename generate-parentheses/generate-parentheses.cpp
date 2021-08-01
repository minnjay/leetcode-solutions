class Solution {
public:
    // approach 1: backtracking
    vector<string> generateParenthesis(int n)
    {
        vector<string> result;
        string temp = "";
        backtrack(result, temp, 0, 0, n);
        return result;
    }
    
    void backtrack(vector<string>& res, string& temp, int open, int close, int max)
    {
        if(temp.length() == max*2)
        {
            res.push_back(temp);
            return;
        }
        
        if(open < max)
        {
            temp += "(";
            backtrack(res, temp, open+1, close, max);
            temp.pop_back();
        }
        if(close < open)
        {
            temp+= ")";
            backtrack(res, temp, open, close+1, max);
            temp.pop_back();
        }
        
    }
};