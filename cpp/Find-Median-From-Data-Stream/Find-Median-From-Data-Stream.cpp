// c++ Solution 1:
class MedianFinder {
public:
    /** initialize your data structure here. */
    vector<int> store;
    MedianFinder() {
        
    }
    void addNum(int num) {
        store.push_back(num);
    }
    
    double findMedian() {
        int n = store.size();
        sort(store.begin(),store.end());
        if (n%2==0)
        {
            return ((store[n/2]+store[n/2-1])/2.0);
        }
        else
        {
            return (store[n/2]);
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */


//  C++ Solution 2:
class MedianFinder {
public:
    /** initialize your data structure here. */
    vector<int> store;
    MedianFinder() {
        
    }
    void addNum(int num) {
        if (store.empty())
        {
            store.push_back(num);
        }
        else
            store.insert(lower_bound(store.begin(),store.end(),num),num);
    }
    
    double findMedian() {
        int n = store.size();
        if (n%2==0)
        {
            return ((store[n/2]+store[n/2-1])/2.0);
        }
        else
        {
            return (store[n/2]);
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
//  C++ Solution 3:
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    int count=0;
    void addNum(int num) {
        if (count%2==0) // 偶数放入最大堆
        {
            max.push(num);
            int max_num = max.top();
            max.pop();
            min.push(max_num);
        }
        else     // 奇数放入最小堆
        {
            min.push(num);
            int min_num=min.top();
            min.pop();
            max.push(min_num);
        }
        count++;
    }
    
    double findMedian() {
        if (count%2==0)
        {
            return ((max.top()+min.top())/2.0);
        }
        else
        {
            return (min.top());
        }
        
    }
private:
    priority_queue<int,vector<int>> max;  //大顶堆
    priority_queue<int,vector<int>,greater<int>> min;  // 小顶堆
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
