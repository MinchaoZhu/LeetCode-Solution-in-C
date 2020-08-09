class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
    }
    
    void addNum(int num) {
        int size = s.size();
        s.insert(num);
        if(size == 0) {
            left = right = s.begin();
        }
        else if(size%2 == 0) {
            // even
            if(num >= *left && num < *right) {
                advance(left, 1);
                advance(right, -1);
            }
            else if(num < *left) {
                advance(right, -1);
            }
            else {
                advance(left, 1);
            }
        }        
        else {
            // odd
            if(num < *left) {
                advance(left, -1);
            }            
            else {
                advance(right, 1);
            }
        }
    }
    
    double findMedian() {
        return ((double)*left + (double)*right)/2;
    }
    
private:
        multiset<int> s;
        multiset<int>::iterator left = s.end();
        multiset<int>::iterator right = s.end();
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */