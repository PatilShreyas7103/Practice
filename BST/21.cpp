// ✅ Question: Convert Sorted Linked List to Binary Search Tree

#include <bits/stdc++.h>
using namespace std;
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <string>
#include <cmath>
#include <limits>
#include <climits>
#include <cstring>
#include <functional>
#include <iomanip>
#include <numeric>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == nullptr) return nullptr;
        if (head->next == nullptr) return new TreeNode(head->val);
        
        ListNode* slow = head, *fast = head, *slow_prev = nullptr;
        
        while (fast != nullptr && fast->next != nullptr) {
            slow_prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        TreeNode* root = new TreeNode(slow->val);
        
        slow_prev->next = nullptr;
        
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);
        
        return root;
    }
};
// Utility function to create linked list from vector
ListNode* createList(vector<int> vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* curr = head;
    for (int i = 1; i < vals.size(); i++) {
        curr->next = new ListNode(vals[i]);
        curr = curr->next;
    }
    return head;
}

// Utility function to print inorder traversal of BST
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    vector<int> nums = {-10, -3, 0, 5, 9};  // Sorted linked list values
    ListNode* head = createList(nums);

    Solution sol;
    TreeNode* bstRoot = sol.sortedListToBST(head);

    cout << "Inorder traversal of constructed BST: ";
    inorder(bstRoot);
    cout << endl;

    return 0;
}