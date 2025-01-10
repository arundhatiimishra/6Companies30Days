class Solution {
public:
    int longestMountain(vector<int>& arr) {
        vector<int> contIncre1(arr.size(),1);
        vector<int> contIncre2(arr.size(),1);
        for(int i=1;i<arr.size();i++){
            if(arr[i]>arr[i-1]){
                contIncre1[i]=contIncre1[i-1]+1;
            }
        }
        for(int i=arr.size()-2;i>=0;i--){
            if(arr[i]>arr[i+1]){
                contIncre2[i]=contIncre2[i+1]+1;
            }
        }
        int maxLen=0;
        for(int i=0;i<arr.size();i++){
            if(contIncre1[i]>1 && contIncre2[i]>1){
                maxLen=max(maxLen,contIncre1[i]+contIncre2[i]-1);
            }
        }
        if(maxLen>2){
            return maxLen;
        }
        return 0;
    }
};

// Time Complexity - O(N)
// Space Complexity -  O(N*2)
