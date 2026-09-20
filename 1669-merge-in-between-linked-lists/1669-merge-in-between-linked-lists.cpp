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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* curr = list1;
        ListNode* prev = nullptr;
        int count = 0;

        while(curr && count<a){
            prev = curr;
            curr = curr->next;
            count++;
        }
        prev->next = list2;
        ListNode* list2Tail = list2;
        while(list2Tail->next){
            list2Tail = list2Tail->next;
        }
        ListNode* nextNode = curr->next;
        while(curr && count<b){
            curr = curr->next;
            if(curr) nextNode = curr->next;
            count++;
        }
        curr->next = nullptr;
        list2Tail->next = nextNode;
        return list1;
    }
};