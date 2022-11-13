class Solution {
public:
    string reverseWords(string s) {
        int n=s.length();
        stringstream ss(s);
        string word;
        vector<string> sv;
        while(ss>>word){
            sv.push_back(word);
        }
        string res="";
        for(int i=sv.size()-1;i>=0;i--){
            res+=sv[i];
            res+=' ';
        }
        res = res.substr(0,res.length()-1);
        return res;
        
    }
};