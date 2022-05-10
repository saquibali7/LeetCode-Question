class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector <string> temp(26);
        temp={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> s;
        int n=words.size();
        for(int i=0;i<n;i++){
            string temp1="";
            for(int j=0;j<words[i].length();j++){
                temp1+=temp[words[i][j]-97];
            }
            s.insert(temp1);
        }
        return s.size();
        
    }
};