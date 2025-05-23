# 📐 Competitive Math Formulas

This file contains frequently used mathematical formulas and identities that are essential in competitive programming and problem-solving.

---

## 🔢 Arithmetic and Series

### Sum of the first n natural numbers
```text
1 + 2 + 3 + ... + n = n(n + 1) / 2
```
- Use: counting total items, triangular numbers

### Sum of squares of first n natural numbers
```text
1^2 + 2^2 + ... + n^2 = n(n + 1)(2n + 1) / 6
```

### Sum of cubes of first n natural numbers
```text
1^3 + 2^3 + ... + n^3 = (n(n + 1) / 2)^2
```
- The cube sum is the square of the sum of first n numbers

---

## 🧮 Factorial and Combinatorics

### Factorial
```text
n! = n × (n−1) × ... × 1
```
- Use: counting total permutations of n items

### Permutations (nPr)
```text
nPr = n! / (n − r)!
```

### Combinations (nCr)
```text
nCr = n! / (r! * (n − r)!)
```

### Binomial Coefficient Identity
```text
nCr = (n−1)Cr + (n−1)C(r−1)
```
- Useful in DP and Pascal's Triangle

---

## 📊 Useful Mathematical Identities

### Triangular number
```text
T(n) = n(n + 1) / 2
```

### Centered square number
```text
C(n) = n^2 + (n+1)^2 = 2n^2 + 2n + 1
```

### Sum of consecutive odd numbers
```text
1 + 3 + 5 + ... + (2n−1) = n^2
```

### Number of handshakes in a group of n people
```text
n(n − 1) / 2
```

---

## 🧠 Number Theory Snippets

### Product of two consecutive integers
```text
n(n + 1) = always even
```

### Difference of squares
```text
a^2 − b^2 = (a − b)(a + b)
```

### Sum of geometric progression (r ≠ 1)
```text
S = a(1 − r^n) / (1 − r)
```

---

## 📌 Applications

- Counting operations
- Total possible pairs (e.g., in graphs, handshakes)
- Combinatorics for arrangement problems
- Series manipulation for sum-related constraints
- Identifying perfect squares / triangular numbers

---

✏️ *Next topic suggestion: Modular Arithmetic and Modular Inverse.*
