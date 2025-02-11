#include <iostream>
#include <vector>
#include <stack>
using namespace std;
// vector<int> nextSmallerElement(vector<int> &arr, int n)
// {
//     vector<int> ans;
//     int i = 0;

//     while (i != n)
//     {
//         int min = arr[i];
//         int k = i + 1;
//         while (k != n)
//         {
//             if (min > arr[k])
//             {
//                 min = arr[k];
//             }
//             // else
//             // {
//             //     min = -1;
//             // }
//             k++;
//         }
//         if (min == arr[i])
//         {

//             min = -1;
//         }
//         ans.push_back(min);
//         i++;
//     }

//     return ans;
// }
vector<int> nextsmaller(vector<int> &arr, int n)
{
    vector<int> ans(n);
    stack<int> s;
    s.push(-1);
    for (int i = n - 1; i >= 0; i--)
    {
        int num = arr[i];
        while (s.top() >= num)
        {
            s.pop();
        }
        arr[i]=num;
        s.push(num);
    }
    return ans;
}

int main()
{

    vector<int> arr = {
        5, 40, 300, 20};
    // vector<int> v = nextSmallerElement(arr, 4);
    //     for(int i: v){
    // cout<<i<<" ";
    //     }
}