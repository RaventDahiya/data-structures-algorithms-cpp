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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>>pq;
        for(int i=0;i<lists.size();i++){
            if(lists[i])
                pq.push({lists[i]->val,lists[i]});
        }
        ListNode dummy(0);
        ListNode* temp = &dummy;

        while(!pq.empty()){
            auto [val,node] = pq.top(); pq.pop();
            if(node->next){
                pq.push({node->next->val,node->next});
            }
            temp->next = node;
            temp = temp->next;
        }
        return dummy.next;
    }
};