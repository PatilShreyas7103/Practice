// ✅ Question: Find Ceil and Floor in a BST

#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <algorithm>
#include <stack>
#include <set>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// Definition for BST node
struct Node {
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// ------------------ Ceil Function ------------------
class SolutionCeil {
public:
    int findCeil(Node* root, int x) {
        Node* temp = root;
        int ans = -1;
        while (temp) {
            if (x > temp->data) {
                temp = temp->right;
            } else {
                ans = temp->data;
                temp = temp->left;
            }
        }
        return ans;
    }
};

// ------------------ Floor Function ------------------
class SolutionFloor {
public:
    int findFloor(Node* root, int x) {
        Node* temp = root;
        int ans = -1;
        while (temp) {
            if (x < temp->data) {
                temp = temp->left;
            } else {
                ans = temp->data;
                temp = temp->right;
            }
        }
        return ans;
    }
};

// Helper function to insert node in BST
Node* insert(Node* root, int key) {
    if (!root) return new Node(key);
    if (key < root->data)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    return root;
}

// ------------------ Driver Code ------------------
int main() {
    Node* root = NULL;
    vector<int> values = {8, 4, 12, 2, 6, 10, 14};
    for (int val : values) {
        root = insert(root, val);
    }

    SolutionCeil ceilFinder;
    SolutionFloor floorFinder;

    vector<int> testValues = {5, 13, 15, 1, 8};
    for (int x : testValues) {
        cout << "For x = " << x << ":\n";
        cout << "  Ceil  = " << ceilFinder.findCeil(root, x) << "\n";
        cout << "  Floor = " << floorFinder.findFloor(root, x) << "\n\n";
    }

    return 0;
}