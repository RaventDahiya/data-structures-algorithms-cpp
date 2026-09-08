#include <iostream>
using namespace std;

class Heap {
public:
    int* arr;
    int capacity;
    int index;

    Heap(int capacity) {
        this->capacity = capacity;
        arr = new int[capacity + 1];   // 1-based indexing
        index = 0;
    }

    void printHeap() {
        for (int i = 1; i <= index; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void insert(int data) {

        if (index == capacity) {
            cout << "Overflow" << endl;
            return;
        }

        // Insert at end
        index++;
        arr[index] = data;

        // Move upward
        int childIndex = index;

        while (childIndex > 1 &&
               arr[childIndex / 2] < arr[childIndex]) {

            swap(arr[childIndex / 2], arr[childIndex]);

            childIndex = childIndex / 2;
        }
    }

    void heapify(int arr[], int size, int i) {

        int largest = i;

        int left = 2 * i;
        int right = 2 * i + 1;

        if (left <= size &&
            arr[left] > arr[largest]) {

            largest = left;
        }

        if (right <= size &&
            arr[right] > arr[largest]) {

            largest = right;
        }

        if (largest != i) {

            swap(arr[i], arr[largest]);

            heapify(arr, size, largest);
        }
    }

    void deleteRoot() {

        if (index == 0) {
            cout << "Heap is empty" << endl;
            return;
        }

        // Put last element at root
        swap(arr[1], arr[index]);

        index--;

        // Restore max heap
        heapify(arr, index, 1);
    }

    int top() {

        if (index == 0) {
            cout << "Heap is empty" << endl;
            return -1;
        }

        return arr[1];
    }

    int size() {
        return index;
    }

    // -------------------------
    // HEAP SORT
    // -------------------------
    void heapSort() {

        int heapSize = index;

        while (heapSize > 1) {

            // Largest element is at arr[1]
            // Put it at the end
            swap(arr[1], arr[heapSize]);

            // Reduce heap size
            heapSize--;

            // Restore max heap
            heapify(arr, heapSize, 1);
        }
    }

    ~Heap() {
        delete[] arr;
    }
};

int main() {

    Heap pq(10);

    pq.insert(10);
    pq.insert(5);
    pq.insert(20);
    pq.insert(30);
    pq.insert(40);
    pq.insert(50);

    cout << "Max Heap: ";
    pq.printHeap();

    /*
              50
             /  \
           30    40
          / \    /
         5  20  10
    */

    cout << "Maximum element: " << pq.top() << endl;

    // Heap Sort
    pq.heapSort();

    cout << "After Heap Sort: ";
    pq.printHeap();

    return 0;
}
