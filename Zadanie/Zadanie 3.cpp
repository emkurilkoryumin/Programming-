#include <queue>
#include <iostream>
using namespace std;

void addNum(priority_queue<int>& maxHeap, priority_queue<int, vector<int>, greater<int>>& minHeap, int num) {
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

double findMedian(priority_queue<int>& maxHeap, priority_queue<int, vector<int>, greater<int>>& minHeap) {
    if (maxHeap.size() == minHeap.size()) {
        return (maxHeap.top() + minHeap.top()) / 2.0;
    }
    else {
        return maxHeap.top();
    }
}

int main() {
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    addNum(maxHeap, minHeap, 2);
    addNum(maxHeap, minHeap, 3);
    cout << "Median: " << findMedian(maxHeap, minHeap) << endl;
    addNum(maxHeap, minHeap, 4);
    cout << "Median: " << findMedian(maxHeap, minHeap) << endl;

    return 0;
}
