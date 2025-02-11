// #include <iostream>
// #include <vector>
// #include <cmath>
// #include <bits/stdc++.h>
// using namespace std;

// vector<vector<string>> solve(vector<string> q, vector<string> w)
// {
//     vector<vector<string>> ans;
//     unordered_map<string, vector<string>> m;
//     for (auto x : w)
//     {
//         string word = x;
//         sort(word.begin(), word.end());
//         m[word].push_back(x);
//     }

//     for (auto i : q)
//     {
//         // ans.push_back(i.second);
//         string word = i;
//         sort(word.begin(), word.end());

//         if (m.find(word) != m.end())
//         {
//             ans.push_back(m[word]);
//         }
//         else
//         {
//             ans.push_back({});
//         }
//     }

//     int n = ans.size();

//     for (int i = 0; i < n; i++)
//     {
//         sort(ans[i].begin(), ans[i].end());
//     }
//     return ans;
// }

// #include <iostream>
// #include <vector>
// #include <deque>

// using namespace std;

// int getMaxEfficiency(const vector<int> &arrivalTime)
// {
//     int maxEfficiency = INT_MIN;
//     int n = arrivalTime.size();

//     deque<int> minDeque, maxDeque;
//     int left = 0;

//     for (int right = 0; right < n; ++right)
//     {
//         // Maintain the maxDeque to keep track of the maximum in the current window
//         while (!maxDeque.empty() && arrivalTime[maxDeque.back()] <= arrivalTime[right])
//         {
//             maxDeque.pop_back();
//         }
//         maxDeque.push_back(right);

//         // Maintain the minDeque to keep track of the minimum in the current window
//         while (!minDeque.empty() && arrivalTime[minDeque.back()] >= arrivalTime[right])
//         {
//             minDeque.pop_back();
//         }
//         minDeque.push_back(right);

//         // Adjust the window if the time span is too large
//         while (arrivalTime[maxDeque.front()] - arrivalTime[minDeque.front()] > right - left)
//         {
//             ++left;
//             if (maxDeque.front() < left)
//                 maxDeque.pop_front();
//             if (minDeque.front() < left)
//                 minDeque.pop_front();
//         }

//         // Calculate the efficiency
//         int testCases = right - left + 1;
//         int timeActive = arrivalTime[maxDeque.front()] - arrivalTime[minDeque.front()];
//         int efficiency = testCases - timeActive;

//         // Update the maximum efficiency
//         maxEfficiency = max(maxEfficiency, efficiency);
//     }

//     return maxEfficiency;
// }

// int main()
// {
//     // Example input
//     vector<int> arrivalTimes = {8, 10, 12, 5, 6, 5, 7, 6, 10};

//     // Calculate maximum efficiency
//     int result = getMaxEfficiency(arrivalTimes);

//     // Print result
//     cout << "Maximum efficiency: " << result << endl;

//     return 0;
// }
// vector<int> isConvertibleData(const std::vector<std::string> &arr)
// {
//     std::vector<int> ans;

//     for (const std::string &str : arr)
//     {
//         std::stack<char> stack;
//         int allowedDown = 0;

//         for (char ch : str)
//         {
//             if (ch == '(')
//             {
//                 stack.push('(');
//             }
//             else
//             {
//                 if (!stack.empty())
//                 {
//                     stack.pop();
//                 }
//                 else
//                 {
//                     allowedDown++;
//                 }
//             }
//         }

//         if (stack.size() == 1 && allowedDown == 1)
//         {
//             ans.push_back(1);
//         }
//         else if (stack.empty() && allowedDown == 0)
//         {
//             ans.push_back(1);
//         }
//         else
//         {
//             ans.push_back(0);
//         }
//     }

//     return ans;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long

// string canreach(int x1, int y1, int x2, int y2)
// {
//     if (x1 == x2 && y1 == y2)
//     {
//         return "YES";
//     }
//     if (x1 > x2 || y1 > y2)
//     {
//         return "NO";
//     }
//     if (canreach(x1 + y1, y1, x2, y2) == "YES" || canreach(x1, y1 + x1, x2, y2) == "YES")
//     {
//         return "YES";
//     }
//     return "NO";
// }

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

unordered_map<string, string> memo;

string createKey(int x1, int y1)
{
    return to_string(x1) + "," + to_string(y1);
}

string canReach(int x1, int y1, int x2, int y2)
{

    if (x1 == x2 && y1 == y2)
    {
        return "YES";
    }
    if (x1 > x2 || y1 > y2)
    {
        return "NO";
    }

    string key = createKey(x1, y1);
    if (memo.find(key) != memo.end())
    {
        return memo[key];
    }

    if (canReach(x1 + y1, y1, x2, y2) == "YES" || canReach(x1, y1 + x1, x2, y2) == "YES")
    {
        memo[key] = "YES"; // Memoize the result
        return "YES";
    }

    memo[key] = "NO";

    return "NO";
}

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int findMaxBarrier(vector<int> &initialEnergy, int threshold)
{
    int n = initialEnergy.size();
    int left = 0, right = *max_element(initialEnergy.begin(), initialEnergy.end());

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        long long sum = 0;

        for (int i = 0; i < n; i++)
        {
            sum += max(initialEnergy[i] - mid, 0);
        }

        if (sum >= threshold)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return right;
}

int main()
{
    int n, threshold;
    cin >> n >> threshold;

    vector<int> initialEnergy(n);
    for (int i = 0; i < n; i++)
    {
        cin >> initialEnergy[i];
    }

    int maxBarrier = findMaxBarrier(initialEnergy, threshold);
    cout << "Maximum possible barrier: " << maxBarrier << endl;

    return 0;
}

#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

vector<vector<string>> getSearchResults(const vector<string> &words, const vector<string> &queries)
{
    map<string, vector<string>> anagram_dict;

    for (const string &word : words)
    {
        string sorted_word = word;
        sort(sorted_word.begin(), sorted_word.end());
        anagram_dict[sorted_word].push_back(word);
    }

    vector<vector<string>> result;
    for (const string &query : queries)
    {
        string sorted_query = query;
        sort(sorted_query.begin(), sorted_query.end());

        if (anagram_dict.find(sorted_query) != anagram_dict.end())
        {
            result.push_back(anagram_dict[sorted_query]);
        }
        else
        {
            result.push_back({});
        }
    }

    int n = result.size();

    for (int i = 0; i < n; i++)
    {
        sort(result[i].begin(), result[i].end());
    }

    return result;
}

int main()
{
    vector<string> words = {"duel", "speed", "duel", "cars"};
    vector<string> queries = {"spede", "deul"};

    vector<vector<string>> result = getSearchResults(words, queries);

    for (const vector<string> &anagrams : result)
    {
        for (const string &anagram : anagrams)
        {
            cout << anagram << " ";
        }
        cout << endl;
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
vector<int> getPopularityOrder(vector<vector<int>> song_preferences)
{
    int n = song_preferences[0].size();
    vector<vector<int>> boxScore(n, vector<int>(n, 0));
    for (const vector<int> &pref : song_preferences)
    {
        for (int i = 0; i < pref.size() - 1; i++)
        {
            for (int j = i + 1; j < pref.size(); j++)
            {
                boxScore[pref[i]][pref[j]] += 1;
            }
        }
    }

    vector<array<int, 2>> wins(n, {0, 0});
    for (int i = 0; i < n; i++)
    {
        wins[i][0] = i;
        for (int j = i + 1; j < n; j++)
        {
            int score = boxScore[i][j] - boxScore[j][i];
            if (score >= 0)
            {
                wins[i][1]++;
            }
            else
            {
                wins[j][1]++;
            }
        }
    }

    sort(wins.begin(), wins.end(), [](const array<int, 2> &a, const array<int, 2> &b)
         {
        if (a[1] == b[1]) {
            return a[0] < b[0];
        } else {
            return b[1] < a[1];
        } });

    vector<int> result;
    for (const auto &win : wins)
    {
        result.emplace_back(win[0]);
    }

    return result;
}

#include <bits/stdc++.h>
using namespace std;

vector<int> getPopularityOrder(vector<vector<int>> song_preferences)
{
    int n = song_preferences[0].size();
    vector<vector<int>> boxScore(n, vector<int>(n, 0));
    for (const vector<int> &pref : song_preferences)
    {
        for (int i = 0; i < pref.size() - 1; i++)
        {
            for (int j = i + 1; j < pref.size(); j++)
            {
                boxScore[pref[i]][pref[j]] += 1;
            }
        }
    }

    vector<array<int, 2>> wins(n, {0, 0});
    for (int i = 0; i < n; i++)
    {
        wins[i][0] = i;
        for (int j = i + 1; j < n; j++)
        {
            int score = boxScore[i][j] - boxScore[j][i];
            if (score >= 0)
            {
                wins[i][1]++;
            }
            else
            {
                wins[j][1]++;
            }
        }
    }

    sort(wins.begin(), wins.end(), [](const array<int, 2> &a, const array<int, 2> &b)
         {
        if (a[1] == b[1]) {
            return a[0] < b[0];
        } else {
            return b[1] < a[1];
        } });

    vector<int> result;
    for (const auto &win : wins)
    {
        result.emplace_back(win[0]);
    }

    return result;
}

int main()
{
    vector<vector<int>> song_preferences = {
        {0, 1, 2},
        {0, 2, 1},
        {1, 2, 0}};

    vector<int> popularity_order = getPopularityOrder(song_preferences);

    cout << "Popularity Order of Songs:" << endl;
    for (int song : popularity_order)
    {
        cout << song << " ";
    }
    cout << endl;

    return 0;
}