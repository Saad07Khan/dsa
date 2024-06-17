class Solution
{
public:
    bool solve(vector<vector<char>> &board, string word, int i, int j, int n, int m, int k)
    {
        if (k == word.length())
            return true;
        if (i < 0 || i >= n || j < 0 || j >= m || word[k] != board[i][j] || board[i][j] == '.')
            return false;
        board[i][j] = '.';
        bool temp = false;
        int x[4] = {0, 0, -1, 1}; //left,right,up,down
        int y[4] = {-1, 1, 0, 0};
        for (int idx = 0; idx < 4; idx++)
            temp = temp || word_search(board, word, i + x[idx], j + y[idx], n, m, k + 1);
        board[i][j] = word[k];
        return temp;
    }
    bool exist(vector<vector<char>> &board, string word)
    {
        int n = board.size();
        if (n == 0)
            return false;
        int m = board[0].size();
        if (word.size() == 0)
            return false;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (word[0][0] == board[i][j])
                {
                    if (solve(board, word, i, j, n, m, k))
                        return true;
                }
            }
        }
        return false;
    }
};