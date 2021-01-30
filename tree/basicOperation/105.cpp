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
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty() || inorder.empty() || preorder.size() != inorder.size()) return NULL;
        return build(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
private:
    TreeNode* build(vector<int>& preorder, int ps, int pe, vector<int>& inorder, int is, int ie){
        TreeNode *root = new TreeNode(preorder[ps]);
        if(ps == pe) return root;
        
        int i;
        for(i = 0; i<ie; i++){
            if(inorder[i] == root->val) break;
        }
        
        if(i - 1 >= is) root -> left =  build(preorder, ps + 1, ps + (i-is), inorder, is, i - 1);
        if(i + 1 <= ie) root -> right = build(preorder, ps + (i-is) + 1, pe, inorder, i + 1, ie);
        
        return root;
    }
};
