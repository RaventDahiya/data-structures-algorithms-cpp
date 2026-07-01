class MedianFinder {
public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    MedianFinder() {}

    void addNum(int num) {
        // Handle first element separately
        if(maxHeap.empty() && minHeap.empty()) {
            maxHeap.push(num);
            return;
        }
        
        double mid = findMedian();
        if(num > mid) {
            minHeap.push(num);
        } else {
            maxHeap.push(num);
        }
        
        // Balance heaps after insertion
        int n = maxHeap.size();
        int m = minHeap.size();
        
        if(n > m + 1) {
            // maxHeap has too many elements
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } 
        else if(m > n) {
            // minHeap has too many elements
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian() {
        int n = maxHeap.size();
        int m = minHeap.size();
        
        if(n == 0 && m == 0) return 0;
        
        if(n == m) {
            return (maxHeap.top() + minHeap.top()) / 2.0;  // Fixed: 2.0 for double
        } else if(n > m) {
            return maxHeap.top();
        } else {
            return minHeap.top();
        }
    }
};