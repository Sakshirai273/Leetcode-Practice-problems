class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int, vector<int>, greater<int> > minHeap;
	priority_queue<int> maxHeap;
    MedianFinder(){}

    void addNum(int num) {
        if (maxHeap.empty() || maxHeap.top() > num) {
			maxHeap.push(num);
		} else {
			minHeap.push(num);
		}
           //always maintain max wale ka size 1 greater than min wale ka size ya fir dono equal ho
		if (abs((int)maxHeap.size() - (int)minHeap.size()) > 1) {
			minHeap.push(maxHeap.top());
			maxHeap.pop();
		} else if (minHeap.size() > maxHeap.size() ) {
			maxHeap.push(minHeap.top());
			minHeap.pop();
		}
    }
    
    double findMedian() {
        if (maxHeap.size() == minHeap.size()) { //even no. of elements wala case hoga 
			if (maxHeap.empty()) {
				return 0;
			} else {
				double avg = (maxHeap.top() + minHeap.top()) / 2.0;
				return avg;
		}

		} else { //odd no. of elements wala case hoga 
			 return maxHeap.size() > minHeap.size() ? maxHeap.top() : minHeap.top();
           // return maxHeap.top();
		}
    }
};

