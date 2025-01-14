class Solution {
public:
    int MOD=1e9+7;

    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        for(int i=0;i<k;i++){
            int topEle=pq.top();
            pq.pop();
            pq.push(topEle+1);
        }
        unsigned long long answer=1;
        while(pq.empty()==false){
            answer*=pq.top();
            answer%=MOD;
            pq.pop();
        }
        return answer;
    }
};

// Time Complexity - O(N*log(N)+O(k*log(N))
// Space Complexity - O(N)
