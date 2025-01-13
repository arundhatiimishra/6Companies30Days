class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        long long currMass=mass;
        for(int i=0;i<asteroids.size();i++){
            if(currMass>=asteroids[i]){
                currMass+=asteroids[i];
            }else{
                return false;
            }
        }
        return true;
    }
};

// Time Complexity - O(N*log(N))
// Space Complexity - O(1)
