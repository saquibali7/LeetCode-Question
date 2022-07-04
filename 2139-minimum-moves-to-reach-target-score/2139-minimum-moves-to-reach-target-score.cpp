class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        long long int count=0;
        while(target!=1){
            if(maxDoubles==0){
                count+=(target-1);
                break;
            }
            if(target%2==0 && maxDoubles>0){
                target/=2;
                maxDoubles--;
            }
            else {
                target--;
            }
            count++;
        }
        return count;
    }
};