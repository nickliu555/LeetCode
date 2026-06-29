/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    Node* cloneTree(Node* root) {
        if (root == nullptr) return nullptr;

        Node* rootCopy = new Node(root->val);
        queue<Node*> bfsQueue;
        queue<Node*> bfsQueueCopy;
        bfsQueue.push(root);
        bfsQueueCopy.push(rootCopy);
        while (!bfsQueue.empty()) {
            Node* curr = bfsQueue.front();
            bfsQueue.pop();
            Node* currCopy = bfsQueueCopy.front();
            bfsQueueCopy.pop();

            for (Node* child: curr->children) {
                bfsQueue.push(child);
                Node* childCopy = new Node(child->val);
                currCopy->children.push_back(childCopy);
                bfsQueueCopy.push(childCopy);
            }
        }
        return rootCopy;
    }
};