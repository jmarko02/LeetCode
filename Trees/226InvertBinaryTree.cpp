

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 #include<stack>
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return nullptr;
        std::stack<TreeNode*> node_stack;
        TreeNode* curr;
        node_stack.push(root);
        while(node_stack.empty() != true){
            curr = node_stack.top();
            node_stack.pop();
            TreeNode* tmp = curr->right ? curr->right : nullptr;
            curr->right = curr->left ? curr->left : nullptr;
            curr->left = tmp; 
            if(curr->left) node_stack.push(curr->left);
            if(curr->right) node_stack.push(curr->right);
        }
        return root;
    }
};