// https://leetcode.com/problems/implement-strstr/submissions/
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=haystack.size();
        int m=needle.size();
        if(m==0){
            return 0;
        }
        int i=0;
        while(i<n&&n-i+1>=m){
            if(haystack[i]==needle[0]){
                int j=0;
                int k=i;
                while(k<n&&j<m&&haystack[k]==needle[j]){
                    k++;
                    j++;
                }
                if(j==m){
                    return i;
                }
                i+=1;
            }
            else{
                i++;
            }
        }
        return -1;
    }
};
