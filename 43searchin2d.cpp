//  O(log(m * n)) solution

class Solution {
public:

    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int n= matrix.size(); // to get the number of rows
        int m = matrix[0].size(); // to get the number of coloumns
        int low=0;
        int high = (n*m)-1;

        while(low<=high)
        {
            int mid = (low+high)/2;

            int rows = mid/m;
            int coloumns= mid%m;

            if(matrix[rows][coloumns]==target)
            {
                return true;
            }

            else if(matrix[rows][coloumns]<target)
            {
                low=mid+1;
            }

            else
            {
                high=mid-1;
            }


        }

        return false;
   }
};


// another solution
bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int n=matrix.size();
        int m = matrix[0].size();
        int rows=0;
        int coloumns = m-1;
        while(rows<n && coloumns>=0) // until we have rows and coloumns becuase while moving we might cross the rows or cross the coloumns as for coloumns we move left -- and rows we might right ++
        {
            if(matrix[rows][coloumns]==target)
            {
                return true;
            }

            else if(matrix[rows][coloumns]>target)
            {
                coloumns--;
            }
            else
            {
                rows++;
            }
        }
        return false;
    }


