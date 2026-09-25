class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> a;
        int n=nums.size();
        int c=0;
        unordered_map<int,int> b;
        for(int i=0;i<n;i++){
        b[nums[i]]++;
                }
                for(auto x:b){
                    if(x.second>n/3){
                       a.push_back(x.first);
                    }
                }
                return a;
    }
};