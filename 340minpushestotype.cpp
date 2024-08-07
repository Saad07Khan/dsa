class Solution {
public:
    int minimumPushes(string word) {
        //map with alphabets and their frequencies

        //sort them in decreasing order
        // if freq high, push 1 until charac 8
        vector<int>frequency(26,0);
        for(int i=0;i<word.size();i++)
        {
            frequency[word[i]-'a']++;
        }
      
        sort(frequency.rbegin(),frequency.rend());
        int cost=0;
        for(int i=0;i<26;i++)
        {
            // if (frequency[i] == 0) break;
            // cost+=(i/8+1)*frequency[i];
            if (i < 8 ) {
             cost += frequency[i]; // 1 press
            } else if (i < 16) {
            cost += frequency[i] * 2; // 2 presses
            } else if (i < 24) {
                cost += frequency[i] * 3; // 3 presses
            } else {
         cost += frequency[i] * 4; // 4 presses
            }
            
        }

        return cost;

    }
};