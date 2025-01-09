class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<map<char,int>> rows(9),cols(9),subgrid(9);
        for(int i=0;i<9;i++){
           
            for(int j=0;j<9;j++){
                char val = board[i][j];
                if(val=='.')continue;
                if(rows[i].find(val)!=rows[i].end()){
                    return false;
                }
                rows[i][val]++;

                if(cols[j].find(val)!=cols[j].end()){
                    return false;
                }
                cols[j][val]++;

                int index = (i/3)*3+(j/3);

                if(subgrid[index].find(val)!=subgrid[index].end()){
                    return false;
                }
                subgrid[index][val]++;

            }
        }
        return true;
    }
};