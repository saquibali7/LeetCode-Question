class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n==0 ||n==2 || n <0){
            return false;
        }
        int temp=n;
        while(temp > 0){
            if(temp==1){
                temp /=3;
                continue;
            }
            if(temp%3 != 0){
                return false;
            }
            temp /=3;
        }
        return true;
    }
};