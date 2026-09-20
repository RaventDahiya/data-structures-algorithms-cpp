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
    ListNode* sortList(ListNode* head) {
        if (!head)
            return nullptr;
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>,
                       greater<pair<int, ListNode*>>>
            pq;
        ListNode* curr = head;
        while(curr){
            pq.push({curr->val, curr});
            curr = curr->next;
        }

        ListNode dummy(0);
        ListNode* temp = &dummy;

        while (!pq.empty()) {
            auto [val, node] = pq.top();
            pq.pop();

            temp->next = node;
            temp = temp->next;
        }
        temp->next = nullptr;
        return dummy.next;
    }
};