class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double cheftime=customers[0][0];
        double waitingTime=0;
        int n= customers.size();
        for(auto it:customers)
        {
            if(cheftime<it[0])
            {
                cheftime+=((it[0]-cheftime)+it[1]);
            }
            else
            {
            cheftime+=it[1];
            }
            double arrival = it[0];
            waitingTime+= (cheftime-arrival);
        }

        return (waitingTime/n);
    }
};