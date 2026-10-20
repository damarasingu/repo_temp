
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefixZero(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefixZero[i + 1] =
                prefixZero[i] + (nums[i] == 0);
        }

        int maxLength = 0;

        for (int start = 0; start < n; start++) {
            int low = start;
            int high = n - 1;
            int farthest = start - 1;

            while (low <= high) {
                int mid = low + (high - low) / 2;

                int zeroCount =
                    prefixZero[mid + 1] -
                    prefixZero[start];

                if (zeroCount <= k) {
                    farthest = mid;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }

            if (farthest >= start) {
                maxLength = max(
                    maxLength,
                    farthest - start + 1
                );
            }
        }

        return maxLength;
    }
};

