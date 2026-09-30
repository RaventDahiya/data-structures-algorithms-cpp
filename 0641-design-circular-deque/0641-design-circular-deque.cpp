class MyCircularDeque {
public:
    vector<int> cq;
    int head, tail, size, capacity;

    MyCircularDeque(int k) {
        cq.resize(k);
        head = 0;
        tail = 0;
        size = 0;
        capacity = k;
    }

    bool insertFront(int value) {
        if (isFull())
            return false;
        head = (head - 1 + capacity) % capacity;
        cq[head] = value;
        size++;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) return false;
        cq[tail] = value;
        tail = (tail + 1) % capacity;
        size++;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) return false;
        head = (head+1)%capacity;
        size--;
        return true;

    }

    bool deleteLast() {
        if (isEmpty()) return false;
        tail = (tail-1+capacity)%capacity;
        size--;
        return true;
    }

    int getFront() {
        if (isEmpty()) return -1;
        return cq[head];
    }

    int getRear() {
        if (isEmpty()) return -1;
        return cq[(tail - 1 + capacity) % capacity];
    }

    bool isEmpty() { return size == 0; }

    bool isFull() { return size == capacity; }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */