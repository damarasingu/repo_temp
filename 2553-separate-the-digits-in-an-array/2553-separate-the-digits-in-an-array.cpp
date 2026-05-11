class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> a;

        for(int i=0;i<nums.size();i++){
            stack<int> s;

            for(int x=nums[i];x>0;x/=10){
                s.push(x%10);
            }

            while(!s.empty()){
                a.push_back(s.top());
                s.pop();
            }
        }

        return a;
    }
};