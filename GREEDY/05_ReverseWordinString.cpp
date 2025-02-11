//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        stack<string>st;
        string str="";
        for(int i = 0; i<S.size() ; i++){
            str = "";
            while( S[i]!='.'){
                str+=S[i];
                i++;
                if(i==S.size())
                break;
            }
            st.push(str);
        }
        str = "";
        while(!st.empty()){
            str+=st.top();
            st.pop();
            if(!st.empty())
            str+='.';
        }
        
    return str;    
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends