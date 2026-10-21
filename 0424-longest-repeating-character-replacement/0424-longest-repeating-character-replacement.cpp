class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        if(n==0||k<0){
            return 0;
        }
        vector<int> f(26,0);

        int l=0;
        int maxf=0;
        int maxl=0;

        for(int r=0;r<n;r++){
            int i=s[r]-'A';
            f[i]++;

            maxf=max(maxf,f[i]);
            int currentL=r-l+1;

            if(currentL-maxf>k){
                f[s[l]-'A']--;
                l++;
            }

            currentL=r-l+1;
            maxl=max(maxl,currentL);
        }
        return maxl;
    }
};