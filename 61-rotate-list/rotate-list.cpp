/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (k == 0 || head == nullptr) return head;

        int n = 1;
        ListNode* ptr = head;
        while (ptr->next != nullptr) {
            ptr = ptr->next;
            ++n;
        }

        // ptr is now the last node
        // point the last node to head
        ptr->next = head;

        int rotate = (n - (k % n)) % n;
        for (int i=0; i<rotate; ++i) {
            ptr = ptr->next;
        }

        ListNode* ans = ptr->next;
        ptr->next = nullptr;
        return ans;
    }
};