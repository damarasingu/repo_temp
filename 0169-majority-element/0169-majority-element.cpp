class Solution {
public:
   int majorityElement(vector<int>& nums) {
        unordered_map<int,int> b;
        int n=nums.size();
        int c=0;
    
        for(int i=0;i<n;i++){
        b[nums[i]]++;
                }
                for(auto x:b){
                    if(x.second>n/2){
                       c=x.first;
                    }
                }
                return c;
    }
};