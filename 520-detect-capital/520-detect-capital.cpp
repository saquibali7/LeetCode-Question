class Solution {
public:
    bool detectCapitalUse(string word) {
        int count1=0,count2=0;
        for(int i=0;i<word.length();i++){
            if(word[i]>=97 && word[i]<=122){
                count1++;
            }
            else if(word[i]>=65 && word[i]<=90){
                count2++;
            }
        }
        if(count1==word.length() || count2==word.length()){
            return true;
        }
        if(count2==1 && word[0]>=65 && word[0]<=90){
            return true;
        }
        return false;
        
    }
};