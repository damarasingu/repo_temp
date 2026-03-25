class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        long long total = 0;

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                total += grid[i][j];

        if (total % 2) return false;

        unordered_map<long long, int> mp;

        long long curr = 0;
        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n; j++)
                curr += grid[i][j];
            mp[curr]++;
        }

        curr = 0;
        for (int j = 0; j < n - 1; j++) {
            for (int i = 0; i < m; i++)
                curr += grid[i][j];
            mp[curr]++;
        }

        return mp[total / 2] > 0;
    }
};