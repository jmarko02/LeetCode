
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(!root) return result;
        queue<TreeNode*> q;

        q.push(root);
        while(!q.empty()){
            vector<int> part;
            int size = q.size();
            for(int i = 0; i < size; i++){
                TreeNode* curr = q.front();
                q.pop();
                if(curr){
                    part.push_back(curr->val);
                    q.push(curr->left);
                    q.push(curr->right);
                }
            }
            if(!part.empty()) result.push_back(part);
        }   
        return result;
    }
};