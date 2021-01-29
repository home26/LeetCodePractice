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
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        if(pre.empty() || post.empty() || pre.size() != post.size()) return NULL;
        
        return build(pre, 0, pre.size()-1, post, 0, post.size()-1);
    }
private:
    TreeNode* build(vector<int>& pre, int pres, int pree, vector<int>& post, int posts, int poste){
        TreeNode *root = new TreeNode(pre[pres]);
        if(pres == pree) return root;
        
        int length = 1;
        while(post[posts + length-1] != pre[pres+1]){
            ++length;
        }
        
        if(pres + 1 <= pres + length && posts<=posts + length - 1)        
        root -> left = build(pre, pres + 1, pres + length, post, posts, posts + length - 1);
        if(pres + length + 1 <= pree && posts + length<=poste-1)
        root -> right = build(pre, pres + length + 1, pree, post, posts + length, poste-1);
        
        return root;
    }
};
