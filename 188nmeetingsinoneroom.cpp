class Solution
{
    public:
    static bool cmp(pair<int,int>a, pair<int,int>b)
    {
        return a.second<b.second; //ending time should be sorted
    }
    int maxMeetings(int start[], int end[], int n)
    {
       vector<pair<int,int>>v;
       
       for(int i=0;i<n;i++)
       {
           pair<int,int>p=make_pair(start[i],end[i]); //store both the arrays as pairs
           v.push_back(p);
       }     
       sort(v.begin(),v.end(),cmp); //sort according to the ending times
       
       int count=1;              // count=1 as considering first element as a part of the soln
       int ansEnd=v[0].second;  //consider first element as a part of soln as its greedy method,
       
       for(int i=1;i<n;i++)
       {
           if(ansEnd<v[i].first)
           {
               count++;
               ansEnd=v[i].second;
           }
       }
       
       return count;
    }
};