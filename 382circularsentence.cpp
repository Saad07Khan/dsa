class Solution {
public:
    bool isCircularSentence(string sentence) {
        
        stringstream ss(sentence);
        string word;
        vector<string> sentences;
        while (ss >> word) {
            sentences.push_back(word);
        }
        for(int i=0;i<sentences.size()-1;i++)
        {
            string s1= sentences[i];
            string s2=sentences[i+1];
            int n1=s1.size();
            int n2=s2.size();
            if(s1[n1-1]!=s2[0])
            {
                return false;
            }
        }

        int n=sentences.size();
        string s1=sentences[0];
        string s2=sentences[n-1];
        int n3=s2.length();
        if(s2[n3-1]!=s1[0])
        {
            return false;
        }

        return true;
    }
};