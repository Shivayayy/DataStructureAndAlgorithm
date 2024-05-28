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
class NodeValue {
public:
    int maxNode, minNode, maxSum;
    bool isBST;

    NodeValue(int minNode, int maxNode, int maxSum, bool isBST) {
        this->maxNode = maxNode;
        this->minNode = minNode;
        this->maxSum = maxSum;
        this->isBST = isBST;
    }
};

class Solution { 
public:
    NodeValue largestbst(TreeNode* root, int& maxSum) {
        if (!root) return NodeValue(INT_MAX, INT_MIN, 0, true);

        NodeValue left = largestbst(root->left, maxSum);
        NodeValue right = largestbst(root->right, maxSum);

        if (left.isBST && right.isBST && root->val > left.maxNode && root->val < right.minNode) {
            int sum = left.maxSum + right.maxSum + root->val;
            maxSum = max(maxSum, sum);
            return NodeValue(min(root->val, left.minNode), max(root->val, right.maxNode), sum, true);
        }
        
        // If the subtree rooted at current node is not a BST, then return the maximum sum from its children
        return NodeValue(INT_MIN, INT_MAX, max(left.maxSum, right.maxSum), false);
    }

    int maxSumBST(TreeNode* root) {
        int maxSum = 0;
        largestbst(root, maxSum);
        return maxSum;
    }
};