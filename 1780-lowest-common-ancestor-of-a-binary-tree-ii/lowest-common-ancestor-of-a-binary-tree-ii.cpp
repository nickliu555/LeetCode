/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = nullptr;
        dfs(root, p, q, ans);
        return ans;
    }

    bool dfs(TreeNode* curr, TreeNode* p, TreeNode* q, TreeNode*& ans) {
        if (curr == nullptr) {
            return false;
        }

        int numMatches = 0;
        numMatches += curr->val == p->val || curr->val == q->val;
        numMatches += dfs(curr->left, p, q, ans);
        numMatches += dfs(curr->right, p, q, ans);

        if (numMatches == 2) {
            ans = curr;
        }
        return numMatches > 0;
    }
};