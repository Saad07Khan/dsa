class StockSpanner {
     public:
    stack<pair<int, int>> st;
    int i;

    StockSpanner() {
        i=1;
    }
    
    int next(int price) {
       int ans=0;
       while(!st.empty()&&st.top().first<=price)
       {
           st.pop();
       }
       if(st.empty())
       {
           ans=i;
       }
        else
        {
            ans=i-st.top().second;
        }

        st.push({price,i});
        i++;
        return ans;
    }
};


