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
    ListNode* reverseList(ListNode* head) {
        // Base case
        if (!head || !head->next)
            return head;

        ListNode* newHead = reverseList(head->next);

        head->next->next = head; // make next node point back
        head->next = nullptr;    // break original forward link

        return newHead;
    }
    ListNode* addTwoNumbers(ListNode* r1, ListNode* r2) {
        int carry = 0;
        ListNode dummy(-1);
        ListNode* curr = &dummy;
        while(r1 && r2){
            int sum = r1->val + r2->val + carry;
            int digit = sum % 10;
            carry = sum / 10;
            curr->next = new ListNode(digit);
            curr = curr->next;
            r1 = r1->next;
            r2 = r2->next;
        }
        while(r1){
            int sum = r1->val + carry;
            int digit = sum % 10;
            carry = sum / 10;
            curr->next = new ListNode(digit);
            curr = curr->next;
            r1 = r1->next;
        }
        while(r2){
            int sum = r2->val + carry;
            int digit = sum % 10;
            carry = sum / 10;
            curr->next = new ListNode(digit);
            curr = curr->next;
            r2 = r2->next;
        }
        if(carry){
            curr->next = new ListNode(carry);
            curr = curr->next;
        }
        return dummy.next;
    }
};