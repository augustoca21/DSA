/*
🧠 Descripción del problema
Dado un conjunto de denominaciones de monedas 
y un monto total amount, encuentra el número máximo 
de monedas que se pueden usar para alcanzar ese monto. 
Si no es posible, devuelve -1.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int maxCoins(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, INT_MIN);  // INT_MIN porque buscamos máximo
    dp[0] = 0;  // 0 monedas para alcanzar 0

    for (int i = 1; i <= amount; ++i) {
        for (int coin : coins) {
            if (i >= coin && dp[i - coin] != INT_MIN) {
                dp[i] = max(dp[i], dp[i - coin] + 1);
            }
        }
    }

    return (dp[amount] == INT_MIN) ? -1 : dp[amount];
}

int minCoins(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, INT_MAX);  // INT_MAX porque buscamos minimo
    dp[0] = 0;  // 0 monedas para alcanzar 0

    for (int i = 1; i <= amount; ++i) {
        for (int coin : coins) {
            if (i >= coin && dp[i - coin] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    return (dp[amount] == INT_MAX) ? -1 : dp[amount];
}

int main() {
    vector<int> coins = {2, 3, 4};  // puedes cambiar los valores
    int amount = 7;

    int result = minCoins(coins, amount);
    if (result != -1)
        cout << "Máximo número de monedas para " << amount << " es: " << result << endl;
    else
        cout << "No se puede formar el monto " << amount << " con las monedas dadas." << endl;

    return 0;
}
