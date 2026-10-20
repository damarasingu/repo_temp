
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();

        vector<int> l(k + 1, 0);
        vector<int> r(k + 1, 0);

        for (int i = 1; i <= k; i++) {
            l[i] = l[i - 1] + cardPoints[i - 1];
        }

        for (int i = 1; i <= k; i++) {
            r[i] = r[i - 1] + cardPoints[n - i];
        }

        int ms = 0;

        for (int lc = 0; lc <= k; lc++) {
            int rc = k - lc;
            int cs = l[lc] + r[rc];
            ms = max(ms, cs);
        }

        return ms;
    }
};
