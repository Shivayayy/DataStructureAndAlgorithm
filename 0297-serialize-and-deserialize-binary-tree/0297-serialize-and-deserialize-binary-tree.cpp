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

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) 
    {
        if(root == NULL)return "";
        string serial;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* node =q.front();
            q.pop();
            if(!node)
            {
                serial.append("n,");
                continue;
            }
            serial.append(to_string(node->val)+',');
            q.push(node->left);
            q.push(node->right);
        }
        return serial;
    }

    TreeNode* deserialize(string data) 
    {
        if(data == "")return NULL;
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode* root =new TreeNode(stoi(str));
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* node =q.front();
            q.pop();

            string str;
            getline(s,str,',');
            if(str == "n")node->left =NULL;
            else
            {
                int value =stoi(str);
                node->left =new TreeNode(value);
                q.push(node->left);
            }

            getline(s,str,',');
            if(str == "n")node->right =NULL;
            else
            {
                int value =stoi(str);
                node->right =new TreeNode(value);
                q.push(node->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));