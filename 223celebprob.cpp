class Solution
{
    bool knows(vector<vector<int>> &M, int a, int b)
    {
        if (M[a][b] == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

public:
    int celebrity(vector<vector<int>> &M, int n)
    {
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            st.push(i);
        }

        while (st.size() > 1)
        {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            if (knows(M, a, b) == true)
            {
                st.push(b);
            }
            else
            {
                st.push(a);
            }
        }

        int ans = st.top();
        st.pop();
        int zerocount = 0;
        for (int i = 0; i < n; i++)
        {
            if (M[ans][i] == 0)
                zerocount++;
        }

        if (zerocount != n)
        {
            return -1;
        }

        int count1 = 0;

        for (int i = 0; i < n; i++)
        {
            if (M[i][ans] == 1)
                count1++;
        }
        if (count1 != n - 1)
        {
            return -1;
        }

        return ans;
    }
};



Stack<int>St = new Stack<>();
for(int i=0;i<n;i++)
{
    st.push(i);
}

while(st.size()>1)
{
    int x = st.top();
    st.pop();
    int y = st.top();
    st.pop();

    if(knows(x,y)==true)
    {
        
    }
}