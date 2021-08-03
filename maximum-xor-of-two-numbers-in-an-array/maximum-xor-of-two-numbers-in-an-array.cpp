class TrieNode {
public:
    int element; // number of element go through this node
    TrieNode* children[2];
    
    TrieNode()
    {
        element = 0;
        memset(children, 0 ,sizeof(children));
        children[0] = nullptr;
        children[1] = nullptr;
    }
    
};
class Trie {
public:
    TrieNode* root;
    Trie()
    {
        root = new TrieNode();
    }
    ~Trie()
    {
        clear(root);
    }
    void clear(TrieNode* node)
    {
        if(node->children[0] != nullptr)
        {
            clear(node->children[0]);
        }
        if(node->children[1] != nullptr)
        {
            clear(node->children[1]);
        }
        delete node;
    }
    void insert(int num)
    {
        TrieNode* node = root;
        for(int i = 31; i>=0; --i)
        {
            int j = (num >> i) & 1;
            if(node->children[j] == nullptr)
            {
                node->children[j] = new TrieNode();
            }
            node = node->children[j];
            node->element += 1;
        }
    }
    
    int findMax(int num)
    {
        TrieNode* node = root;
        int ans = 0;
        for(int i = 31; i>=0; --i)
        {
            int j = (num >> i) & 1;
            if(node->children[1-j] != nullptr)
            {
                node = node->children[1-j];
                ans |= (1<<i);
            }
            else
            {
                node = node->children[j];
            }
        }
        return ans;
    }
    
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums)
    {
        Trie tree;
        for(int i = 0; i<nums.size(); ++i)
        {
            tree.insert(nums[i]);
        }
        int answer = 0;
        for(int i = 0; i<nums.size(); ++i)
        {
           answer = max(answer, tree.findMax(nums[i]));
        }
        return answer;
    }
};