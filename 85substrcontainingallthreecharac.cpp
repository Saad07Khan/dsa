class Solution
{
public:
    int numberOfSubstrings(string s)
    {

        int i = 0;
        int j = 0;
        int n = s.length();
        int count = 0;
        unordered_map<char, int> mp;

        while (i < n)
        {
            mp[s[i]]++;

            while (mp['a'] >= 1 && mp['b'] >= 1 && mp['c'] >= 1)
            {
                count += (n - i); // Increment the count by the number of valid substrings that end at index 'i'.

                mp[s[j]]--; // remove frequency of the character from the map
                j++; // decrease the window size by j++
            }

            i++;
        }
        return count;
    }
};