// ✅ Question: Serialize and Deserialize BST

#include <iostream>
#include <sstream>
#include <string>
#include <queue>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
    // 🔹 Encodes a tree to a single string (Level-order traversal)
    string serialize(TreeNode* root) {
        if (root == NULL) {
            return "";
        }

        string ans = "";
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            auto node = q.front();
            q.pop();

            if (node == NULL) {
                ans += "#,";
            } else {
                ans += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            }
        }

        return ans;
    }

    // 🔹 Decodes your encoded data to tree
    TreeNode* deserialize(string data) {
        if (data.empty()) {
            return NULL;
        }

        stringstream s(data);
        string str;

        getline(s, str, ',');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            auto f = q.front();
            q.pop();

            // Left child
            if (str == "#") {
                f->left = NULL;
            } else {
                TreeNode* t = new TreeNode(stoi(str));
                f->left = t;
                q.push(t);
            }

            // Right child
            if (str == "#") {
                f->right = NULL;
            } else {
                TreeNode* t = new TreeNode(stoi(str));
                f->right = t;
                q.push(t);
            }
        }

        return root;
    }
};

// ✅ Example usage for VS Code
int main() {
    Codec ser, deser;

    // Constructing a simple tree
    //        1
    //       / \
    //      2   3
    //         / \
    //        4   5
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    // Serialize the tree
    string data = ser.serialize(root);
    cout << "Serialized Tree: " << data << endl;

    // Deserialize it back
    TreeNode* newRoot = deser.deserialize(data);
    cout << "Deserialized Tree Root Value: " << newRoot->val << endl;

    return 0;
}