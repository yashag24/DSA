#include <bits/stdc++.h>
using namespace std;
/////////////////////////////////recursive///////////////////////
int solve(int ind, int last, vector<vector<int>> &points) {
  if (ind == 0) {
    int maxi = 0;
    for (int i = 0; i < 3; i++) {
      if (i != last)
        maxi = max(maxi, points[0][i]);
    }
    return maxi;
  }

  int maxif = 0, curr = 0;

  for (int i = 0; i < 3; i++) {
    if (i != last)
      curr = points[ind][i] + solve(ind - 1, i, points);

    maxif = max(maxif, curr);
  }
  return maxif;
}
//////////////////////////memoization////////////////////////////
 int f(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp) {

  if (dp[day][last] != -1)
    return dp[day][last];

  if (day == 0) {
    int maxi = 0;

    for (int i = 0; i <= 2; i++) {
      if (i != last)
        maxi = max(maxi, points[0][i]);
    }

    return dp[day][last] = maxi;
  }

  int maxi = 0;

  for (int i = 0; i <= 2; i++) {
    if (i != last) {

      int activity = points[day][i] + f(day - 1, i, points, dp);
      maxi = max(maxi, activity);
    }
  }

  return dp[day][last] = maxi;
}
/////////////////////////Tabulation////////////////
int f(int n, vector<vector<int>> &points) {
  vector<vector<int>> dp(n, vector<int>(4, -1));

  dp[0][0] = max(points[0][1], points[0][2]);
  dp[0][1] = max(points[0][0], points[0][2]);
  dp[0][2] = max(points[0][0], points[0][1]);

  dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

  int maxi = 0;

  for (int day = 1; day < n; day++) {
    for (int last = 0; last < 4; last++) {

      int maxi = 0;
      for (int task = 0; task < 3; task++) {
        if (task != last) {

          int activity = points[day][task] + dp[day - 1][task];
          maxi = max(maxi, activity);
        }
      }
      dp[day][last] = maxi;
    }
  }

  return max(dp[n - 1][0], max(dp[n - 1][1], dp[n - 1][2]));
}
///////////////////////////////////////////////Space//////////////////////////////////
int f(int n, vector<vector<int>> &points) {
vector<int>prev(4,0);

  prev[0] = max(points[0][1], points[0][2]);
  prev[1] = max(points[0][0], points[0][2]);
  prev[2] = max(points[0][0], points[0][1]);

  prev[3] = max(points[0][0], max(points[0][1], points[0][2]));

  int maxi = 0;

  for (int day = 1; day < n; day++) {
    vector<int>temp(4,0);
    for (int last = 0; last < 4; last++) {

      int maxi = 0;
      for (int task = 0; task < 3; task++) {
        if (task != last) {

          int activity = points[day][task] + prev[task];
          maxi = max(maxi, activity);
        }
      }
      temp[last] = maxi;
    }
    prev=temp;
  }

  return max(prev[0], max(prev[1], prev[2]));
}

int ninjaTraining(int n, vector<vector<int>> &points) {
  int ans = solve(n - 1, -1, points);
  return ans;
}