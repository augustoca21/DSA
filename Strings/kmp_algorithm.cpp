#include <bits/stdc++.h>
using namespace std;

vector<int> prefix_function(string s) {
    int n = s.size();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) j = pi[j - 1];
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}

int main() {
    string s = "ababcababc";
    vector<int> pi = prefix_function(s);

    cout << "Prefix function: ";
    for (int x : pi) cout << x << " ";
    cout << endl;
    return 0;
}
