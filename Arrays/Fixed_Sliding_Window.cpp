#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxSumFixedWindow(vector<int>& nums, int k) {
    int n = nums.size();
    if (n < k) return -1; // No se puede formar una ventana

    int windowSum = 0;
    for (int i = 0; i < k; ++i) {
        windowSum += nums[i];
    }

    int maxSum = windowSum;
    for (int i = k; i < n; ++i) {
        windowSum += nums[i] - nums[i - k];  // Slide the window
        maxSum = max(maxSum, windowSum);
    }

    return maxSum;
}

int main() {
    vector<int> nums = {2, 1, 5, 1, 3, 2};
    int k = 3;
    cout << "Max sum of window size " << k << " is: " << maxSumFixedWindow(nums, k) << endl;
    return 0;
}
