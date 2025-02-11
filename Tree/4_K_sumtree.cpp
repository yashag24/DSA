#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
class Node
{
public:
    Node *left;
    int data;
    Node *right;
    Node(int d)
    {
        data = d;
        left = right = NULL;
    }
};
void solve(Node *root, int k, int &count, vector<int> path)
{
    if (root == NULL)
        return;
    path.push_back(root->data);

    solve(root->left, k, count, path);
    solve(root->right, k, count, path);
    int sum = 0;
    for (int i = path.size(); i >= 0; i--)
    {
        sum += path[i];
        if (sum == k)
            count++;
    }
    path.pop_back();
}
int ksum(Node *root, int k)
{

    vector<int> path;
    int count = 0;

    solve(root, k, count, path);

    return count;
}
void solve(Node* root, int k, int& count, unordered_map<int, int>& prefixSum, int currentSum) {
    if (root == NULL)
        return;

    currentSum += root->data;

    // Check if there exists a subpath with sum equal to k
    if (prefixSum.find(currentSum - k) != prefixSum.end()) {
        count += prefixSum[currentSum - k];
    }

    // Update the prefix sum map
    prefixSum[currentSum]++;

    solve(root->left, k, count, prefixSum, currentSum);
    solve(root->right, k, count, prefixSum, currentSum);

    // Remove the current sum from the map to avoid interference with other paths
    prefixSum[currentSum]--;
}

int sumK(Node* root, int k) {
    int count = 0;
    unordered_map<int, int> prefixSum; // Map to store prefix sums
    prefixSum[0] = 1; // Initialize with a prefix sum of 0
    solve(root, k, count, prefixSum, 0);
    return count;
}
