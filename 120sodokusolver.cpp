class Solution {
public:

bool solve(vector<vector<char>>& board)
{
    for(int i=0;i<board.size();i++)
    {
        for(int j=0;j<board[0].size();j++)
        {
            if(board[i][j]=='.')
            {
               for(char c='1';c<='9';c++)
               {
                   if(isvalid(board,i,j,c))
                   {
                       board[i][j]=c;
                       if(solve(board)==true)
                       {
                       return true;
                       }
                   
                       board[i][j]='.';
                       
                   }
               }
               return false; // not able to place any number
            }
        }
    }
    return true; // if soduku is already solved
}

bool isvalid(vector<vector<char>>& board,int row, int col, char c)
{
    for(int i=0;i<9;i++)
    {
        if(board[i][col]==c)//col stays constant row is changing
        {
            return false;
        }
        if(board[row][i]==c)//row stays constant coloumn is changing
        {
            return false;
        }
        if(board[3*(row/3)+i/3][3*(col/3)+i%3] == c)
        {
            return false;
        }
    }
    return true;
}
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};


