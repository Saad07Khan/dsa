class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buycost = prices[0], maxprofit=0;  
        int n = prices.size();

        for(int i=1;i<n;i++)
        {
            int cost = prices[i]- buycost;
            maxprofit = max(maxprofit,cost);

            buycost = min(prices[i],buycost);
        }

        return  maxprofit;
    }
};

/* buycost stores the day to sell the stock,it should be minimum for maximum profit initially maxprofit 0 as if we sell stock on the same day itself
profit will be 0*

/

