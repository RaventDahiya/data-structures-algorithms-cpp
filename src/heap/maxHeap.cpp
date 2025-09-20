// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class Heap {
public:
    int* arr;
    int capacity;
    int index;

    Heap(int capacity) {
        this->capacity = capacity;
        arr = new int[capacity];
        index = 0;
    }

    void printHeap() {
        for (int i = 1;i <= index;i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void insert(int data) {
        if (index == capacity - 1) {
            cout << "overflow" << endl;
            return;
        }
        index++;
        arr[index] = data;
        int childIndex = index;
        while (childIndex > 1 && arr[childIndex / 2] < arr[childIndex]) {
            swap(arr[childIndex / 2], arr[childIndex]);
            childIndex = childIndex / 2;
        }
    }

    void deleteRoot() {
        if (index == 0) {
            cout << "Heap is empty" << endl;
            return;
        }
        swap(arr[1], arr[index]);
        index--;
        heapify(arr, index, 1);
    }

    void heapify(int arr[], int size, int i) {
        int largest = i;           // Initialize largest as root
        int left = 2 * i;          // left child index (1-based indexing)
        int right = 2 * i + 1;     // right child index

        if (left <= size && arr[left] > arr[largest]) {
            largest = left;
        }

        if (right <= size && arr[right] > arr[largest]) {
            largest = right;
        }

        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify(arr, size, largest);
        }
    }

};
int main() {
    // Write C++ code here
    Heap pq(10);
    pq.insert(10);
    pq.insert(5);
    pq.insert(20);
    pq.insert(30);
    pq.insert(40);
    pq.insert(50);
    pq.printHeap();
    pq.deleteRoot();
    pq.deleteRoot();
    pq.printHeap();
    return 0;
}