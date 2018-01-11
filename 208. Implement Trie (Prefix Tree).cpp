// https://leetcode.com/problems/implement-trie-prefix-tree/description/

class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() {
        count = 0;
        for(int i=0; i<26; i++)
            neighbor[i] = nullptr;
    }
    TrieNode* neighbor[26]; // 下一级的 26 个节点，如果非空，则代表后续有对应的字符
    int count;             // 以当前节点为终点的字符串的个数
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* prev = root;
        for (size_t i = 0; i < word.size(); ++i) {
            if (!prev->neighbor[word[i] - 'a'])
                prev->neighbor[word[i] - 'a'] = new TrieNode();
            prev = prev->neighbor[word[i] - 'a'];
        }
        ++prev->count;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        return searchHelper(word, true);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return searchHelper(prefix, false);
    }
    
private:
    bool searchHelper(string word, bool whole_match) {
        TrieNode* prev = root;
        for (size_t i = 0; i < word.size(); ++i) {
            if (!prev->neighbor[word[i] - 'a'])
                return false;
            prev = prev->neighbor[word[i] - 'a'];
        }
        return whole_match ? (prev->count > 0) : true;
    }
    
private:
    TrieNode* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */