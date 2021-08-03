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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root)
    {
        vector<vector<int>> res;
        vector<int> temp;
        stack<TreeNode*> firsts, seconds;
        if(root == nullptr)
        {
            return res;
        }
        
        firsts.push(root);
        while(! (firsts.empty() && seconds.empty()) )
        {
            while(!firsts.empty())
            {
                TreeNode* t = firsts.top();
                firsts.pop();
                temp.push_back(t->val);
                if(t->left != nullptr)
                {
                    seconds.push(t->left);
                }
                if(t->right != nullptr)
                {
                    seconds.push(t->right);
                }
            }
            
            if(!temp.empty())
            {
                res.push_back(temp);
                temp.clear();
            }
            
            while(!seconds.empty())
            {
                TreeNode* t = seconds.top();
                seconds.pop();
                temp.push_back(t->val);
                if(t->right != nullptr)
                {
                    firsts.push(t->right);
                }
                if(t->left != nullptr)
                {
                    firsts.push(t->left);
                }
            }
            
            if(!temp.empty())
            {
                res.push_back(temp);
                temp.clear();
            }
            
        }
        return res;
        
    }
};