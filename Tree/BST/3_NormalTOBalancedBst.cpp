// void getarray(TreeNode<int>*root,vector<int>&v){
// if(root==NULL )
// return;
// getarray(root->left,v);
// v.push_back(root->data);
// getarray(root->right, v);



// }
// TreeNode<int>* solve(TreeNode<int>* root,vector<int>&v,int i,int L){
// if(i>L)
// return NULL;

// int mid = (i +L)/2;
// root=new TreeNode<int>(v[mid]);
// root->left=solve(root->left,v,i,mid-1);
// root->right=solve(root->right,v,mid+1,L);
// }
// TreeNode<int>* balancedBst(TreeNode<int>* root) {
// if(root==NULL)
// return root;

// vector<int>v;
// getarray(root, v);

// int i =0;
// int L=v.size()-1;
// TreeNode<int>* newroot=NULL;
// newroot=solve(root,v,i,L);
// return newroot;

// }