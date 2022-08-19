class Solution {
public:
    int arrangeCoins(int n) {
        int temp=1;
        int count=0;
        while(n>0){
            if(n<temp){
                break;
            }
            n-=temp;
            temp++;
            count++;
        }
        return count;
    }
};