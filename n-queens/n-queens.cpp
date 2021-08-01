class Solution {
public:
    vector<vector<string>> solveNQueens(int n)
    {
        int ** board = new int* [n];
        for(int i = 0; i<n; ++i)
        {
            board[i] = new int[n];
            for(int j = 0; j<n; ++j)
            {
                board[i][j] = 0;
            }
        }
        vector<vector<string>> res;
        backtrack(0, board, n, res);
        return res;
    }
    
    void backtrack(int numQueen, int ** board, int n, vector<vector<string>> &result)
    {
        if(numQueen == n)
        {
            vector<string> subres;
            string temp = "";
            for(int i = 0; i<n; ++i)
            {
                temp = "";
                for(int j = 0; j<n; ++j)
                {
                    if(board[i][j] == 0)
                    {
                        temp += '.';
                    }else
                    {
                        temp += 'Q';
                    }
                }
                subres.push_back(temp);
            }
            result.push_back(subres);
            return;
        }
        for(int i = 0; i<n; ++i)
        {
            if(canPlace(board, i, numQueen, n))
            {
                board[i][numQueen] = 1;
                backtrack(numQueen+1, board, n, result);
                board[i][numQueen] = 0;
            }
        }   
    }
    
    bool canPlace(int ** board, int row, int col, int n)
    {
        // check vertically
        for(int i = 0; i<n; ++i)
        {
            if(i != row)
            {
                if(board[i][col] == 1)
                {
                    return false;
                }
            }
            
        }
        // check horizontally
        for(int i = 0; i<n; ++i)
        {
            if(i != col)
            {
                if(board[row][i] == 1)
                {
                    return false;
                }
            } 
        }
        // check diagonnally bottom left to top right
        int sumRC = row + col;
        for(int i = 0; i<n; ++i)
        {
            if(sumRC - i < n && sumRC - i >= 0)
            {
                int tempCol = sumRC - i;
                if(board[i][tempCol] == 1)
                {
                    return false;
                }
            }
        }
        // check diagonally top left to bottom right
        int diffRC = row - col;
        for(int i = 0; i<n; ++i)
        {
            if(i - diffRC < n && i - diffRC >= 0)
            {
                int tempCol = i - diffRC;
                if(board[i][tempCol] == 1)
                {
                    return false;
                }
            }
        }
        return true;
    }
    
    
};