/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
   int  count = 0;

     pair<int,int> calAvg(TreeNode* root){
        if(root == NULL) return {0,0};

        pair<int,int> leftTree = calAvg(root->left);
        pair<int,int> rightTree = calAvg(root->right);

        int sum = leftTree.first + rightTree.first + root->val;
        int nodeCount = leftTree.second + rightTree.second + 1;

        int avg = sum / nodeCount;

        if(avg == root->val) count++;

        return {sum,nodeCount};
    }

    int averageOfSubtree(TreeNode* root) {
        calAvg(root);

        return count;
    }
};