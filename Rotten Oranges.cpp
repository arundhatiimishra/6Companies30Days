class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<int>> rottenOranges=grid;
        queue<vector<int>> q;
        for(int i=0;i<rottenOranges.size();i++){
            for(int j=0;j<rottenOranges[i].size();j++){
                if(rottenOranges[i][j]==2){
                    q.push({i,j,0});
                }
            }
        }
        vector<int> x={0,-1,0,1};
        vector<int> y={-1,0,1,0};
        int maxTime=0;
        while(q.empty()==false){
            int i=q.front()[0];
            int j=q.front()[1];
            int time=q.front()[2];
            q.pop();
            for(int k=0;k<4;k++){
                int nextX=i+x[k];
                int nextY=j+y[k];
                if(nextX>=0 && nextY>=0 && nextX<=grid.size()-1 && nextY<=grid[0].size()-1 && rottenOranges[nextX][nextY]==1){
                    q.push({nextX,nextY,time+1});
                    rottenOranges[nextX][nextY]=2;
                    maxTime=max(maxTime,time+1);
                }
            }
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(rottenOranges[i][j]==1){
                    return -1;
                }
            }
        }
        return maxTime;
    }
};

// Time Complexity - O(N*M)
// Space Complexity - O(N*M)
