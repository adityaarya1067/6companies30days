class Solution {
public:
    int longestString(int a, int b, int z) {
        int maxi = max(a,b);
        int mini = min(a,b);

        int diff = maxi-mini;
        int k = 0;
        if(maxi==mini)k=mini;
        else k = mini+1;
        return k*2+mini*2+z*2;
    }
};