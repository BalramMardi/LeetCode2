class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        map<int, int> events; 
        
        for (auto &log : logs) {
            events[log[0]]++; 
            events[log[1]]--; 
        }
        
        int maxYear = 0, maxPopulation = 0, currentPopulation = 0;
        
       
        for (auto &event : events) {
            currentPopulation += event.second;
            if (currentPopulation > maxPopulation) {
                maxPopulation = currentPopulation;
                maxYear = event.first;
            }
        }
        
        return maxYear;
    }
};