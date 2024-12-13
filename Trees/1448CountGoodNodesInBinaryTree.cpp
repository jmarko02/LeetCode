

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
    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);
    }
    int dfs(TreeNode* node, int val){
        if(!node) return 0;
        int res = (node->val >= val) ? 1 : 0;
        res += dfs(node->left, max(node->val, val));
        res += dfs(node->right, max(node->val, val));
        return res;
    }
};
/*
class Solution {
public:
    int goodNodes(TreeNode* root) {
        int res = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, -INT_MAX});
        while(!q.empty()){
            pair<TreeNode*, int> p = q.front();
            q.pop();
            int max = std::max(p.first->val, p.second);
            if(p.first->val >= p.second) res++;
            if(p.first->left) q.push({p.first->left, max});
            if(p.first->right) q.push({p.first->right, max});
        }
        return res;
    }
};
*/