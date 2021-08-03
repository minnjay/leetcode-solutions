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
    bool isValidBST(TreeNode* root)
    {
        vector<int> vc;
        inorder(root, vc);
        for(int i = 1; i<vc.size(); ++i)
        {
            if(vc[i]<=vc[i-1])
            {
                return false;
            }
        }
        return true;
        
    }
    
    void inorder(TreeNode* node, vector<int>& vc)
    {
        if(node == nullptr)
        {
            return;
        }
        inorder(node->left, vc);
        vc.push_back(node->val);
        inorder(node->right, vc);
    }
};