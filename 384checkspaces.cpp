// class Solution {
// public:
//     string addSpaces(string s, vector<int>& spaces) {
        
//         for(int i=0;i<spaces.size();i++)
//         {
//             int pos= spaces[i];
//             s.insert(pos+i," ");
//         }

//         return s;
//     }
// };

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        
        int n=s.size();
        int m=spaces.size();
        string str;

        int i=0;
        int j=0;
        while(i<n)
        {
            if(j<m&& i==spaces[j])
            {
                str.push_back(' ');
                j++;
            }
            else
            {
                str.push_back(s[i]);
                i++;
            }
        }

        return str;

    }
};