//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{   
    public:
    //Function to get the maximum total value in the knapsack.
    static bool cmp(pair<double,Item>a,pair<double,Item>b){
        return a.first > b.first;
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {

     vector<pair<double,Item>>unitVal;
    
     for(int i =0;i<n;i++)
     {
         double u = (arr[i].value*1.0)/arr[i].weight;
         unitVal.push_back({u,arr[i]});
         
     }
     
     sort(unitVal.begin(),unitVal.end() ,cmp);
    double val =0.0; 
    for(int i =0 ;i<n;i++)
    {   if(W<=0)
            break;
        int currwt =  unitVal[i].second.weight;
        int currval =  unitVal[i].second.value;
        double currUval =  unitVal[i].first;
        if(W<currwt)
        {
                   val += currUval * W;
                W = 0;

        }
        else
        {
                        W-=currwt;
            val+=currval;
        }
        
    }
        return val;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(6)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends