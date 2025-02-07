class MyCalendarThree {
public:
    map<int, int> timeline; 

    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        timeline[start]++;  
        timeline[end]--;    
        
        int currentActive = 0;
        int maxEvents = 0;
        
        for (auto &entry : timeline) {
            currentActive += entry.second; 
            maxEvents = max(maxEvents, currentActive); 
        }
        
        return maxEvents;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */