class Solution {
public:
    bool hasValidRows(vector<vector<char>> &board){
        for(int i=0;i<9;i++){
            vector<int> numFreq(9,0);
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    numFreq[board[i][j]-'1']++;
                    if(numFreq[board[i][j]-'1']>1){
                        return false;
                    }
                }
            }
        }
        return true;
    }

    bool hasValidColumns(vector<vector<char>> &board){
        for(int i=0;i<9;i++){
            vector<int> numFreq(9,0);
            for(int j=0;j<9;j++){
                if(board[j][i]!='.'){
                    numFreq[board[j][i]-'1']++;
                    if(numFreq[board[j][i]-'1']>1){
                        return false;
                    }
                }
            }
        }
        return true;       
    }

    bool hasValidBlocks(vector<vector<char>> &board){
        vector<int> rowStart={0,3,6};
        vector<int> colStart={0,3,6};
        for(int i=0;i<rowStart.size();i++){
            for(int j=0;j<colStart.size();j++){
                int currRow=rowStart[i];
                int currCol=colStart[j];
                vector<int> numFreq(9,0);
                for(int a=currRow;a<currRow+3;a++){
                    for(int b=currCol;b<currCol+3;b++){
                        if(board[a][b]!='.'){
                            numFreq[board[a][b]-'1']++;
                            if(numFreq[board[a][b]-'1']>1){
                                return false;
                            }
                        }
                    }
                }
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        if(hasValidRows(board)==true && hasValidColumns(board)==true && hasValidBlocks(board)==true){
            return true;
        }
        return false;
    }
};

// Time Complexity - O(3*9*9)
// Space Complexity - O(9*(9+9+9))
