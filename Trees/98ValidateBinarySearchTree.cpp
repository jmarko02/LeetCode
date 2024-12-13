#include <climits>
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
    bool isValidBST(TreeNode* root) {
        return isValid(root, LONG_MIN, LONG_MAX);
    }
    bool isValid(TreeNode* node, long left, long right){
        if(!node) return true;
        if(!(node->val > left && node->val < right)) return false;
        return isValid(node->left, left, node->val) && isValid(node->right, node->val, right);
    }
};
 /*
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(!root) return 0;
        queue<tuple<TreeNode*, long, long>> q;
        q.push(make_tuple(root, LONG_MIN,LONG_MAX));
        while(!q.empty()){
            auto [node, left, right] = q.front();
            q.pop();
            if(!(node->val > left && node->val < right)) return false;
            if(node->left) q.push(make_tuple(node->left, left, node->val));
            if(node->right) q.push(make_tuple(node->right, node->val, right));
        }
        return true;
    }
};
*/
/*
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        auto a = checkSubtree(root, -1001, 1001);
        return std::get<0>(a);
    }

    std::tuple<bool, int, int> checkSubtree(TreeNode* node, int minVal, int maxVal)
    {
        if (!node) return {true, minVal, maxVal};
        auto left = checkSubtree(node->left, minVal, node->val);
        auto right = checkSubtree(node->right, node->val, maxVal);
        auto [left_valid, left_min, left_max] = left;
        auto [right_valid, right_min, right_max] = right;
        if(!left_valid || !right_valid) return {false,left_min, right_max};
        if(node->val > left_min && node->val < right_max) return {true,left_min,right_max};
        else return {false, left_min, right_max};
    }

};
*/