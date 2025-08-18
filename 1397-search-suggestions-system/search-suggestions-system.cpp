class Node {
public:
    int prefix;
    Node* child[26];
    vector<string> endingWords;

    Node() {
        prefix = 0;
        for (int i = 0; i < 26; i++) {
            child[i] = NULL;
        }
    }
};

class SearchSuggestionsSystem {
    Node* root;

    void search(Node* curr, int K, vector<string> &results) {
        if (curr == NULL) {
            return;
        }

        if (results.size() == K) {
            return;
        }

        for (auto word : curr->endingWords) {
            results.push_back(word);
            if (results.size() == K) {
                return;
            }
        }

        for (int i = 0; i < 26; i++) {
            if (curr->child[i] == NULL) {
                continue;
            }

            search(curr->child[i], K, results);
        }
    }

public:
    SearchSuggestionsSystem() {
        root = new Node();
    }

    void insert(string word) {
        auto curr = root;

        for (auto character : word) {
            int value = character - 'a';
            if (curr->child[value] == NULL) {
                curr->child[value] = new Node();
            }
            curr = curr->child[value];
            curr->prefix++;
        }

        curr->endingWords.push_back(word);
    }

    vector<string> suggest(string prefixWord, int K) {
        vector<string> results;

        auto curr = root;
        for (auto character : prefixWord) {
            int value = character - 'a';

            if (curr->child[value] == NULL) {
                return results;
            }

            curr = curr->child[value];
        }

        search(curr, K, results);
        return results;
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        SearchSuggestionsSystem searchSuggestionsSystem;
        for (auto product : products) {
            searchSuggestionsSystem.insert(product);
        }

        vector<vector<string>> suggestedProructs;
        string prefixWord = "";
        for (auto character : searchWord) {
            prefixWord += character;

            auto suggestions = searchSuggestionsSystem.suggest(prefixWord, 3);
            suggestedProructs.push_back(suggestions);
        }
        return suggestedProructs;
    }
};