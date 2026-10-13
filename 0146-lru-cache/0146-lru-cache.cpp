
class CacheNode {
public:
    int key, val;
    CacheNode* next = nullptr;
    CacheNode* prev = nullptr;

    CacheNode(int k, int v) : key(k), val(v) {}
};

class LRUCache {
public:
    int cap;
    CacheNode* head;
    CacheNode* tail;
    unordered_map<int, CacheNode*> mp;

    LRUCache(int capacity) {
        head = new CacheNode(-1, -1);
        tail = new CacheNode(-1, -1);

        head->next = tail;
        tail->prev = head;

        cap = capacity;
    }

    void AddAfterHead(CacheNode* node) {
        auto nextNode = head->next;

        head->next = node;
        node->prev = head;
        node->next = nextNode;
        nextNode->prev = node;
    }

    void deleteNode(CacheNode* node) {
        auto prevNode = node->prev;
        auto nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;

        node->next = nullptr;
        node->prev = nullptr;
    }

    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;

        auto node = mp[key];
        deleteNode(node);
        AddAfterHead(node);

        return node->val;
    }

    void put(int key, int value) {
        if (cap == 0) return;

        if (mp.find(key) != mp.end()) {
            auto node = mp[key];

            deleteNode(node);
            AddAfterHead(node);

            node->val = value;
        } 
        else {
            if (mp.size() == cap) {
                auto node = tail->prev;

                deleteNode(node);
                mp.erase(node->key);
                delete node;
            }

            CacheNode* node = new CacheNode(key, value);
            mp[key] = node;
            AddAfterHead(node);
        }
    }

    ~LRUCache() {
        CacheNode* curr = head;
        while (curr != nullptr) {
            CacheNode* nextNode = curr->next;
            delete curr;
            curr = nextNode;
        }
    }
};
