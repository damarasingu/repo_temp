class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }

        int c=1;
        int m=1;
        sort(nums.begin(),nums.end());

        for(int i=1;i<nums.size();i++){
            if(nums[i]-nums[i-1]==1){
                c++;
            }
            else if(nums[i]==nums[i-1]){
                continue;
            }
            else{
                c=1;
            }

            m=max(m,c);
        }

        return m;
    }
};