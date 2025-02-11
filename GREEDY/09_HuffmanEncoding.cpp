//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Node{
    public:
    int d;
    Node * left;
    Node * right;
    Node(int data){
        d=data;
        left =NULL;
        right=NULL;
    }
};
struct Compare {
    bool operator()(Node* l, Node* r) {
        return l->d > r->d; // We want the smallest freq at the top
    }
};

class Solution
{
	public:
	void traverse(Node* root,vector<string>&ans,string t){
	    if(root->left == NULL && root->right == NULL){
	    
	        ans.push_back(t);
	        return;
	    }
	    traverse(root->left , ans , t+'0');
	    traverse(root->right , ans , t+'1');
	}
		vector<string> huffmanCodes(string S,vector<int> f,int N)
		{
		        priority_queue<Node*,vector<Node*>,Compare>pq;
		        for(int i =0;i<N;i++)
		        {
		        Node *temp=new Node(f[i]);    
		        pq.push(temp);
		            
		        }
		        
		        while(pq.size()>1)
		        {
		            Node* left = pq.top();
		            pq.pop();
		            Node* right = pq.top();
		            pq.pop();
		            
		            Node* temp = new Node(left->d+right->d);
		            
		            temp->left=left;
		            temp->right=right;
		            pq.push(temp);
		        }
		        
		        Node * root = pq.top();
		        vector<string >ans;
		        string temp="";
		        traverse(root,ans,temp);
		        return ans;
		        
		}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
	    string S;
	    cin >> S;
	    int N = S.length();
	    vector<int> f(N);
	    for(int i=0;i<N;i++){
	        cin>>f[i];
	    }
	    Solution ob;
	    vector<string> ans = ob.huffmanCodes(S,f,N);
	    for(auto i: ans)
	    	cout << i << " ";
	    cout << "\n";
    }
	return 0;
}
// } Driver Code Ends