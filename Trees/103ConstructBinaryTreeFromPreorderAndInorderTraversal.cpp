
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 

#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
private:
    int preorder_index = 0;
    unordered_map<int,int> m;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty() || inorder.empty()) return nullptr;
        for(int i = 0; i < inorder.size(); i++){
            m[inorder[i]] = i;
        }
        return dfs(preorder, 0, inorder.size() - 1);
    }

    TreeNode* dfs(vector<int>& preorder, int l, int r){
        if ( l > r ) return nullptr;
        int node_val = preorder[preorder_index++];
        TreeNode* node = new TreeNode(node_val);
        int mid = m[node_val];
        node->left = dfs(preorder, l, mid - 1);
        node->right = dfs(preorder, mid + 1, r);
        return node;
    }
};
