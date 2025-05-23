#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    TrieNode* children[26] = {nullptr};
    bool isEnd = false;
};

void insert(TrieNode* root, const string& word) {
    TrieNode* node = root;
    for (char c : word) {
        int idx = c - 'a';
        if (!node->children[idx])
            node->children[idx] = new TrieNode();
        node = node->children[idx];
    }
    node->isEnd = true;
}

bool search(TrieNode* root, const string& word) {
    TrieNode* node = root;
    for (char c : word) {
        int idx = c - 'a';
        if (!node->children[idx]) return false;
        node = node->children[idx];
    }
    return node->isEnd;
}

int main() {
    TrieNode* root = new TrieNode();
    insert(root, "hello");
    insert(root, "world");

    cout << "Search 'hello': " << (search(root, "hello") ? "found" : "not found") << endl;
    cout << "Search 'world': " << (search(root, "world") ? "found" : "not found") << endl;
    cout << "Search 'hi': " << (search(root, "hi") ? "found" : "not found") << endl;

    return 0;
}
