
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

    bool isSubtree(TreeNode* root, TreeNode* subRoot){
        if(!subRoot) return true;
        if(!root) return false;
        if(check_same(root,subRoot)) return true;
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
private:
    bool check_same(TreeNode* p, TreeNode* q){
        if(!p && !q) return true;
        if(p && q && p->val == q->val){
            return check_same(p->left, q->left) && check_same(p->right, q->right);
        } else return false;
    }

    //  bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    //     if(!root && !subRoot) return true;
    //     std::queue<TreeNode*> queue;
    //     queue.push(root);
    //     int subroot = false;
    //     while(!queue.empty()){
    //         TreeNode* curr = queue.front(); queue.pop();
    //         if(curr->val == subRoot->val){
    //             subroot = check_same(curr, subRoot);
    //             if(subroot) break;
    //         }
    //         if(curr->left) queue.push(curr->left);
    //         if(curr->right) queue.push(curr->right);
    //     }
    //     return subroot;
    // }
};
