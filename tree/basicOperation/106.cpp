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
    
    
    TreeNode *construct(vector<int> &inorder, vector<int> &postorder, 
        int is, int ie, int ps, int pe) {
            TreeNode * root = new TreeNode(postorder[pe]);
            if (ps == pe) return root;
            int i;
            for (i = 0; i < ie; i++) {
                if (inorder[i] == root->val) break;
            }
            if (i-1 >= is) {
                root->left = construct(inorder, postorder, is, i-1, ps, ps+i-1-is);
            }
            if (i+1 <= ie) {
                root->right = construct(inorder, postorder, i+1, ie, ps+i-is, pe-1);
            }
            return root;            
        }

    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.empty() || postorder.empty() || 
            inorder.size() != postorder.size()) return NULL;
        return construct(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1);
    }
};
