#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// n = número de objetos, W = capacidad de la mochila
int knapsack(int W, vector<int>& wt, vector<int>& val, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Llenamos la tabla dp
    for (int i = 1; i <= n; ++i) {
        for (int w = 0; w <= W; ++w) {
            if (wt[i - 1] <= w) {
                // Podemos incluir el objeto i-1
                dp[i][w] = max(
                    val[i - 1] + dp[i - 1][w - wt[i - 1]],  // lo tomamos
                    dp[i - 1][w]                            // no lo tomamos
                );
            } else {
                dp[i][w] = dp[i - 1][w];  // no cabe, lo ignoramos
            }
        }
    }

    return dp[n][W];
}

int main() {
    vector<int> wt = {2, 3, 4, 5};       // pesos
    vector<int> val = {3, 4, 5, 6};      // valores
    int W = 5;                           // capacidad máxima

    int result = knapsack(W, wt, val, wt.size());
    cout << "Valor máximo que cabe en la mochila: " << result << endl;

    return 0;
}
