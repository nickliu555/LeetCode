/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     Node *left;
 *     Node *right;
 *     Node *random;
 *     Node() : val(0), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x) : val(x), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x, Node *left, Node *right, Node *random) : val(x), left(left), right(right), random(random) {}
 * };
 */

class Solution {
public:
    NodeCopy* copyRandomBinaryTree(Node* root) {
        if (root == nullptr) return nullptr;
        unordered_map<Node*, NodeCopy*> NodeToNodeCopy;
        queue<pair<Node*, NodeCopy*>> bfsQueue;
        NodeCopy* rootCopy = new NodeCopy(root->val);
        bfsQueue.push({root, rootCopy});
        NodeToNodeCopy[root] = rootCopy;
        while (!bfsQueue.empty()) {
            Node* curr = bfsQueue.front().first;
            NodeCopy* currCopy = bfsQueue.front().second;
            bfsQueue.pop();
        
            if (curr->random != nullptr) {
                NodeCopy* randomCopy;
                if (NodeToNodeCopy[curr->random] != nullptr) {
                    randomCopy = NodeToNodeCopy[curr->random];
                } else {
                    randomCopy = new NodeCopy(curr->random->val);
                    NodeToNodeCopy[curr->random] = randomCopy;
                }
                currCopy->random = randomCopy;
            }

            if (curr->left != nullptr) {
                NodeCopy* leftCopy;
                if (NodeToNodeCopy[curr->left] != nullptr) {
                    leftCopy = NodeToNodeCopy[curr->left];
                } else {
                    leftCopy = new NodeCopy(curr->left->val);
                    NodeToNodeCopy[curr->left] = leftCopy;
                }
                currCopy->left = leftCopy;
                bfsQueue.push({curr->left, leftCopy});
            }

            if (curr->right != nullptr) {
                NodeCopy* rightCopy;
                if (NodeToNodeCopy[curr->right] != nullptr) {
                    rightCopy = NodeToNodeCopy[curr->right];
                } else {
                    rightCopy = new NodeCopy(curr->right->val);
                    NodeToNodeCopy[curr->right] = rightCopy;
                }
                currCopy->right = rightCopy;
                bfsQueue.push({curr->right, rightCopy});
            }
        }
        return rootCopy;
    }
};