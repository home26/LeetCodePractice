class Solution {
public:
    bool isHappy(int n) {
        set<int> search;
        int sum = 0;
        
        while(n != 1){

            while(n){
                sum += (n % 10) * (n % 10);
                n = n / 10;
            }
            n = sum;
            if(search.count(n)) break;
            else {
                search.insert(n);
                sum = 0;                
            }
        }
        
        return n == 1;
    }
};
