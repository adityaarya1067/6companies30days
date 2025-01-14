class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long sum= mass;
        sort(asteroids.begin(),asteroids.end());
        if(asteroids[0]>mass)return false;
        for(int i=1;i<asteroids.size();i++){
          sum+=asteroids[i-1];
            if(asteroids[i]>sum)return false;
        }
        return true;
    }
};