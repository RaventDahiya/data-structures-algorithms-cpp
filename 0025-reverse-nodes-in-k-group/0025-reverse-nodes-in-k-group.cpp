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
        ListNode* temp = head;
        int count = 0;
        while(temp && count<k){
            temp = temp->next;
            count++;
        }
        if(count<k) return head;

        ListNode* curr = head;
        ListNode* prev = nullptr;
        for(int i=0;i<k;i++){
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        //curr is pointing to next group
        //prev is newhead 
        //head is now tail

        head->next = reverseKGroup(curr,k);
        return prev;
    }
};