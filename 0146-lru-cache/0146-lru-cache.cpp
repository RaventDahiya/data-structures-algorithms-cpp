class Node {
public:
    int val;
    Node* next;
    Node* prev;

    Node(int val) : val(val), next(nullptr), prev(nullptr) {}
};

class LRUCache {
public:
    int size;
    int cap;
    Node* head;
    Node* tail;
    unordered_map<int, pair<Node*, int>> mp;

    LRUCache(int capacity) {
        size = 0;
        cap = capacity;
        head = nullptr;
        tail = nullptr;
    }

    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;

        Node* node = mp[key].first;
        int value = mp[key].second;

        if (node == head) {
            // already at the front
            return value;
        }
        else if (node == tail) {
            // node at tail
            tail = node->prev;

            node->prev = nullptr;
            tail->next = nullptr;

            node->next = head;
            head->prev = node;

            head = node;

            return value;
        }
        else {
            // node somewhere in between
            node->prev->next = node->next;
            node->next->prev = node->prev;

            node->prev = nullptr;
            node->next = head;

            head->prev = node;
            head = node;

            return value;
        }

        return value;
    }

    void put(int key, int value) {

        // Key already exists
        if (mp.find(key) != mp.end()) {
            get(key); // brings node to head
            mp[key].second = value;
            return;
        }

        // Cache full
        if (size == cap) {

            Node* newNode = new Node(key);

            // Delete LRU node
            Node* toDelete = tail;
            int tailKey = tail->val;

            if (size == 1) {
                head = newNode;
                tail = newNode;

                mp.erase(tailKey);
                mp[key] = {newNode, value};

                delete toDelete;

                return;
            }
            else {
                tail = tail->prev;
                tail->next = nullptr;

                delete toDelete;
            }

            mp.erase(tailKey);

            // Add new node at head
            newNode->next = head;
            head->prev = newNode;

            head = newNode;

            mp[key] = {newNode, value};
        }

        // Cache not full
        else {

            if (!head && !tail) {
                // first element
                Node* newNode = new Node(key);

                head = newNode;
                tail = newNode;

                mp[key] = {newNode, value};
            }
            else {
                Node* newNode = new Node(key);

                newNode->next = head;
                head->prev = newNode;

                head = newNode;

                mp[key] = {newNode, value};
            }

            size++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */