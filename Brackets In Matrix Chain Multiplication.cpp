class Solution {
  public:
    pair<int,string> getMinMulti(vector<int> &arr,int start,int end,vector<vector<pair<int,string>>> &dp){
        if(start>end){
            string t="";
            t+=char((int)'A'+start-1);
            return {0,t};
        }
        pair<int,string> check={-1,""};
        if(dp[start][end]!=check){
            return dp[start][end];
        }
        if(start==end){
            char c1=char((int)'A'+start-1);
            char c2=char((int)'A'+end);
            string t="";
            return dp[start][end]={arr[start-1]*arr[start]*arr[end+1],t+"("+c1+c2+")"};
        }
        
        long long minMulti=1e9;
        string minString="";
        for(int i=start;i<=end;i++){
            pair<int,string> before=getMinMulti(arr,start,i-1,dp);
            pair<int,string> after=getMinMulti(arr,i+1,end,dp);
            string currString="("+before.second+after.second+")";
            int currMulti=before.first+after.first+(arr[start-1]*arr[i]*arr[end+1]);
            if(currMulti<minMulti){
                minString=currString;
                minMulti=currMulti;
            }
        }
        return dp[start][end]={minMulti,minString};
    }
    
    string matrixChainOrder(vector<int> &arr) {
        vector<vector<pair<int,string>>> dp(arr.size()+1, vector<pair<int,string>>(arr.size()+1,{-1,""}));
        pair<int,string> p=getMinMulti(arr,1,arr.size()-2,dp);
        return p.second;
    }
};

// Time Complexity - O(N*N*2*26)
// Space Complexity - O(N*N*2*26)
