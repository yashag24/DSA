#include <iostream>
#include <climits>
using namespace std;
class Node
{
public:
    Node *left, *right;
    int data;
    Node(int d)
    {
        data = d;
        left = right = NULL;
    }
};

bool solve(Node *root, int min, int max)
{
    if (root == NULL)
        return true;

    if (min <= root->data && root->data <= max)
    {
        bool leftans = solve(root->left, min, root->data);
        bool rightans = solve(root->right, root->data, max);
        return rightans && leftans;
    }
    else
    {
        return false;
    }
}
bool validateBST(Node *root)
{

    return solve(root, INT_MIN, INT_MAX);
}

// wrong answer
//  bool validateBST(Node *root)
//  {

//     if (root == NULL)
//         return true;
//     if (root->right == NULL && root->left == NULL)
//         return true;
//     bool leftans = validateBST(root->left);
//     bool rightans = validateBST(root->right);
//     bool result;
//     if (root->left && !root->right)
//     {
//         result = (root->data > root->left->data) ? true : false;
//     }
//     else if (!root->left && root->right)
//     {
//         result = (root->data < root->right->data) ? true : false;
//     }
//     else
//     {
//         result =
//             ((root->data > root->left->data) && (root->data < root->right->data)) ? true : false;
//     }
//     if (leftans && rightans && result)
//         return true;
//     return false;
// }
/// right approach 1
// / 2 approach
// make inorder and check whether it is sorted or not

#include <iostream>
#include <vector>
using namespace std;

// Function to calculate the sum of digits of a number
int sumOfDigits(int num)
{
    int sum = 0;
    while (num > 0)
    {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

// Main function to calculate total products delivered for each client
vector<int> prodDelivery(vector<int> &orderIDs)
{
    vector<int> result;
    // For each orderID, calculate the sum of its digits
    for (int orderID : orderIDs)
    {
        result.push_back(sumOfDigits(orderID));
    }
    return result;
}

int main()
{
    // Input number of clients
    int numOfClients;
    cin >> numOfClients;

    // Input orderIDs
    vector<int> orderIDs(numOfClients);
    for (int i = 0; i < numOfClients; i++)
    {
        cin >> orderIDs[i];
    }

    // Calculate the total products delivered for each client
    vector<int> result = prodDelivery(orderIDs);

    // Output the result for each client
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}