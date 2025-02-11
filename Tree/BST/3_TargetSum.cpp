
// void getarray(BinaryTreeNode<int>*root,vector<int>&v){
// if(root==NULL )
// return;
// getarray(root->left,v);
// v.push_back(root->data);
// getarray(root->right, v);



// }
// bool twoSumInBST(BinaryTreeNode<int>* root, int target) {
// 	if(root==NULL)
//     return false;
//   vector<int>v;
// // get array
// getarray(root,v);

// int j =v.size()-1;
// int i =0;
// int sum =0;
// while(i<j){
// sum = v[i]+v[j];

// if(sum==target)
// return true;

// else if(sum>target)
// j--;
// else if(sum<target)
// i++;




// }
// return false;

// }