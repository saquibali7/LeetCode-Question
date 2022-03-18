class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        int count[256]={0};
        int n=word1.length(),m=word2.length();
        for(int i=0;i<n;i++){
            count[word1[i]]++;
        }
        for(int i=0;i<m;i++){
            count[word2[i]]--;
        }
        for(int i=0;i<256;i++){
            if(count[i] > 3 || count[i] < -3){
                return false;
            }
        }
        return true;
        
    }
};