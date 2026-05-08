class Solution {
public:
    bool isPrime(int x){
        if(x<2)return false;

        for(int i=2;i*i<=x;i++){
            if(x%i==0)return false;
        }

        return true;
    }

    vector<int> fac(int x){
        vector<int> v;

        for(int i=2;i*i<=x;i++){
            if(x%i==0){
                v.push_back(i);

                while(x%i==0){
                    x/=i;
                }
            }
        }

        if(x>1)v.push_back(x);

        return v;
    }

    int minJumps(vector<int>& nums) {
        int n=nums.size();

        unordered_map<int,vector<int>> mp;

        for(int i=0;i<n;i++){
            vector<int> v=fac(nums[i]);

            for(int x:v){
                mp[x].push_back(i);
            }
        }

        queue<int> q;
        vector<int> ds(n,-1);

        q.push(0);
        ds[0]=0;

        unordered_set<int> us;

        while(!q.empty()){
            int i=q.front();
            q.pop();

            if(i==n-1)return ds[i];

            if(i-1>=0&&ds[i-1]==-1){
                ds[i-1]=ds[i]+1;
                q.push(i-1);
            }

            if(i+1<n&&ds[i+1]==-1){
                ds[i+1]=ds[i]+1;
                q.push(i+1);
            }

            int x=nums[i];

            if(isPrime(x)&&!us.count(x)){
                us.insert(x);

                for(int j:mp[x]){
                    if(ds[j]==-1){
                        ds[j]=ds[i]+1;
                        q.push(j);
                    }
                }
            }
        }

        return -1;
    }
};