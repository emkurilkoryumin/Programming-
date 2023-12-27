#include <queue>
#include <iostream>
using namespace std;

int main() {
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int num;
    void addNum(int num); {
        if (maxHeap.empty() || num < maxHeap.top()) {
            maxHeap.push(num);
        }
        else {
            minHeap.push(num);
        }

        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian() {
        if (maxHeap.size() == minHeap.size()) {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }
        else {
            return maxHeap.top();
        }
    }

    addNum(2);
    addNum(3);
    cout << "Median: " << findMedian() << endl;
    addNum(4);
    cout << "Median: " << findMedian() << endl;

    return 0;
}

