
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
   };
 

#include<vector>
using namespace std;
class Solution {
public:
    int kthSmallest(TreeNode* root, int k){
        vector<int> arr(2);
        arr[0] = k;
        inorder(root,arr);
        return arr[1];
    }
    void inorder(TreeNode* node, vector<int>& arr){
        if(!node) return;
        inorder(node->left, arr);
        arr[0]--;
        if(arr[0] == 0) {
            arr[1] = node->val;
            return;
        }
        inorder(node->right, arr);
    }

};
// class Solution {
// public:
//     int kthSmallest(TreeNode* root, int k) {
//         vector<int> arr;
//         inorder(root,arr);
//         return arr[k-1];
//     }
//     void inorder(TreeNode* node, vector<int>& arr){
//         if(!node) return;
//         inorder(node->left, arr);
//         arr.push_back(node->val);
//         inorder(node->right, arr);
//     }
// };