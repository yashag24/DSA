// pair<int, int> predecessorSuccessor(TreeNode* root, int key) {
//     int pred = -1;
//     int succ = -1;

//     if (root == NULL)
//         return make_pair(pred, succ);

//     TreeNode* temp = root;

//     while (temp != NULL && temp->data != key) {
//         if (temp->data > key) {
//             succ = temp->data;
//             temp = temp->left;
//         } else {
//             pred = temp->data;
//             temp = temp->right;
//         }
//     }

//     if (temp == NULL) {
//         // Key not found
//         return make_pair(pred, succ);
//     }

//     // pred
//     TreeNode* leftree = temp->left;
//     while (leftree != NULL) {
//         pred = leftree->data;
//         leftree = leftree->right;
//     }

//     // succ
//     TreeNode* rightree = temp->right;
//     while (rightree != NULL) {
//         succ = rightree->data;
//         rightree = rightree->left;
//     }

//     return make_pair(pred, succ);
// }



////mine
//void getarray(TreeNode*root,vector<long int>&v){
// if(root==NULL)
// return;


// getarray(root->left,v);
// v.push_back(root->data);
// getarray(root->right,v);

// }
// pair<int, int> predecessorSuccessor(TreeNode *root, int key)
// {
//     if(root==NULL)
//     return make_pair(-1,-1);
// vector<long int>v;
// getarray(root, v);
// int size =v.size();
// int i=0,flag =2;
// for( i =0;i<size;i++){

//     if (key == v[i]) {
//      flag =1;
//       break;
//     }
// }
// if(flag==2)
// return make_pair(-1,-1);
// if(i==0 ){
// return make_pair(-1,v[i+1]);
// }
// if(i==size-1){
//     return make_pair(v[i-1],-1);
// }
// return make_pair(v[i-1],v[i+1]);

