
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> result;
        if (nums1.empty() || nums2.empty() || k == 0) return result;
        
        auto cmp = [](const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
            return get<0>(a) > get<0>(b);  
        };
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, decltype(cmp)> minHeap(cmp);
        
        
        minHeap.push({nums1[0]+nums2[0], 0, 0});

        
       
        unordered_set<string> visited;
        visited.insert("0_0");
        
        while (!minHeap.empty() && result.size() < k) {
            auto [sum, i, j] = minHeap.top();
            minHeap.pop();
            
            result.push_back({nums1[i], nums2[j]});
            
           
            if (i + 1 < nums1.size() && visited.find(to_string(i + 1) + "_" + to_string(j)) == visited.end()) {
                minHeap.push({nums1[i + 1] + nums2[j], i + 1, j});
                visited.insert(to_string(i + 1) + "_" + to_string(j));
            }
            
            
            if (j + 1 < nums2.size() && visited.find(to_string(i) + "_" + to_string(j + 1)) == visited.end()) {
                minHeap.push({nums1[i] + nums2[j + 1], i, j + 1});
                visited.insert(to_string(i) + "_" + to_string(j + 1));
            }
        }
        
        return result;
    }
};
