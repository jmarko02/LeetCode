
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 

#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* right = nullptr;
            int size = q.size();
            for(int i = 0; i < size; i++){
                TreeNode* curr = q.front();
                q.pop();
                if(curr) {
                    right = curr;
                    q.push(curr->left);
                    q.push(curr->right);
                }
            }
            if(right){
                result.push_back(right->val);
            }
        }
        return result;
    }
};
