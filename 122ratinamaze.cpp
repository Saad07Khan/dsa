class Solution{
    void solve(int i, int j, vector<vector<int>> &a, int &n, vector<string> &ans, string move, 
     int di[], int dj[]) {
        if(i==n-1 && j==n-1) {
            ans.push_back(move);
            return; 
        }
         string dir="DLRU";
        for(int ind = 0; ind<4;ind++) {
            int nexti = i + di[ind]; 
            int nextj = j + dj[ind]; 
            if(nexti >= 0 && nextj >= 0 && nexti < n && nextj < n && a[nexti][nextj] == 1) {
                a[i][j] = 0;
                solve(nexti, nextj, a, n, ans, move+dir[ind],di, dj);
                a[i][j] = 1; 
            }
        }
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        int di[] = {+1, 0,  0,  -1}; 
        int dj[] = {0, -1,  1,   0}; 

        // string move="";
        if(m[0][0] == 1) solve(0,0,m,n, ans,"",di, dj); 
        return ans; 
    }
};
