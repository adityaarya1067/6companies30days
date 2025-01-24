#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long lcm(long long a, long long b) {
        return (a / __gcd(a, b)) * b; }

    bool isValid(int x, int d1, int d2, int cnt1, int cnt2) {
        long long lcmVal = lcm(d1, d2);
        
        long long totalNonDivByD1 = x - x / d1;
        long long totalNonDivByD2 = x - x / d2;
        long long totalNonDivByBoth = x - x / lcmVal;

        return totalNonDivByD1 >= cnt1 && totalNonDivByD2 >= cnt2 && totalNonDivByBoth >= (cnt1 + cnt2);
    }

    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        int left = 1, right = INT_MAX, ans = 0;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isValid(mid, divisor1, divisor2, uniqueCnt1, uniqueCnt2)) {
                ans = mid;
                right = mid - 1; 
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};
