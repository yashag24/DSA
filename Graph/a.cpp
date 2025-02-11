#include <bits/stdc++.h>
using namespace std;

// Function to compute LIS length
int computeLIS(vector<int>& arr) {
    vector<int> lis;
    for (int num : arr) {
        auto it = lower_bound(lis.begin(), lis.end(), num);
        if (it == lis.end()) {
            lis.push_back(num);
        } else {
            *it = num;
        }
    }
    return lis.size();
}

int longestReversibleLIS(vector<int>& arr) {
    int n = arr.size();
    if (n == 1) return 1;

    vector<int> LIS_left(n), LIS_right(n);

    // Compute LIS from the left
    vector<int> lis;
    for (int i = 0; i < n; i++) {
        auto it = lower_bound(lis.begin(), lis.end(), arr[i]);
        if (it == lis.end()) lis.push_back(arr[i]);
        else *it = arr[i];
        LIS_left[i] = lis.size();
    }

    // Compute LIS from the right
    lis.clear();
    for (int i = n - 1; i >= 0; i--) {
        auto it = lower_bound(lis.begin(), lis.end(), arr[i]);
        if (it == lis.end()) lis.push_back(arr[i]);
        else *it = arr[i];
        LIS_right[i] = lis.size();
    }

    // Try reversing every subarray and calculate the LIS
    int maxLIS = LIS_left[n - 1]; // Without reversing any subsequence
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            // Reverse the subarray [i...j]
            vector<int> reversed = arr;
            reverse(reversed.begin() + i, reversed.begin() + j + 1);

            // Merge LIS_left, reversed part, and LIS_right
            vector<int> merged;
            for (int k = 0; k <= i - 1; k++) merged.push_back(arr[k]);
            for (int k = j; k >= i; k--) merged.push_back(arr[k]);
            for (int k = j + 1; k < n; k++) merged.push_back(arr[k]);

            maxLIS = max(maxLIS, computeLIS(merged));
        }
    }

    return maxLIS;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << longestReversibleLIS(arr) << endl;
    return 0;
}
