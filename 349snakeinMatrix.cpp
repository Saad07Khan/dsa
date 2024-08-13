class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int row=0;
        int col=0;
        for(int i=0;i<commands.size();i++)
        {
            if(commands[i]=="UP")
            {
                row=row-1;
                
            }
            else if(commands[i]=="DOWN")
            {
                row=row+1;
            }
            else if(commands[i]=="LEFT")
            {
                col=col-1;
            }
            else
            {
                col=col+1;
            }
        }

        long long ans = row*n+col;
        return ans;
        
    }
};