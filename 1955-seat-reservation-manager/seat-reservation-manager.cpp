class SeatManager {
public:

    priority_queue<int> maxpq;
    priority_queue<int,vector<int>,greater<int>> minpq;
    int num;

    SeatManager(int n) {
        for(int i=1;i<=n;i++){
            minpq.push(i);
        }
    }
    
    int reserve() {
        int first = minpq.top();
        minpq.pop();
        return first;
    }
    
    void unreserve(int seatNumber) {
        minpq.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */