class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b){
        return (a[1]-a[0])>(b[1]-b[0]);
    }

    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(),tasks.end(),cmp);

        int a=0;
        int energy=0;

        for(int i=0;i<tasks.size();i++){
            int act=tasks[i][0];
            int minimum=tasks[i][1];

            if(energy<minimum){
                a+=minimum-energy;
                energy=minimum;
            }

            energy-=act;
        }

        return a;
    }
};