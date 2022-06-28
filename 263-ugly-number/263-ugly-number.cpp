class Solution {
public:
    bool isUgly(int n) {
        unordered_set<int> s;
        if(n<0 || n==0){
            return false;
        }
        while(n%2==0){
            s.insert(2);
            n/=2;
        }
        for(int i=3;i<=sqrt(n);i=i+2){
            while(n%i==0){
                s.insert(i);
                n/=i;
            }
        }
        if(n>2){
            s.insert(n);
        }
        for(auto it : s){
            if(it==2 || it==3 || it==5){
                continue;
            }
            return false;
        }
        return true;
        
    }
};
