class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> dict(26,0);
        for(auto i : sentence){
            dict[i-'a']++;
        }
        for(int i=0;i<26;i++){
            if(dict[i]==0){
                return false;
            }
        }
        return true;
        
    }
};