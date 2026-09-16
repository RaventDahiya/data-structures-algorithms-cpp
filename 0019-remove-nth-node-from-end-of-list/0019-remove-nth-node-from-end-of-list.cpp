class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* fast = &dummy;
        ListNode* slow = &dummy;

        for (int i = 0; i < n; i++)
            fast = fast->next;

        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }

        slow->next = slow->next->next; // remove target node
        return dummy.next;
    }
    // Using dummy node handles edge case: removing head itself
};