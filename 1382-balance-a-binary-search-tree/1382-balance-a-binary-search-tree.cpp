/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    void inOrderArray(TreeNode* &root, vector<int>& inOrder){
        if(root == nullptr) return;
        inOrderArray(root->left, inOrder);
        inOrder.push_back(root->val);
        inOrderArray(root->right, inOrder);
    }

    TreeNode* build_balanced_tree(vector<int>& inOrder, int s, int e)
    {
        if(s > e)
        {
            return nullptr;
        }
        int mid = s + (e-s) / 2;
        TreeNode* root = new TreeNode(inOrder[mid]);
        root->left = build_balanced_tree(inOrder, s, mid-1);
        root->right = build_balanced_tree(inOrder, mid + 1, e);
        return root;
    }

public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inOrder;
        inOrderArray(root, inOrder);
        return build_balanced_tree(inOrder, 0, inOrder.size()-1);
        
    }
};