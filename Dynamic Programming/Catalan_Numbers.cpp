#include <bits/stdc++.h>

using namespace std;

int catalan_number(int n) {
    if(n==1) return 1;
    long long c1 = 1;
    for (int i=2; i<=n; i++) 
        c1 = ((c1*(4*i-2))/(i+1));
    return c1;
}

signed main () {
    cout << catalan_number(5) << endl;
    return 0;
}