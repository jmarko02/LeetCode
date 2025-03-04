 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 #include <algorithm>
 using namespace std;
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        dfs(root,res);
        return res;
    }
    int dfs(TreeNode* root, int& res){
        if (!root) return 0;
        int leftPath = dfs(root->left, res);
        int rightPath = dfs(root->right, res);
        res = max(res, leftPath + rightPath);

        return 1 + max(leftPath, rightPath);
    }
};