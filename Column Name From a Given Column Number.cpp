class Solution {
public:
    string convertToTitle(int columnNumber) {
        string answer="";
        int currCol=columnNumber;
        while(currCol!=0){
            int val=currCol%26;
            if(val==0){
                val=26;
            }
            currCol-=val;
            currCol/=26;
            char temp=char(val-1+'A');
            answer=temp+answer;
        }
        return answer;  
    }
};

// Time Complexity - O(log base26 (N))
// Space Complexity -O(1)
