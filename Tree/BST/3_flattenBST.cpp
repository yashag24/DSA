// void getarray(TreeNode<int>*root,vector<int>&v){
// if(root==NULL )
// return;
// getarray(root->left,v);
// v.push_back(root->data);
// getarray(root->right, v);



// }
// TreeNode<int>* flatten(TreeNode<int>* root)
// {
// if (root == NULL) 
// return NULL;
 

//  vector<int>v;
//  getarray(root,v);
// int j =v.size();

// TreeNode<int>*newroot=new TreeNode<int>(v[0]);



// TreeNode<int>*temp=newroot;

// for(int i =1;i<j;i++){
//  temp->right = new TreeNode<int>(v[i]);
//  temp->left=NULL;
// temp=temp->right;

// }
// return newroot;





// }