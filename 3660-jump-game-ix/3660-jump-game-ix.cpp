class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n=nums.size();

        vector<int> pm(n),sm(n);

        pm[0]=nums[0];
        for(int i=1;i<n;i++){
            pm[i]=max(pm[i-1],nums[i]);
        }

        sm[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            sm[i]=min(sm[i+1],nums[i]);
        }

        vector<int> an(n);

        int st=0;
        int cm=nums[0];

        for(int i=0;i<n-1;i++){
            cm=max(cm,nums[i]);

            if(pm[i]<=sm[i+1]){
                for(int j=st;j<=i;j++){
                    an[j]=cm;
                }

                st=i+1;
                cm=nums[st];
            }
        }

        cm=*max_element(nums.begin()+st,nums.end());

        for(int j=st;j<n;j++){
            an[j]=cm;
        }

        return an;
    }
};