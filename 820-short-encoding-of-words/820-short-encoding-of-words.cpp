class Solution {
public:
    static bool mycmp(string a, string b){
        return a.length() > b.length();
    }
    int minimumLengthEncoding(vector<string>& words) {
        unordered_set<string> m;
        sort(words.begin(),words.end(),mycmp);
        string s;
        for(int i=0;i<words.size();i++){
            if(m.find(words[i])!=m.end()){
                continue;
            }
            string temp="";
            for(int j=words[i].length()-1;j>=0;j--){
                reverse(temp.begin(),temp.end());
                temp+=words[i][j];
                reverse(temp.begin(),temp.end());
                m.insert(temp);
            }
            s+=words[i]+"#";
        }
        return s.length();   
    }
};