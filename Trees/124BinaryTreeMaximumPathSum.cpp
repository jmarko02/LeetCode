
#include <algorithm>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int result = root->val;
        dfs(root, result);
        return result;
    }

    int dfs(TreeNode* node, int& result){
        if(!node) return 0;

        int leftMax = max(dfs(node->left, result), 0);
        int rightMax = max(dfs(node->right, result), 0);

        result = max(result, node->val + leftMax + rightMax);
        return node->val + max(leftMax, rightMax);
    }
};