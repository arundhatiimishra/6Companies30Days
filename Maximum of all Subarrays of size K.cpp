class Solution {
  public:
    // Function to find maximum of each subarray of size k.
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        priority_queue<vector<int>> pq;
        vector<int> answer;
        for(int i=0;i<arr.size();i++){
            pq.push({arr[i],i});
            if(i>=k-1){
                int windowMax=0;
                while(pq.empty()==false){
                    if(pq.top()[1]>=i-k+1){
                        windowMax=pq.top()[0];
                        break;
                    }else{
                        pq.pop();
                    }
                }
                answer.push_back(windowMax);
            }
        }
        return answer;
    }
};

// Time Complexity - O(N*log(N))
// Space Complexity - O(N)
