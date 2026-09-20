/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;

        unordered_map<Node*,Node*>mp;
        Node dummy(0);
        Node* newCurr = &dummy;

        Node* oldCurr = head;

        while(oldCurr){
            newCurr->next = new Node(oldCurr->val);
            newCurr = newCurr->next;
            mp[oldCurr] = newCurr;
            oldCurr = oldCurr->next;
        }

        oldCurr = head;

        while(oldCurr){
            Node* oldRandom = oldCurr->random;
            Node* temp1 = mp[oldCurr];
            Node* temp2 = mp[oldRandom];
            if(oldRandom){
                temp1->random = temp2;
            }
            oldCurr = oldCurr->next;
        }

        return dummy.next;

    }
};