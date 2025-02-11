//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int LongestBitonicSequence(int n, vector<int> &nums) {
        // code here
     
        vector<int>dpf(n,1),dpb(n,1);
        int maxi = 0;
        
        for(int i =0;i<n;i++){
            //front
            
            for(int prev =0;prev<i;prev++)
            {
                if(nums[prev]<nums[i] && dpf[i]<dpf[prev]+1)
                {
                    dpf[i]=dpf[prev]+1;
                }
            }
        }
        
        for(int i =n-1 ;i>=0;i--){
             //back
            for(int ahead =n-1;ahead>i;ahead--)
            {
                if(nums[ahead]<nums[i] && dpb[i]<dpb[ahead]+1)
                {
                    dpb[i]=dpb[ahead]+1;
                }
            }
            
        }
        
        for(int i =0;i<n;i++){
            if(dpb[i]!=1 && dpf[i]!=1)
                maxi= max(maxi,dpf[i]+dpb[i]-1);
        }
        return maxi;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        vector<int> nums(n);
        Array::input(nums, n);

        Solution obj;
        int res = obj.LongestBitonicSequence(n, nums);

        cout << res << endl;
    }
}

// } Driver Code Ends