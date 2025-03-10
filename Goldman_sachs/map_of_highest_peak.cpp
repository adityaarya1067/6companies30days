class Solution {
public:
#define func pair<int,int>
bool valid(int &x,int&y,int&m,int&n){
    return(x>=0 && x<m && y>=0 &&y<n);
}
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        queue<func> q;
        int m = isWater.size();
        int n = isWater[0].size();
        vector<vector<int>> height(m,vector<int>(n,0));
        vector<vector<bool>> visited(m,vector<bool>(n,false));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(isWater[i][j]==1){
                    q.push(make_pair(i,j));
                    visited[i][j]=true;
                }
            }
        }
        vector<int> dir = {-1,0,1,0,-1};
        int level = 0;
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                func curr = q.front();
                q.pop();

                int x  = curr.first;
                int y = curr.second;
                for(int d=0;d<4;d++){
                    int newX= x+dir[d];
                    int newY = y+dir[d+1];
                    if(valid(newX,newY,m,n) && !visited[newX][newY]){
                        q.push(make_pair(newX,newY));
                        height[newX][newY]=level+1;
                         visited[newX][newY]=true;
                    }
                }
            }
            level++;
        }
        return height;
    }
};