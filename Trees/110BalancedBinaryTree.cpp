
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

    bool isBalanced(TreeNode* root){
        bool balanced = true;
        dfs(root, balanced);
        return balanced;
    }

    int dfs(TreeNode* node, bool& balanced){

        if(!node) return 0;
        int leftHeight = dfs(node->left, balanced);
        int rightHeight = dfs(node->right, balanced);

        balanced &= abs(leftHeight - rightHeight) <= 1;

        return 1 + max(leftHeight, rightHeight);
    }

//cursed:
    // bool isBalanced(TreeNode* root) {

    //     try {
    //         dfs(root);
    //     }
    //     catch (...)
    //     {
    //         return false;
    //     }
    //     return true;
    // }

    // int dfs(TreeNode* node){

    //     if(!node){
    //         return 0;
    //     }

    //     int left = dfs(node->left);
    //     int right = dfs(node->right);
    //     if(abs(left-right) > 1) throw 1;
    //     return 1 + max(left,right);
    // }
};
