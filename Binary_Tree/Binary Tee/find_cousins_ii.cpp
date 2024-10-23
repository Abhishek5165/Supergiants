// Brute Force ....

// Time Complexity : O(2N);
// Space Complexity : O(N);

// Time Complexity : O(N);
// Space Complexity : O(N);

class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        if (root == NULL) {
            return NULL;
        }
    
        queue<TreeNode*> Q;
        Q.push(root);

        int sum = root->val;

        while (!Q.empty()) {

            int nextLevelSum = 0;

            int size = Q.size();
            
            while (size--) {

            int SiblingSum = 0;
            TreeNode* node = Q.front();
            Q.pop();
            
            node->val = sum - node->val;

            SiblingSum += (node->left != NULL) ? 
            node->left->val : 0;
            SiblingSum += (node->right != NULL) ? 
            node->right->val : 0;

                if (node->left != NULL) {
                    nextLevelSum += node->left->val;
                    node->left->val = SiblingSum;
                    Q.push(node->left);
                }
                if (node->right != NULL) {
                    nextLevelSum += node->right->val;
                    node->right->val = SiblingSum;
                    Q.push(node->right);
                }
            }
            sum = nextLevelSum;
        }
        return root;
    }
};