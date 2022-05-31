class Solution {
public:
    bool judgeSquareSum(int c) {
        long long int high = sqrt(c);
        long long int low = 0;
        while(low<=high){
            if(((high*high)+(low*low))==c){
                return true;
            } else if(((high*high)+(low*low))<c){
                low++;
            } else {
                high--;
            }
        }
        return false;
        
    }
};