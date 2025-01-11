class Solution {
public:
    int firstUniqChar(string s) {
        int firstNonRepIdx=-1;
        vector<int> freq(26,0);
        for(int i=0;i<s.size();i++){
            freq[s[i]-'a']++;
        }
        for(int i=0;i<s.size();i++){
            if(freq[s[i]-'a']==1){
                firstNonRepIdx=i;
                break;
            }
        }
        return firstNonRepIdx;
    }
};

// Time Complexity - O(N*2)
// Space Complexity - O(26)
