# Number Theory 📘

This folder contains key number theory concepts and techniques widely used in competitive programming and algorithmic problem solving.

---

## 📐 GCD – *Greatest Common Divisor*

### 🧾 Definition:
The GCD of two integers `a` and `b` is the largest positive integer that divides both `a` and `b` without leaving a remainder. It is useful for simplifying fractions, working with cycles, and solving congruences.

36: {1,2,3,6,9,12,18,36} Divisors of 36.

24: {1,2,4,6,12,24} Divisors of 24.

### 12 is the latest or rightmost common divisor between both
so gcd(24,36) = 12

---

🧠 Useful Tricks and Properties:
* gcd(a, b) = gcd(b, a) → commutative

* gcd(a, a) = a

* gcd(a, 0) = |a|

* gcd(a, b) * lcm(a, b) = |a * b|

* If gcd(a, b) == 1, then a and b are coprime

* If a % b == 0, then gcd(a, b) = b

Can be used to reduce fractions:
* int num = a / gcd(a, b);
* int den = b / gcd(a, b);
---

### 🧠 Additional GCD Tricks and Properties

#### 🔁 Basic properties
- `gcd(0, 0) = 0`
- `gcd(a, b) = gcd(|a|, |b|)` → sign does not matter
- `gcd(a, b, c) = gcd(gcd(a, b), c)` → can be extended to any number of integers
- If `gcd(a, b) = 1`, then `a` and `b` are **coprime**

---

#### 🧮 Operations and transformations
- `gcd(a, b) * lcm(a, b) = |a * b|`
- `gcd(k*a, k*b) = k * gcd(a, b)` for any `k ∈ ℕ`
- If `a divides b` (`a | b`), then `gcd(a, b) = a`
- `gcd(a + b, a - b)` can help simplify or eliminate common unknowns

---

#### 📏 Numeric observations
- `gcd(a, a + 1) = 1` → consecutive integers are always coprime
- If `a` is odd: `gcd(a, a + 2) = 1`  ✅ *(your trick!)*
- `gcd(n, n + k)` > 1 only if `k` shares a common factor with `n`

Example:
```cpp
gcd(10, 14) = gcd(10, 4) = 2
gcd(10, 13) = gcd(10, 3) = 1
```
---

📌 Common Applications:
* Fraction simplification

* LCM (Least Common Multiple) computation

* Periodicity in problems

* Bezouts identity and Diophantine equations

* Working with common multiples

* Solving modulo/congruence problems

---

## 🔢 Divisibility

### 🧾 Definition:
An integer `a` is divisible by `b` if there exists an integer `k` such that `a = b * k`.  
We write it as: `b | a`.  
If not divisible, we write: `b ∤ a`.

---

### 🧠 Properties and Tricks

#### 🔁 Basic Properties

- If `a | b` and `b | c`, then `a | c` (transitive)
- If `a | b` and `a | c`, then `a | (b ± c)`
- If `a | b`, then `a | (b * k)` for any integer `k`
- `a | b` ⟺ `b % a == 0`
- If `a | b` and `a | c`, then `a | gcd(b, c)`

---

#### 🔢 Useful Tricks

- **Sum of digits rule**:
  - If the sum of digits of `n` is divisible by `3`, then `n` is divisible by `3`
  - Same for `9`
- **Alternating digits rule**:
  - If alternating sum of digits is divisible by `11`, then the number is divisible by `11`
  - Example: `n = 918273` → `9 - 1 + 8 - 2 + 7 - 3 = 18`, and `18 % 11 = 7` → Not divisible

- **Divisibility by 2** → last digit is even  
- **Divisibility by 4** → last 2 digits divisible by 4  
- **Divisibility by 8** → last 3 digits divisible by 8  
- **Divisibility by 5** → last digit is 0 or 5  
- **Divisibility by 10** → last digit is 0

---

#### 🔗 Advanced Observations

- If `a | b` and `b % a == 0`, then `b = k * a`
- If `a | (b * c)` and `gcd(a, b) = 1`, then `a | c`  
  → Known as **Euclid’s Lemma**
- If `a | b` and `a | c`, then `a | (bx + cy)` for any integers `x, y`
- If `a % b = r`, then `a = q * b + r` → **division algorithm**

---

### 📌 Applications

- Checking constraints in modular arithmetic problems
- Finding common multiples or factors
- Creating optimization logic based on divisibility
- Reducing the search space for brute-force solutions
- Grouping items into equal sets, tiling problems
- Logic puzzles involving calendars, cycles, and remainders

---

## 🔷 Prime Numbers and the Sieve of Eratosthenes

### 🧾 Definition
A **prime number** is an integer greater than 1 that has no positive divisors other than 1 and itself.  
All other integers > 1 that are not prime are called **composite numbers**.

---

### 🔍 How to check if a number is prime

#### 1. Trial Division
Check divisibility from 2 to √n.  
If n is divisible by any number in this range → it is not prime.

```cpp
bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}
```

#### 2. Optimized Trial Division
Check 2, then only odd numbers from 3 to √n.  
Skips even numbers to speed up.

---

### 🔥 Sieve of Eratosthenes

#### 🧠 Idea
Mark all non-primes in a boolean array by iterating multiples of each prime starting from 2.

```cpp
int N = 1e6;
vector<bool> is_prime(N + 1, true);
is_prime[0] = is_prime[1] = false;

for (int i = 2; i * i <= N; i++) {
    if (is_prime[i]) {
        for (int j = i * i; j <= N; j += i)
            is_prime[j] = false;
    }
}
```

- `is_prime[x] == true` ⟺ `x` is prime  
- Time complexity: **O(N log log N)**  
- Space complexity: **O(N)**

---

### 🧠 Prime Number Properties and Tricks

- 2 is the only even prime
- Every prime > 2 is odd
- If `n` is not divisible by any prime ≤ √n, then `n` is prime
- Any even number ≥ 4 can be written as the sum of two primes → **Goldbach conjecture**
- The number of primes ≤ n is approximately `n / log(n)`
- The difference between consecutive primes can be arbitrarily large
- All primes > 3 are of the form `6k ± 1`
- `lcm(a, b) = (a * b) / gcd(a, b)` → often used when both numbers are prime

---

### 📌 Applications

- Cryptography (e.g., RSA encryption)
- Factorization-based problems
- Finding coprime pairs
- Modular inverses and arithmetic
- Preprocessing for number theory problems
- Prime-counting and generating primes fast
- Problems involving divisors, LCM, or GCD

---

## 🧩 Prime Factorization and SPF (Smallest Prime Factor)

### 🧾 Definition
**Prime Factorization** is the process of expressing a number as the product of its prime factors.  
For example:  
`60 = 2^2 * 3 * 5`

The **Smallest Prime Factor (SPF)** of a number `n` is the smallest prime number that divides `n`.

---

### 🔍 Trial Division Method (Naive Factorization)

Check divisibility from 2 to √n, and divide as many times as possible:

```cpp
vector<int> prime_factors(int n) {
    vector<int> factors;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }
    if (n > 1) factors.push_back(n); // n is prime
    return factors;
}
```

- Time complexity: **O(√n)**  
- Works fine for small values (up to 10^6)

---

### 🚀 SPF Method (Efficient Factorization with Sieve)

Use a sieve to precompute the smallest prime factor for every number up to N.

```cpp
int N = 1e6;
vector<int> spf(N + 1);

void buildSPF() {
    for (int i = 0; i <= N; i++) spf[i] = i;
    for (int i = 2; i * i <= N; i++) {
        if (spf[i] == i) { // i is prime
            for (int j = i * i; j <= N; j += i)
                if (spf[j] == j) spf[j] = i;
        }
    }
}
```

Once built, you can factorize `x` in **O(log x)** time:

```cpp
vector<int> get_factors(int x) {
    vector<int> res;
    while (x != 1) {
        res.push_back(spf[x]);
        x /= spf[x];
    }
    return res;
}
```

---

### 🧠 Tricks and Observations

- You can count the number of distinct prime factors using `set`
- You can count total number of divisors using exponents:  
  If `n = p1^a1 * p2^a2 * ... * pk^ak`  
  Then `num_divisors(n) = (a1+1)(a2+1)...(ak+1)`
- You can find the largest prime factor by using `spf[n]` until the last

---

### 📌 Applications

- Efficient factorization for many queries
- Precomputing factorization data for range problems
- Calculating number of divisors
- Solving problems with multiplicative functions (like Euler’s totient)
- GCD / LCM through factor comparison




