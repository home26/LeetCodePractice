class Solution {
public:
    bool isValid(string s) {
        stack<char> ans;
        for(int i=0; i<s.size(); i++){
            char temp = s[i];
            if(ans.empty()){
                ans.push(temp);
                continue;
            }
            if(ans.top() == '(' && temp == ')'){
                ans.pop();
                continue;
            } 
            if(ans.top() == '{' && temp == '}'){
                ans.pop();
                continue;
            } 
            if(ans.top() == '[' && temp == ']'){
                ans.pop();
                continue;
            } 
            ans.push(temp);
        } 
        if(ans.empty()) return true;
        else return false;
    }
};
