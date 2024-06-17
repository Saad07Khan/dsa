string minWindow(string s, string t)
{
    if (s.length() < t.length() || s.length() == 0 || t.length() == 0)
    {
        return "";
    }
    vector<int> v(256, 0);
    for (int i = 0; i < t.length(); i++)
    {
        v[t[i]]++;
    }

    int start = 0, end = 0, count = 0, ans_start = 0, minlength = INT_MAX;

    while (end < s.length())
    {
        if (v[s[end]] > 0)
        {
            count++;
        }

        v[s[end]]--;

        while (count == t.length())
        {
            if (minlength > end - start + 1 && start > ans_start)
            {
                minlength = end - start + 1;
                ans_start = start;
            }

            v[s[start]]++; // increasing the frequency of the character again as we are moving the window to the right from start pointer
            if (v[s[start]] > 0)
                count--;

            start++;
        }

        end++;
    }

    if (minlength == INT_MAX)
    {
        return "";
    }

    return s.substr(ans_start, minlength);

}