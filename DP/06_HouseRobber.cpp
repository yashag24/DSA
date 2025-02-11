#include <bits/stdc++.h>
using namespace std;
////////////////////////////Recursion///////////////
int solve(vector<int> &viH, int ind)
{
    if (ind == 0)
        return viH[0];
    if (ind < 0)
        return 0;

    int notpick = 0 + solve(viH, ind - 1);
    int pick = viH[ind] + solve(viH, ind - 2);
    return max(pick, notpick);
}
/////////////////////memoization//////////////////
int solve(vector<int> &viH, int ind, vector<int> &dp)
{
    if (dp[ind] != -1)
        return dp[ind];
    if (ind == 0)
        return viH[0];
    if (ind < 0)
        return 0;

    int pick = viH[ind] + solve(viH, ind - 2, dp);
    int notpick = 0 + solve(viH, ind - 1, dp);

    return max(pick, notpick);
}
///////////////////////////Tabulation///////////////
#include <bits/stdc++.h>
int solve(vector<int> &viH) {
  int n = viH.size();
  vector<int> dp(n, -1);
  dp[0] = viH[0];
  for (int i = 1; i < n; i++) {
      
    int notpick = 0 + dp[i - 1];

    int pick = viH[i];
    if (i > 1)
      pick += dp[i - 2];

    dp[i] = max(pick, notpick);
  }
  return dp[n - 1];
}

long long int houseRobber(vector<int> &valueInHouse) {
  int n = valueInHouse.size();

  if (n == 1)
    return valueInHouse[0];

  vector<int> temp1;
  vector<int> temp2;
  for (int i = 0; i < n; i++) {
    if (i != 0)
      temp1.push_back(valueInHouse[i]);
    if (i != n - 1)
      temp2.push_back(valueInHouse[i]);
  }

  int first = solve(temp2);

  int last = solve(temp1);

  return max(first, last);
}///////////////////////////////////////////optimal//////////////////////
class Solution {
public:
    int solve(vector<int>& viH) {

        int n = viH.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return viH[0];
        int prev = viH[0];
        int prev2 = 0;
        int curr = 0;

        for (int i = 1; i < n; i++) {
            int notpick = prev;
            int pick = viH[i] + prev2;
            curr = max(pick, notpick);

            // Update prev and prev2 for the next iteration
            prev2 = prev;
            prev = curr;
        }

        return curr; // Return the maximum value
    }
    int rob(vector<int>& valueInHouse) {
        int n = valueInHouse.size();

        if (n == 1)
            return valueInHouse[0];

        vector<int> temp1;
        vector<int> temp2;
        for (int i = 0; i < n; i++) {
            if (i != 0)
                temp1.push_back(valueInHouse[i]);
            if (i != n - 1)
                temp2.push_back(valueInHouse[i]);
        }

        int first = solve(temp1);

        int last = solve(temp2);

        return max(first, last);
    }
};
//////////////////////////////////////////////////////////////////

long long int houseRobber(vector<int> &valueInHouse)
{
    int n = valueInHouse.size();
    int first = INT_MIN;
    if (n > 1)
    {
        first = solve(valueInHouse, n - 2);
        valueInHouse[0] = 0;
    }

    int last = solve(valueInHouse, n - 1);

    return max(first, last);
}