class Solution {
public:
    string reversePrefix(string word, char ch) {
        int idx=-1;
        for(int i=0;i<word.length();i++){
            if(word[i]==ch){
                idx=i;
                break;
            }
        }
        if(idx!=-1){
            int low=0,high=idx;
            while(low<high){
                swap(word[low],word[high]);
                low++;
                high--;
            }
        }
        return word;
    }
};