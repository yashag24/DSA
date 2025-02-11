//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
static bool cmp(const Job &a, const Job &b) {
    return a.profit > b.profit;
}

vector<int> JobScheduling(Job arr[], int n) {
    // Sort jobs based on descending order of profit
    sort(arr, arr + n, cmp);

    int maxDeadline = 0;
    // Find maximum deadline to size the job schedule vector
    for (int i = 0; i < n; i++) {
        if (arr[i].dead > maxDeadline) {
            maxDeadline = arr[i].dead;
        }
    }

    // Create a vector to keep track of free slots
    vector<int> slot(maxDeadline + 1, -1); // Using 1-based index for ease

    int countJobs = 0, totalProfit = 0;

    // Iterate over each job
    for (int i = 0; i < n; i++) {
        // Find a free slot for this job (in reverse from its deadline)
        for (int j = arr[i].dead; j > 0; j--) {
            if (slot[j] == -1) { // Free slot found
                slot[j] = arr[i].id; // Allocate the slot
                countJobs++;
                totalProfit += arr[i].profit;
                break; // Important: break after scheduling
            }
        }
    }

    return {countJobs, totalProfit};
} 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends