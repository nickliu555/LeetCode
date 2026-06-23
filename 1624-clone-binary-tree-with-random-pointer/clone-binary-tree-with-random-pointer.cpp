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
                NodeCopy* randomCopy = deepCopy(curr->random, NodeToNodeCopy);
                currCopy->random = randomCopy;
            }

            if (curr->left != nullptr) {
                NodeCopy* leftCopy = deepCopy(curr->left, NodeToNodeCopy);
                currCopy->left = leftCopy;
                bfsQueue.push({curr->left, leftCopy});
            }

            if (curr->right != nullptr) {
                NodeCopy* rightCopy = deepCopy(curr->right, NodeToNodeCopy);
                currCopy->right = rightCopy;
                bfsQueue.push({curr->right, rightCopy});
            }
        }
        return rootCopy;
    }

    NodeCopy* deepCopy(Node* node, unordered_map<Node*, NodeCopy*>& NodeToNodeCopy) {
        NodeCopy* nodeCopy;
        if (NodeToNodeCopy[node] != nullptr) {
            nodeCopy = NodeToNodeCopy[node];
        } else {
            nodeCopy = new NodeCopy(node->val);
            NodeToNodeCopy[node] = nodeCopy;
        }
        return nodeCopy;
    }
};