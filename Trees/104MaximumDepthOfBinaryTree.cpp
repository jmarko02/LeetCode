

 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 #include <stack>
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        std::stack<std::pair<TreeNode*,int>> node_stack;
        node_stack.push({root,1});
        int maxDepth = 1;
        while(!node_stack.empty()){
            std::pair<TreeNode*, int> curr_pair = node_stack.top();
            TreeNode* curr = curr_pair.first;
            int depth = curr_pair.second;
            node_stack.pop();
            maxDepth = std::max(maxDepth, depth);
            if(curr->right) node_stack.push({curr->right,depth + 1} );
            if(curr->left) node_stack.push({curr->left, depth + 1});
        }
        return maxDepth;
    }
};