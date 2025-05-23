#include<bits/stdc++.h>

using namespace std;

/*
Sieve of Eratosthenes
*/ 
signed main() {
    int N = 20;
    vector<bool> is_prime(N + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i * i <= N; i++) {
        if (is_prime[i]) {
            cout << i << endl;
            for (int j = i * i; j <= N; j += i)
                is_prime[j] = false;
        }
    }
    long long cnt =0;
    for (int i = 1;  i <= N; i++) {
        if (is_prime[i]) {
          cout << i << endl;
          cnt++;
        }
    }

    cout <<cnt<< endl;
    return 0;
}


