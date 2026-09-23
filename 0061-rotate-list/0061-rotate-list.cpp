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

    int LLlen(ListNode* head) {
        int len = 0;

        while (head) {
            len++;
            head = head->next;
        }

        return len;
    }

    ListNode* rotateRight(ListNode* head, int k) {

        if (!head || !head->next)
            return head;

        int len = LLlen(head);

        // Effective rotations
        k = k % len;

        if (k == 0)
            return head;

        // We need to cut after (len - k) nodes
        ListNode* curr = head;

        int steps = len - k - 1;

        while (steps) {
            curr = curr->next;
            steps--;
        }

        // New head
        ListNode* newHead = curr->next;

        // Break first and second parts
        curr->next = nullptr;

        // Find tail of second part
        curr = newHead;

        while (curr->next) {
            curr = curr->next;
        }

        // Connect second part with old head
        curr->next = head;

        return newHead;
    }
};