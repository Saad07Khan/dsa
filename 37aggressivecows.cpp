bool canweplace(vector<int> &stalls,int mid,int cows)
{
    int cowcount=1;
    int last = stalls[0];

    for(int i=1;i<stalls.size();i++)
    {
        if(stalls[i]-last>=mid)
        {
            cowcount+=1;
            last=stalls[i]; 
        }

        if(cowcount>=cows)
        {
            return true;
        }
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    int n = stalls.size();
    sort(stalls.begin(),stalls.end());

    int low=1; //min dist has to be 1
    int high= stalls[n-1]-stalls[0]; // max distance between two cows can only be from highest-lowest element of array

    
    while(low<=high)
    {
        int mid = (low+high)/2;

        if(canweplace(stalls, mid,  k)==true)
        {
            low=mid+1;//since we want the maximum we go towards right

        }

        else
        {
            high=mid-1;
        }

    }

    return high;

}