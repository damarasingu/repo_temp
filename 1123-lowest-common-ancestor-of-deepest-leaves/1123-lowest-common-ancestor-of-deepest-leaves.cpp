
class Solution {
public:
    pair<TreeNode*,int> solve(TreeNode* root){
        if(root==NULL)
            return {NULL,0};

        pair<TreeNode*,int> l=solve(root->left);
        pair<TreeNode*,int> r=solve(root->right);

        if(l.second==r.second)
            return {root,l.second+1};

        if(l.second>r.second)
            return {l.first,l.second+1};

        return {r.first,r.second+1};
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root){
        pair<TreeNode*,int> p=solve(root);
        return p.first;
    }
};
