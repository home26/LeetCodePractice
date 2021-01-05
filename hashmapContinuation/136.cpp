class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> res;
        for(int i=0; i < nums.size(); i++){
            if(!res.count(nums[i])){
                res.insert(nums[i]);
            }else{
                res.erase(nums[i]);
            }
            
        }
        auto ans = res.begin();
        return *ans;
    }
};
