class Solution
{
    public:
    //Function to return the sorted array.
    vector <int> nearlySorted(int arr[], int num, int K){
        priority_queue<int,vector<int>,greater<int>>minh;
        vector<int>ans;
        for(int i=0;i<num;i++)
        {
            minh.push(arr[i]);
            if(minh.size()>K)
            {
                ans.push_back(minh.top());
                minh.pop();
            }
        }
        
        while(!minh.empty())
        {
            ans.push_back(minh.top());
            minh.pop();
        }
        
        return ans;
        
    }
};