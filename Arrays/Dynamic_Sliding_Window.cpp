/*🧠 Cuándo usar Sliding Window Dinámico
Cuando la ventana debe cumplir una condición, como:

Suma mínima o máxima.

Número de caracteres únicos.

Frecuencia de elementos.

Longitud mínima de subarreglos con restricciones.*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minSizeSubarraySum(int target, vector<int>& nums) {
    int n = nums.size();
    int left = 0, sum = 0, minLen = INT_MAX;

    for (int right = 0; right < n; ++right) {
        sum += nums[right];

        while (sum >= target) {
            minLen = min(minLen, right - left + 1);
            sum -= nums[left];
            ++left;
        }
    }

    return (minLen == INT_MAX) ? 0 : minLen;
}

int main() {
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    int target = 7;
    cout << "Minimum size subarray sum ≥ " << target << " is: "
         << minSizeSubarraySum(target, nums) << endl;
    return 0;
}
