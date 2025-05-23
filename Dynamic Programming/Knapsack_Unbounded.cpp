#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int unboundedKnapsack(int W, vector<int>& wt, vector<int>& val, int n) {
    vector<int> dp(W + 1, 0);  // dp[w] = máximo valor con capacidad w

    for (int w = 0; w <= W; ++w) {
        for (int i = 0; i < n; ++i) {
            if (wt[i] <= w) {
                dp[w] = max(dp[w], val[i] + dp[w - wt[i]]);
            }
        }
    }

    return dp[W];
}

int main() {
    vector<int> wt = {2, 3, 4};
    vector<int> val = {4, 5, 6};
    int W = 5;

    int result = unboundedKnapsack(W, wt, val, wt.size());
    cout << "Máximo valor en mochila (unbounded): " << result << endl;

    return 0;
}