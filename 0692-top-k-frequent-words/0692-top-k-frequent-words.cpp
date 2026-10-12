class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;

        for (string &word : words) {
            mp[word]++;
        }
        vector<string> ans;
        for (auto &p : mp) {
            ans.push_back(p.first);
        }
        sort(ans.begin(), ans.end(), [&](string &a, string &b) {
            if (mp[a] != mp[b]) {
                return mp[a] > mp[b];
            }
            return a < b;
        });

        ans.resize(k);

        return ans;
    }
};