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
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;

        // Move prev to node just before 'left'
        for (int i = 0; i < left - 1; i++)
            prev = prev->next;

        ListNode* curr = prev->next;

        // Reverse the sublist
        for (int i = 0; i < right - left; i++) {
            ListNode* nextTemp = curr->next;
            curr->next = nextTemp->next;
            nextTemp->next = prev->next;
            prev->next = nextTemp;
        }

        return dummy.next;
    }
    // Time: O(n), Space: O(1)
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        // Count nodes
        int n = 0;
        ListNode* curr = head;

        while (curr) {
            n++;
            curr = curr->next;
        }

        int start = 1; // starting position of current group
        int groupSize = 1;

        while (start <= n) {

            int actualLen = min(groupSize, n - start + 1);
            int end = start + actualLen - 1;

            // Reverse only if actual group length is even
            if (actualLen % 2 == 0) {
                head = reverseBetween(head, start, end);
            }

            start = end + 1;
            groupSize++;
        }

        return head;
    }
};