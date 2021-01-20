class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int, int> map;
        for(auto i : nums) map[i]++;
        
        priority_queue<pair<int, int>> heap;
        for(auto i : map) heap.push(make_pair(i.second, i.first));
        
        vector<int> ans;
        for(int i = 0; i<k; i++){
            ans.push_back(heap.top().second);
            heap.pop();
        }
        return ans;
    }
};
