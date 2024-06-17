class Solution {
public:
    string frequencySort(string s) {
        map<char,int> mp;
        for(int i=0; i<s.size(); i++)
        {
            mp[s[i]]++;
        }
 //  counting frequency of charcters using map

        string ans="";
        priority_queue<pair<int,char> >pq;

        for(auto i:mp) // iterating through the entire map
        pq.push({i.second,i.first}); // pushing int(freq) first then character
        
        while(!pq.empty())
        {
            int n=pq.top().first; //storing value of frequency in n

            while(n--)
            {
                ans+=pq.top().second;
            }

            pq.pop();
        }
        return ans;


    }
};