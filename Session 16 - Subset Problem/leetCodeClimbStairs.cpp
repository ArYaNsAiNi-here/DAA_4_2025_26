#include <vector>

class Solution {
public:
    int climbStairs(int n) {
        int ft = 1;
        int st = 2;
        int tt = 0;
        for (int i = 3; i <= n; i++) {
            tt = ft + st;
            ft = st;
            st = tt;
        }
        if (n == 1 || n == 2) {
            return n;
        }
        return tt;
    }
};