class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int s1[256] = {0}, t1[256] = {0};
        for(int i = 0; i < t.size(); i++){
            if(s1[s[i]] != t1[t[i]]){
                return false;
            }
            s1[s[i]] = i + 1;
            t1[t[i]] = i + 1;
        }
        return true;
    }
};
