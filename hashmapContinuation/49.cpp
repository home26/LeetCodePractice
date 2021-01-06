class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>> ans;
        unordered_map<string, int> map;
        
        for(int i=0; i < strs.size(); i++){
            string strTemp = strs[i];
            sort(strTemp.begin(), strTemp.end());
            
            if(map.count(strTemp)){
                ans[map[strTemp]].push_back(strs[i]);
            }else{
                vector<string> temp(1, strs[i]);
                ans.push_back(temp);
                map[strTemp] = ans.size() - 1;
            }
        }
        return ans;
    }
};
