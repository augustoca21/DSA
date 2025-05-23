#include <bits/stdc++.h>
using namespace std;

struct Node {
    int len, suff_link;
    map<char, int> next;
    int occ = 0;
    int id;
    Node(int _len, int _link, int _id) : len(_len), suff_link(_link), id(_id) {}
};

struct Eertree {
    vector<Node> tree;
    string s;
    int suff;
    int node_count = 2;

    Eertree() {
        tree.emplace_back(-1, 0, 0); // imaginary node
        tree.emplace_back(0, 0, 1);  // empty string node
        suff = 1;
    }

    void add_char(char c) {
        s += c;
        int pos = s.size() - 1;
        int curr = suff;

        while (true) {
            int curr_len = tree[curr].len;
            int i = pos - 1 - curr_len;
            if (i >= 0 && s[i] == c) break;
            curr = tree[curr].suff_link;
        }

        if (tree[curr].next.count(c)) {
            suff = tree[curr].next[c];
            tree[suff].occ++;
            return;
        }

        suff = tree.size();
        tree.emplace_back(tree[curr].len + 2, 0, node_count++);
        tree[curr].next[c] = suff;

        if (tree[suff].len == 1) {
            tree[suff].suff_link = 1;
        } else {
            int link = tree[curr].suff_link;
            while (true) {
                int link_len = tree[link].len;
                int i = pos - 1 - link_len;
                if (i >= 0 && s[i] == c) break;
                link = tree[link].suff_link;
            }
            tree[suff].suff_link = tree[link].next[c];
        }

        tree[suff].occ = 1;

        int start = pos - tree[suff].len + 1;
        cout << "Created palindrome: \"" << s.substr(start, tree[suff].len)
            << "\" (len=" << tree[suff].len
            << ", id=" << tree[suff].id
            << ", suff_link id=" << tree[tree[suff].suff_link].id << ")" << endl;
    }

    void build(const string &input) {
        for (char c : input) add_char(c);
    }
};

int main() {
    string input = "aaa";
    Eertree eertree;
    cout << "Building Eertree for: " << input << "\n\n";
    eertree.build(input);
    int maximum = eertree.tree[0].len;
    for (int i=0; i< eertree.tree.size(); i++) {
        maximum = max(maximum, eertree.tree[i].len);
    }

    cout <<"Len of maximum palindromic substring: " <<maximum<< endl;
    return 0;
}
