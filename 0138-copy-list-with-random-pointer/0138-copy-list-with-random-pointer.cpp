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
        if (!head)
            return nullptr;

        Node* curr = head;

        while (curr) {
            Node* nextNode = curr->next;
            Node* newNode = new Node(curr->val);
            curr->next = newNode;
            if (nextNode)
                newNode->next = nextNode;
            curr = nextNode;
        }
        curr = head;

        while (curr && curr->next) {
            Node* currRandom = curr->random;
            if (currRandom) {
                curr->next->random = currRandom->next;
            }
            curr = curr->next->next;
        }

        curr = head;
        Node* dummy = new Node(0);
        Node* copyCurr = dummy;
        while (curr) {
            copyCurr->next = curr->next;
            curr->next = curr->next->next;
            curr = curr->next;
            copyCurr = copyCurr->next;
        }

        return dummy->next;
    }
};