//https://leetcode.com/problems/generate-parentheses/submissions/
class Solution {
    void gen(vector<string> &ans,string x,int pos,int o,int c,int n){
        if(c==n){
            ans.push_back(x);
            return;
        }
        if(o>c){
            x[pos]=')';
            gen(ans,x,pos+1,o,c+1,n);
        }
        if(o<n){
            x[pos]='(';
            gen(ans,x,pos+1,o+1,c,n);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        string x(2*n,'a');
        vector<string> ans;
        gen(ans,x,0,0,0,n);
        return ans;

    }
};
