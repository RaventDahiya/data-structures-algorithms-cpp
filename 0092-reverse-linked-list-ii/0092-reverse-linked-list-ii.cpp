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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* leftPrev = nullptr;
        ListNode* rightNext = nullptr;
        ListNode* leftNode = nullptr;
        ListNode* rightNode = nullptr;
        ListNode dummy(0);
        dummy.next = head;
        int count = 0;
        ListNode* curr =  &dummy;
        while (curr) {
            if (count == left - 1)
                leftPrev = curr;
            if (count == left)
                leftNode = curr;
            if (count == right)
                rightNode = curr;
            if (count == right + 1)
                rightNext = curr;
            curr = curr->next;
            count++;
        }

        // reverse left to right
        curr = leftNode;
        ListNode* prev = nullptr;
        if (rightNode)
            prev = rightNext;

        while (curr && curr != rightNext) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        if (leftPrev->next)
            leftPrev->next = rightNode;
        return dummy.next;
    }
};