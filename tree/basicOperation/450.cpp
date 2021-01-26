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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr) return nullptr;
        if(key < root->val) root -> left = deleteNode(root -> left, key);
        else if(key > root -> val) root -> right = deleteNode(root -> right, key);
        else {
            if(root -> left != nullptr && root -> right != nullptr){
                
                TreeNode* rightMin = root -> right;
                while(rightMin -> left){
                    rightMin = rightMin -> left;
                }
                
                root -> val = rightMin -> val;
                root -> right = deleteNode(root -> right, rightMin -> val);
                
            }else{
                TreeNode* newNode = root -> left == nullptr ? root -> right : root -> left;
                root -> left = root -> right = nullptr;
                delete root;
                return newNode;
            }
        }
        return root;
    }
};
