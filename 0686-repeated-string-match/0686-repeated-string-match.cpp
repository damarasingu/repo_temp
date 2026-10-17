class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string n=a;
        int c=1;

        while(n.size()<b.size()){
            n+=a;
            c++;
        }
        if(n.find(b)!=-1){
            return c;
        }
          n += a;
        c++;

        if (n.find(b) != -1) {
            return c;
        }

        return -1;
    }
};