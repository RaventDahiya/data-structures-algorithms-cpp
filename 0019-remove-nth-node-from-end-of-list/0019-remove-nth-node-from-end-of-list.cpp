class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* dummy = new ListNode(0, head);

        ListNode* slow = dummy;
        ListNode* fast = dummy;

        // Create gap of n+1
        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }

        while (fast) {
            slow = slow->next;
            fast = fast->next;
        }

        // slow is before the node to delete
        ListNode* temp = slow->next;
        slow->next = temp->next;

        delete temp;

        head = dummy->next;
        delete dummy;

        return head;
    }
};