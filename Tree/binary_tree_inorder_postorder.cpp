/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    TreeNode* va(vector<int> &inorder,vector<int> &postorder,int in1,int in2,int &po2){
        if(in1>in2){
            return NULL;
        }
        TreeNode *ans=new TreeNode(postorder[po2--]);
        int x1=in1;
        while(x1<=in2&&inorder[x1]!=postorder[po2+1]){
            x1++;
        }
        ans->right=va(inorder,postorder,x1+1,in2,po2);
        ans->left=va(inorder,postorder,in1,x1-1,po2);

        return ans;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        int m=postorder.size();
        int po2=n-1;
        TreeNode *ans= va(inorder,postorder,0,n-1,po2);
        return ans;
    }
};
