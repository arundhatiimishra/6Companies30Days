class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long maxSum=0;
        long long currSum=0;
        unordered_map<int,int> countDistEle;
        for(int i=0;i<k;i++){
            currSum+=nums[i];
            countDistEle[nums[i]]++;
        }
        if(countDistEle.size()==k){
            maxSum=max(maxSum,currSum);
        }
        for(int i=k;i<nums.size();i++){
            currSum-=nums[i-k];
            currSum+=nums[i];
            if(countDistEle[nums[i-k]]==1){
                countDistEle.erase(nums[i-k]);
            }else{
                countDistEle[nums[i-k]]--;
            }
            countDistEle[nums[i]]++;
            if(countDistEle.size()==k){
                maxSum=max(maxSum,currSum);
            }
        }
        return maxSum;   
    }
};

// Time Complexity - O(N)
// Space Complexity - O(N)
