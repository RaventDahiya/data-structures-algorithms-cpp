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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prevGroup = &dummy;

        while(true){
            //find kth node
            ListNode* kth = prevGroup;
            for(int i=0;i<k && kth;i++) kth = kth->next;
            if(!kth) break; //no more group present

            ListNode* nextGroup = kth->next;

            ListNode* curr = prevGroup->next;
            ListNode* prev = nextGroup;

            while(curr!=nextGroup){ //reverse k group
                ListNode* nextNode = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextNode;
            }

            //reconnect front
            ListNode* temp = prevGroup->next;
            prevGroup->next = kth;
            prevGroup = temp;
        }

        return dummy.next;
    }
    ListNode* swapPairs(ListNode* head) {
        return reverseKGroup(head,2);
    }
};