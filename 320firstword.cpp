class Solution {
  public:
    string firstWord(int n, vector<string> &dictionary) {
        sort(dictionary.begin(),dictionary.end());
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(dictionary[i]==dictionary[j])
                {
                    return "Invalid";
                }
            }
        }
        
        return dictionary[0];
     
    }
};