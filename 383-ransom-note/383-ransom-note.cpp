class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int n=ransomNote.length(),m=magazine.length();
        int count[256] = {0};
        for(int i=0;i<m;i++){
            count[magazine[i]]++;
        }
        for(int j=0;j<n;j++){
            if(count[ransomNote[j]]!=0){
                count[ransomNote[j]]--;
            }
            else if(count[ransomNote[j]] == 0){
                return false;
            }
            else {
                continue;
            }
        }
        return true;
    }
};