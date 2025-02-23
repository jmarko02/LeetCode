#include<queue>
#include<vector>
using namespace std;
class MedianFinder {
public:
    //divide stream into 2 parts
    priority_queue<int, vector<int>> maxHeap; //for lower values
    priority_queue<int, vector<int>, greater<int>> minHeap; //for greater values

    MedianFinder() {}
    
    void addNum(int num) {
        maxHeap.push(num);
        if(!minHeap.empty() && maxHeap.top() > minHeap.top())
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        if(maxHeap.size() > minHeap.size() + 1)
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        if(maxHeap.size() + 1 < minHeap.size()){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if(maxHeap.size() == minHeap.size())
            return ( maxHeap.top() + minHeap.top() ) / 2.0;
        if(maxHeap.size() > minHeap.size())
            return maxHeap.top();
        else return minHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */