class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for(int i=0; i<nums.size(); i++){
            if(!map.count(nums[i])) map[target - nums[i]] = i;
            else if(map.count(nums[i])){
                int res[] = {map[nums[i]],i};
                return vector<int>(res, res+2);
            }
            
        }
        return vector<int> {99,99};
    }
};
