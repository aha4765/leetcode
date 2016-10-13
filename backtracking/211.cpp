class WordDictionary {
public:

    struct TrieNode {
        TrieNode* child[26];
        bool isLeaf;
        
        bool haschild() {
            for (int i = 0; i < 26; ++i) {
                if (child[i] != nullptr) return true;
            }
            return false;
        }
        
        bool hasleafchild() {
            for (int i = 0; i < 26; ++i) {
                if (child[i] != nullptr) {
                    if (child[i]->isLeaf) return true;
                }
            }
            return false;
        }
        
        TrieNode() {
            for (int i = 0; i < 26; ++i) {
                child[i] = nullptr;
            }
            isLeaf = false;
        }
        TrieNode(bool leaf) 
        : isLeaf(leaf) {
            for (int i = 0; i < 26; ++i) {
                child[i] = nullptr;
            }
        }
    };

    // Adds a word into the data structure.
    void addWord(string word) {
        int len = word.size();
        TrieNode* root = &rootnode;
        for (int i = 0; i < len; ++i) {
            if (root->child[word[i]-'a'] == nullptr) {
                TrieNode* temp = new TrieNode(i == (len-1));
                root->child[word[i]-'a'] = temp;
                root = root->child[word[i]-'a'];
            }
            else {
                root = root->child[word[i]-'a'];
				if (i == (len-1)) root->isLeaf = true;
            }
        }
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        int len = word.size();
        return searchHelp(&rootnode, word, 0);
    }
    
    bool searchHelp(TrieNode* node, string word, int ind) {
        if (node == nullptr) return false;
        
        char val = word[ind];
        if (ind == word.size() - 1) {
            if (val == '.') {
                if (node->hasleafchild()) {
                    return true;
                }
                else {
                    return false;
                }
            }
            else if (node->child[val-'a'] != nullptr) { 
                if (node->child[val-'a']->isLeaf)
                    return true;
            }
            else {
                return false;
            }
        }
        
        if (val == '.') {
            for (int i = 0; i < 26; ++i) {
                if (searchHelp(node->child[i], word, ind+1)) {
                    return true;
                }
            }
            return false;
        }
        else {
            return searchHelp(node->child[val-'a'], word, ind+1);
        }
    }
    
private:
    TrieNode rootnode;
};


// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
