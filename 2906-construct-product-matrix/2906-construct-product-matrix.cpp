class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int mod = 12345;

        int size = n * m;
        vector<int> arr(size);

        // Step 1: Flatten
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                arr[i * m + j] = grid[i][j] % mod;
            }
        }

        // Step 2: Prefix
        vector<int> prefix(size, 1), suffix(size, 1);

        for(int i = 1; i < size; i++) {
            prefix[i] = (prefix[i - 1] * arr[i - 1]) % mod;
        }

        // Step 3: Suffix
        for(int i = size - 2; i >= 0; i--) {
            suffix[i] = (suffix[i + 1] * arr[i + 1]) % mod;
        }

        // Step 4: Build result
        vector<vector<int>> result(n, vector<int>(m));

        for(int i = 0; i < size; i++) {
            int val = (prefix[i] * suffix[i]) % mod;
            result[i / m][i % m] = val;
        }

        return result;
    }
};