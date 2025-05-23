#include <bits/stdc++.h>
using namespace std;

const int p = 31;
const int m = 1e9 + 9;

vector<long long> compute_hashes(const string &s) {
    int n = s.size();
    vector<long long> hashes(n), powers(n);
    powers[0] = 1;
    hashes[0] = s[0] - 'a' + 1;
    for (int i = 1; i < n; i++) {
        powers[i] = (powers[i - 1] * p) % m;
        hashes[i] = (hashes[i - 1] * p + (s[i] - 'a' + 1)) % m;
    }
    return hashes;
}

int main() {
    string s = "abcdabc";
    vector<long long> hashes = compute_hashes(s);

    cout << "Hash values: ";
    for (auto h : hashes) cout << h << " ";
    cout << endl;
    return 0;
}
