#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {

        int n = nums.size();

        vector<int> diff(2 * limit + 2, 0);

        for(int i = 0; i < n / 2; i++) {

            int a = nums[i];
            int b = nums[n - 1 - i];

            int x = min(a, b);
            int y = max(a, b);

            // one move range
            diff[x + 1]--;
            diff[y + limit + 1]++;

            // exact sum -> 0 move
            diff[a + b]--;
            diff[a + b + 1]++;
        }

        int pairs = n / 2;

        // initially every pair needs 2 moves
        int cur = 2 * pairs;

        int ans = INT_MAX;

        for(int s = 2; s <= 2 * limit; s++) {

            cur += diff[s];

            ans = min(ans, cur);
        }

        return ans;
    }
};