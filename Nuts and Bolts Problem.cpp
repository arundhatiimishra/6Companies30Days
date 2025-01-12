class Solution {
  public:
    void matchPairs(int n, char nuts[], char bolts[]) {
        vector<char> order={'!','#','$','%','&','*','?','@','^'};
        unordered_map<char,int> mp;
        for(int i=0;i<n;i++){
            mp[nuts[i]]++;
            mp[bolts[i]]++;
        }
        char answer[n];
        int ptrAnswer=0;
        for(int i=0;i<order.size();i++){
            if(mp[order[i]]==2){
                answer[ptrAnswer]=order[i];
                ptrAnswer++;
            }
        }
        for(int i=0;i<n;i++){
            nuts[i]=answer[i];
            bolts[i]=answer[i];
        }
    }
};

// Time Complexity - O(N)
// Space Complexity - O(256+N)
