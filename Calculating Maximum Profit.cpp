class Solution {
public:
    int getMaxProfit(int remTrans, int buy, int idx, vector<int> &prices,vector<vector<vector<int>>> &dp){
        if(idx==prices.size()){
            return 0;
        }
        if(dp[idx][remTrans][buy]!=-1){
            return dp[idx][remTrans][buy];
        }
        if(buy==1){
            if(remTrans>0){
                return dp[idx][remTrans][buy]=max(getMaxProfit(remTrans-1,0,idx+1,prices,dp)-prices[idx],getMaxProfit(remTrans,1,idx+1,prices,dp));
            }else{
                return dp[idx][remTrans][buy]=getMaxProfit(remTrans,1,idx+1,prices,dp);
            }
        }else{
            return dp[idx][remTrans][buy]=max(getMaxProfit(remTrans,1,idx+1,prices,dp)+prices[idx],getMaxProfit(remTrans,0,idx+1,prices,dp));
        }
    }

    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(k+1, vector<int>(2,-1)));
        return getMaxProfit(k,true,0,prices,dp);
    }
};

// Time Complexity - O(N*(K+1)*2)
// Space Complexity - O(N*(K+1)*2)
