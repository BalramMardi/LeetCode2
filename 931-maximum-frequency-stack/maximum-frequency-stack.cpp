class FreqStack {
public:
    priority_queue<pair<int, pair<int, int>>> q;
    unordered_map<int, int> freq;
    int pos = 0;
    FreqStack() {
        
    }
    
    void push(int val) {
        q.emplace(++freq[val], make_pair(++pos, val));
    }
    
    int pop() {
        auto val = q.top();
        q.pop();
        int x = val.second.second;
        freq[x]--;
        return x;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */