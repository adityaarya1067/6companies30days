class TrieNode {
public:
    TrieNode* children[26];
    bool isTerminal;

    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        isTerminal = false;
    }
};

class Solution {
public:
    void insert(TrieNode* root, const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (node->children[index] == nullptr) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->isTerminal = true;
    }

    void searchSuggestions(TrieNode* node, string prefix, vector<string>& suggestions) {
        if (node == nullptr) return;
        if (node->isTerminal) {
            suggestions.push_back(prefix);
        }
        for (int i = 0; i < 26; i++) {
            if (node->children[i] != nullptr) {
                searchSuggestions(node->children[i], prefix + char('a' + i), suggestions);
            }
        }
    }

    vector<vector<string>> displayContacts(int n, string contact[], string s) {
        
        TrieNode* root = new TrieNode();
        for (int i = 0; i < n; i++) {
            insert(root, contact[i]);
        }

        vector<vector<string>> result;
        TrieNode* node = root;
        string prefix = "";

        for (char ch : s) {
            int index = ch - 'a';
            prefix += ch;

            if (node == nullptr || node->children[index] == nullptr) {
                result.push_back({"0"});
                node = nullptr; 
            } else {
                node = node->children[index];
                vector<string> suggestions;
                searchSuggestions(node, prefix, suggestions);
                sort(suggestions.begin(), suggestions.end());
                result.push_back(suggestions);
            }
        }

        return result;
    }
};