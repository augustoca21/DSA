/*🎯 Problema: Subset Sum
🔷 Enunciado:
Dado un arreglo de enteros nums[] y un número objetivo 
target, responde si existe un subconjunto de elementos 
cuya suma sea exactamente igual a target.

📌 Puedes usar cada número una sola vez 
(como en 0/1 Knapsack).
*/

#include <iostream>
#include <vector>
using namespace std;

bool subsetSum(vector<int>& nums, int target, vector<int>& subset) {
    int n = nums.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

    // Base cases
    for (int i = 0; i <= n; ++i)
        dp[i][0] = true;

    // DP table fill
    for (int i = 1; i <= n; ++i) {
        for (int sum = 1; sum <= target; ++sum) {
            if (nums[i - 1] <= sum)
                dp[i][sum] = dp[i - 1][sum] || dp[i - 1][sum - nums[i - 1]];
            else
                dp[i][sum] = dp[i - 1][sum];
        }
    }

    // No solution
    if (!dp[n][target])
        return false;

    // Reconstruct subset
    int i = n, sum = target;
    while (i > 0 && sum > 0) {
        if (dp[i][sum] && !dp[i - 1][sum]) {
            subset.push_back(nums[i - 1]);
            sum -= nums[i - 1];
        }
        i--;
    }

    return true;
}

int main() {
    vector<int> nums = {3, 34, 4, 12, 5, 2};
    int target = 9;
    vector<int> subset;

    if (subsetSum(nums, target, subset)) {
        cout << "Sí, se puede formar el subconjunto: ";
        for (int x : subset) cout << x << " ";
        cout << endl;
    } else {
        cout << "No se puede formar el subconjunto." << endl;
    }

    return 0;
}
