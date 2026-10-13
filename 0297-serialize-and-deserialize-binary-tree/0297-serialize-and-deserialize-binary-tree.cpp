/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void help(TreeNode* root,string& result){
        if(root==nullptr){
            result +="N,";
            return;
        }
        result+=to_string(root->val)+",";
        help(root->left,result);
        help(root->right,result);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result;
        help(root,result);
        return result;
    }

    TreeNode* helper(stringstream& ss){
        string value;
        getline(ss,value,',');
        if(value=="N")
            return nullptr;
        TreeNode* root=new TreeNode(stoi(value));
        root->left=helper(ss);
        root->right=helper(ss);
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return helper(ss);
    }
};
// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));