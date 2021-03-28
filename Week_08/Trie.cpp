class TrieNode {
public:
    TrieNode() {
        links.reserve(num);
        for(int i=0; i<num; i++) {
            links[i] = NULL;
        }
    }

    bool containsKey(char ch) {
        return links[ch-'a'] != NULL;
    }

    TrieNode* get(char ch) {
        return links[ch-'a'];
    }

    void put(char ch, TrieNode* node) {
        links[ch-'a'] = node;
    }

    void setEnd() {
        is_end = true;
    }

    bool isEnd() {
        return is_end;
    }

private:
    vector<TrieNode*> links;
    int num = 26;
    bool is_end = false;
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *node = root;
        int length = word.size();
        for(int i=0; i<length; i++) {
            if(!node->containsKey(word[i])) {
                TrieNode *_node = new TrieNode();
                node->put(word[i], _node);
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *node = root;
        int length = word.size();
        for(int i=0; i<length; i++) {
            if(node->containsKey(word[i])) {
                node = node->get(word[i]);
            }
            else {
                return false;
            }
        }
        return (node && node->isEnd());
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *node = root;
        int length = prefix.size();
        for(int i=0; i<length; i++) {
            if(node->containsKey(prefix[i])) {
                node = node->get(prefix[i]);
            }
            else {
                return false;
            }
        }
        return true;
    }
private:
    TrieNode *root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */