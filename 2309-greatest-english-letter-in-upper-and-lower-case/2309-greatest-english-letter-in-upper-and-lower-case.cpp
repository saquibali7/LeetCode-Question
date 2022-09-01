class Solution {
public:
    string greatestLetter(string s) {
        unordered_set<int> se;
        char res='a';
        for(auto i : s){
            se.insert(i);
        }
        for(int i=0;i<=26;i++){
            if(se.find(i+65)!=se.end() && se.find(i+97)!=se.end()){
                res=i+65;
            }
        }
        string res1="";
        if(res=='a'){
            return res1;
        }
        res1+=res;
        return res1;
    }
};