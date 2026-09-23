/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int llLen(ListNode* head){

        int len = 0;
        while(head){
            len++;
            head = head->next;
            
        }
        return len;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==headB) return headA;

        int lenA = llLen(headA);
        int lenB = llLen(headB);
        if(lenA>lenB) return getIntersectionNode(headB,headA);
        int diff = lenB-lenA;
        //move diff in LL2
        for(int i=0;i<diff;i++){
            headB = headB->next;
        }

        while(headA && headB){
            if(headA==headB) return headA;
            headA = headA->next;
            headB = headB->next;
        }

        return nullptr;
    }
};