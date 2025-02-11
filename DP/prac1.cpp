#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int getMaxEfficiency(vector<int> &arrivalTime)
{
    // Sorting the array: O(n log n)
    sort(arrivalTime.begin(), arrivalTime.end());

    int maxEfficiency = INT_MIN;
    int n = arrivalTime.size();

    int left = 0;

    // Sliding window approach: O(n)
    for (int right = 0; right < n; ++right)
    {
        int timeActive = arrivalTime[right] - arrivalTime[left];
        int testCases = right - left + 1;
        int efficiency = testCases - timeActive;
        maxEfficiency = max(maxEfficiency, efficiency);

        while (left < right && timeActive > testCases - 1)
        {
            ++left;
            timeActive = arrivalTime[right] - arrivalTime[left];
            testCases = right - left + 1;
            efficiency = testCases - timeActive;
            maxEfficiency = max(maxEfficiency, efficiency);
        }
    }

    return maxEfficiency;
}

int main()
{
    // Example input
    vector<int> arrivalTimes = {8, 10, 12, 5, 6, 5, 7, 6, 10};

    // Calculate maximum efficiency
    int result = getMaxEfficiency(arrivalTimes);

    // Print result
    cout << "Maximum efficiency: " << result << endl;

    return 0;
}
