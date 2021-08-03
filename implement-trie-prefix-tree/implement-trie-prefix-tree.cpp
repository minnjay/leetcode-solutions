class TrieNode {
private:
    bool isEnd;
    TrieNode* children[26];
public:
    TrieNode() 
    {
        isEnd = false;
        memset(children, 0, sizeof(children));
        for(int i = 0; i< 26; ++i)
        {
            children[i] = nullptr;
        }
    }
    
    bool containsKey(char ch)
    {
        return (children[ch-'a'] != nullptr);
    }
    TrieNode* get(char ch)
    {
        return children[ch-'a'];
    }
    TrieNode* getIndex(int num)
    {
        return children[num];
    }
    void put(char ch, TrieNode* node)
    {
        children[ch-'a'] = node;
    }
    void setEnd()
    {
        isEnd = true;
    }
    bool isEndString()
    {
        return isEnd;
    }
    
};

class Trie {
private:
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    Trie()
    {
        root = new TrieNode();
    }
    
    ~Trie()
    {
        clear(root);
    }
    
    void clear(TrieNode* root)
    {
        for(int i = 0; i<26; ++i)
        {
            if(root->getIndex(i) != nullptr)
            {
                clear(root->getIndex(i));
            }
        }
        delete root;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word)
    {
        TrieNode * node = root;
        for(int i = 0; i<word.length(); ++i)
        {
            char ch = word[i];
            if(!node->containsKey(ch))
            {
                node->put(ch, new TrieNode());
            }
            node = node->get(ch);
        }
        node->setEnd();
        
    }
    
    TrieNode* searchPrefix(string word)
    {
        TrieNode* node = root;
        for(int i = 0; i<word.length(); ++i)
        {
            char ch = word[i];
            if(node->containsKey(ch) == true)
            {
                node = node->get(ch);
            }
            else
            {
                return nullptr;
            }
        }
        return node; 
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        TrieNode* node = searchPrefix(word);
        if(node != nullptr && node->isEndString())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        TrieNode* node = searchPrefix(prefix);
        if(node != nullptr)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */