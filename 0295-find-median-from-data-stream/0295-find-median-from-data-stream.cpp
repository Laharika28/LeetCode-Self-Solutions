class MedianFinder {
public: 
    priority_queue<int> firstHalf;
    priority_queue<int, vector<int>, greater<int>> secondHalf;
    
    int s1,s2;
    
    MedianFinder() {
        s1=0;s2=0;
    }
    
    void addNum(int num) {
        
        int a = s1>0 ? firstHalf.top() : 0;
        int b = s2>0 ? secondHalf.top() : 0;
        
        if(s1==s2 || s1<s2){
            if (s2 == 0) {
                firstHalf.push(num);
            } else if(num < b) {
             firstHalf.push(num);
            } else {
               firstHalf.push(b);
               secondHalf.pop();
               secondHalf.push(num);
            }
            s1++;
        }
        else{
            if (num>a) {
                secondHalf.push(num);
            } else {
                secondHalf.push(a);
                firstHalf.pop();
                firstHalf.push(num);
            }
            s2++;
        }
    }
    
    double findMedian() {
        double ans ;
        if(s1==s2){
            ans = (float)(((float)firstHalf.top()+(float)secondHalf.top())/2.0);
        } else if (s1>s2) {
            ans = firstHalf.top();
        } else {
            ans = secondHalf.top();
        }
        return ans;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */