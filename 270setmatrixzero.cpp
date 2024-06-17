// O(N) space complexity soln
class Solution
{
public:
    void setMatrix(int n, int m, vector<vector<int>> &matrix)
    {
        int n1 = matrix.size();
        int m1 = matrix[0].size();
        for (int j = 0; j < m1; j++)
        {
            matrix[n][j] = 0;
        }
        for (int i = 0; i < n1; i++)
        {
            matrix[i][m] = 0;
        }
    }
    void setZeroes(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<pair<int, int>> pairs;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == 0)
                {
                    pairs.push_back({i, j});
                }
            }
        }

        for (auto it : pairs)
        {
            setMatrix(it.first, it.second, matrix);
        }
    }
};

// Optimized

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        // for the first row & first col set x=1 & y=1 respectively as flag values.
        int x=1, y=1;
        
        //iterating first col
         for(int i=0; i<rows; i++)
         {
             if(matrix[i][0] == 0)
                 y = 0;
         }
        
         //iterating first row
         for(int j=0; j<cols; j++)
         {
             if(matrix[0][j] == 0)
                 x = 0;
         }
        
          //iterating over inner matrix
          for(int i=1; i<rows; i++)
          {
              for(int j=1; j<cols; j++)
              {
                  /* if in inner matrix you find any 0 then set 
                    corresponding initial row & column markers as 0 */
                  
                  if(matrix[i][j] == 0)
                  {
                      matrix[i][0]=0;
                      matrix[0][j]=0;
                  }
              }
          }
        
        /* when the above markers are 0, then set corresponding 
           whole row and column markers as 0 */
        
          for(int j=1; j<cols; j++)
          {
              if(matrix[0][j]==0)
              {
                  for(int i=1; i<rows; i++)
                  {

                      matrix[i][j]=0;
                  }
              }
          }
        
         for(int i=1; i<rows; i++)
         {
            if(matrix[i][0]==0)
            {
                for(int j=1; j<cols; j++)
                {

                    matrix[i][j] = 0;

                }
            }
         }
        
        // if x=0 and y=0 then set whole row and column as 0
    
        if(x==0)
        {
          for(int j=0;j<cols;j++)
              matrix[0][j] = 0;
        }
        
       if(y==0)
       {
         for(int i=0;i<rows;i++) 
             matrix[i][0] = 0;
       }
        


    }
};

