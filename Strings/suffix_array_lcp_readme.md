# 🧵 Suffix Array and LCP (Longest Common Prefix)

This document explains two powerful string algorithms used in competitive programming: the **Suffix Array** and the **LCP Array**.

---

## 📚 Suffix Array

A **suffix array** is an array of integers giving the starting positions of suffixes of a string in lexicographically sorted order.

### Example:
For string `s = "banana"`:

Suffixes:
```
0: banana  
1: anana  
2: nana  
3: ana  
4: na  
5: a  
```

Sorted:
```
5: a  
3: ana  
1: anana  
0: banana  
4: na  
2: nana  
```

Suffix Array: `[5, 3, 1, 0, 4, 2]`

---

### 🧠 Construction in O(n log n)

```cpp
vector<int> build_suffix_array(string s) {
    s += '$';
    int n = s.size();
    vector<int> sa(n), c(n);

    // k = 0
    vector<pair<char, int>> a(n);
    for (int i = 0; i < n; i++) a[i] = {s[i], i};
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) sa[i] = a[i].second;
    c[sa[0]] = 0;
    for (int i = 1; i < n; i++) {
        c[sa[i]] = c[sa[i - 1]] + (a[i].first != a[i - 1].first);
    }

    int k = 0;
    vector<int> cnt(n), sa_new(n), c_new(n);
    while ((1 << k) < n) {
        for (int i = 0; i < n; i++)
            sa[i] = (sa[i] - (1 << k) + n) % n;

        fill(cnt.begin(), cnt.end(), 0);
        for (int x : c) cnt[x]++;
        for (int i = 1; i < n; i++) cnt[i] += cnt[i - 1];
        for (int i = n - 1; i >= 0; i--) sa_new[--cnt[c[sa[i]]]] = sa[i];
        sa = sa_new;

        c_new[sa[0]] = 0;
        for (int i = 1; i < n; i++) {
            pair<int, int> prev = {c[sa[i - 1]], c[(sa[i - 1] + (1 << k)) % n]};
            pair<int, int> now = {c[sa[i]], c[(sa[i] + (1 << k)) % n]};
            c_new[sa[i]] = c_new[sa[i - 1]] + (now != prev);
        }
        c = c_new;
        k++;
    }
    return sa;
}
```

---

## 📏 LCP Array (Kasai's Algorithm)

LCP[i] = length of longest common prefix between `s[sa[i]]` and `s[sa[i-1]]`

### Code (O(n)):
```cpp
vector<int> build_lcp_array(const string &s, const vector<int> &sa) {
    int n = s.size(), k = 0;
    vector<int> rank(n, 0), lcp(n - 1, 0);
    for (int i = 0; i < n; i++) rank[sa[i]] = i;
    for (int i = 0; i < n; i++) {
        if (rank[i] == n - 1) {
            k = 0;
            continue;
        }
        int j = sa[rank[i] + 1];
        while (i + k < n && j + k < n && s[i + k] == s[j + k]) k++;
        lcp[rank[i]] = k;
        if (k) k--;
    }
    return lcp;
}
```

---

## 📌 Applications

- Counting distinct substrings:  
  `total = n(n + 1)/2 − sum(lcp)`
- Finding longest repeated substrings
- String compression and suffix queries
- Pattern searching and binary search over suffixes
- Plagiarism detection, bioinformatics

---

✏️ *Next topic suggestion: Palindrome Tree (Eertree)*
