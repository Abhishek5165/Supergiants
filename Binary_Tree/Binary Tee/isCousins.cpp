class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
    if(root == NULL){
        return false;
    }
    bool xfound = false;
    bool yfound = false;
    if(x == y){
        return false;
    }
    queue<TreeNode*>Q;
    Q.push(root);

    while(!Q.empty()){
    int size = Q.size();

    for(int i=0;i<size;i++){

       TreeNode* node = Q.front();
       Q.pop();

       if(node->val == x){
        xfound = true;
       }
       if(node->val == y){
        yfound = true;
       }
       
       if((node->left != NULL && node->right != NULL) && 
       ((node->left->val == x && node->right->val == y) 
       || (node->left->val == y && node->right->val == x))){
        return false;
       }
       if(node->left != NULL){
        Q.push(node->left);
       }
       if(node->right != NULL){
        Q.push(node->right);
       }
    }
    if(xfound && yfound){
        return true;
    }
    if(xfound || yfound){
        return false;
    }
    }
    return false;
    }
};