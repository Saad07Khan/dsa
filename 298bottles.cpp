class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        // int drank = numBottles/numExchange;
        // int remainder = numBottles%numExchange;
        // int newdrank= (drank+remainder)/(numExchange);

        // int ans = numBottles+drank+newdrank;
        // return ans;

        int ans = numBottles;
        int empty=numBottles;
        while(empty>=numExchange)
        {
            int newBottles= empty/numExchange;
            ans+=newBottles;
            empty= newBottles + (empty%numExchange);

        }

        return ans;
    }
};