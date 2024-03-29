/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        if(guess(n)==0){
            return n;
        }
        if(guess(n) == -1){
            return guessNumber(n-1);
        }
        if(guess(n)==1){
            return guessNumber(n+1);
        }
        return -1;
    }
};