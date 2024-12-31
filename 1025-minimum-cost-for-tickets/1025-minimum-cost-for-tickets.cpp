class Solution {
private:
    int minCostHelper(vector<int>& days, vector<int>& costs,int i, vector<int>& dp){
        if(i == days.size()) return 0;
        if(dp[i] != -1) return dp[i];
        int cost1 = costs[0] + minCostHelper(days,costs,i+1,dp);
        int k = i;
        while(k<days.size() && days[i]+7 > days[k]){
            k++;
        }
        int cost2 = costs[1] + minCostHelper(days,costs,k,dp);
        k = i;
        while(k<days.size() && days[i]+30 > days[k]){
            k++;
        }
        int cost3 = costs[2] + minCostHelper(days,costs,k,dp);
        return dp[i] = min(cost1,min(cost2,cost3));
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size()+1,-1);
        return minCostHelper(days,costs,0,dp);
    }
};