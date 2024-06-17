
int summ(vector<int>&boards)
{
    int sum=0;
    for(int i=0;i<boards.size();i++)
    {
        sum+=boards[i];
    }

    return sum;
}

int findmax(vector<int>&boards)
{
    int max=boards[0];

    for(int i=0;i<boards.size();i++)
    {
        if(boards[i]>max)
        {
            max=boards[i];
        }
    }

    return max;
}

int canpaint(vector<int> &boards, int mid)
{
    int painters=1;
    int board=0;

    for(int i=0;i<boards.size();i++)
    {
        if(board+boards[i]<=mid)
        {
            board+=boards[i];
        }
        else
        {
            painters+=1;
            board=boards[i];
        }

    }
    return painters;

}
int findLargestMinDistance(vector<int> &boards, int k)
{



    int low= findmax(boards);
    int high= summ(boards);
    

    while(low<=high)
    {
        int mid=(low+high)/2;
        int pcount = canpaint(boards,mid);
        if(pcount>k)
        {
            low=mid+1;
        }
        else{
            high=mid-1; // since we need the minimum time to get this job done we go on the left side
        }

        
    }
    return low;
    
}   