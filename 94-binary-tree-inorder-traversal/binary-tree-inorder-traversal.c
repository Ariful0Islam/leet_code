/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// Helper function to perform the recursive inorder DFS and fill the array
void helper(struct TreeNode* root, int* res, int* index) {
    if (root == NULL) {
        return;
    }
    helper(root->left, res, index);
    res[(*index)++] = root->val;
    helper(root->right, res, index);
}
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* res = (int*)malloc(100 * sizeof(int));
    *returnSize = 0;
    helper(root, res, returnSize);
    return res;
}
