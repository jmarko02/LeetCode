#include<string>
#include<vector>
#include <sstream>
using namespace std;
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<string> res;
        dfsSerialize(res, root);
        return join(res, ",");
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> vals = split(data, ',');
        int i = 0;
        return dfsDeserialize(vals, i);
    }
private:
    void dfsSerialize(vector<string>& res, TreeNode* node){
        if(!node){
            res.push_back("N");
            return;
        }
        res.push_back(to_string(node->val));
        dfsSerialize(res,node->left);
        dfsSerialize(res,node->right);
    }
    string join(vector<string>& res, string delimiter){
        ostringstream s;
        for(const auto& el : res){
            if(&el != &res[0]) s << delimiter;
            s << el;
        }
        return s.str();
    }

    vector<string> split(const string& data, const char delimiter){
        stringstream s(data);
        string el;
        vector<string> res;
        while(getline(s,el,delimiter)){
            res.push_back(el);
        }
        return res;
    }
    
    TreeNode* dfsDeserialize(vector<string>& vals, int& i){
        if(vals[i] == "N"){
            i++;
            return NULL;
        }
        TreeNode* node = new TreeNode(stoi(vals[i]));
        i++;
        node->left = dfsDeserialize(vals,i);
        node->right = dfsDeserialize(vals,i);
        return node;
    }
};  

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));