class NumberContainers {
public:
    map<int,set<int>> mp;
    map<int,int> num;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(num[index]){
            int nn = num[index];
            if(mp[nn].find(index)!=mp[nn].end())
                mp[nn].erase(index);
            if(mp[nn].empty()){
                mp.erase(nn);
            }
        }
        mp[number].insert(index);
        num[index] = number;
    }
    
    int find(int number) {
        if(mp.find(number) == mp.end()){
            return -1;
        }
        return *mp[number].begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */