class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.find(needle)==-1){
            return -1;
        }
        else{
return(haystack.find(needle));
        }
    }
};