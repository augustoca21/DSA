# 🔤 String Algorithms

This document summarizes important string algorithms and techniques used in competitive programming and algorithmic problems.

---

## 🔍 Basic String Operations

- **Concatenation:** `s + t`
- **Substring:** `s.substr(start, length)`
- **Reverse:** `reverse(s.begin(), s.end())`
- **Find substring:** `s.find("abc")`
- **Compare strings:** `s1 == s2`
- **Lexicographical comparison:** `s1 < s2`

---

## 🧵 Pattern Matching Algorithms

### Naive Search
Check every substring of length `m` in `text` of length `n`  
- Time complexity: **O(n * m)**

---

### KMP Algorithm (Knuth-Morris-Pratt)

- Preprocess the pattern to build a **prefix function**
- Efficient pattern matching in linear time

```cpp
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
```

- Time complexity: **O(n + m)**

---

### Rabin-Karp (Rolling Hash)

- Hash each substring and compare using modular arithmetic
- Good for multiple pattern matching
- Risk of hash collisions

```cpp
const int p = 31, m = 1e9 + 9;
vector<long long> powers, hashes;

void compute_hashes(const string &s) {
    int n = s.size();
    powers.resize(n); hashes.resize(n);
    powers[0] = 1;
    hashes[0] = s[0] - 'a' + 1;
    for (int i = 1; i < n; i++) {
        powers[i] = (powers[i - 1] * p) % m;
        hashes[i] = (hashes[i - 1] * p + (s[i] - 'a' + 1)) % m;
    }
}
```

---

## 🧠 Advanced Techniques

### Z-Algorithm
- Computes Z[i]: length of longest substring starting at i which is also prefix of the string
- Useful for pattern matching, string periodicity

```cpp
vector<int> z_function(string s) {
    int n = s.length();
    vector<int> z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i <= r) z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
        if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
    }
    return z;
}
```

---

### Manacher’s Algorithm
- Finds longest palindromic substring in O(n)
- Works with virtual separators like `#` to handle odd/even centers

---

### Trie (Prefix Tree)
- Tree data structure for storing sets of strings
- Fast lookup and insert in O(L) time where L is string length

---

## 📌 Applications

- Text searching
- DNA matching, substring analysis
- Autocomplete engines
- Detecting periodicity and repetitions
- String hashing and comparing large texts

---

✏️ *Next topic suggestion: Suffix Arrays and LCP (Longest Common Prefix).*
