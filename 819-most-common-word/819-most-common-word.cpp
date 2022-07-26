class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        string temp2="!?',;.";
        unordered_set<char> s;
        unordered_set<string> b;
        for(auto i : banned){
            b.insert(i);
        }
        for(char i : temp2){
            s.insert(i);
        }
        unordered_map<string, int> m;
        string temp="";
        for(int i=0;i<paragraph.length();i++){
            if(s.find(paragraph[i])!=s.end() || paragraph[i]==' '){
               if(b.find(temp)==b.end() && temp.size() > 0){
                   m[temp]++;
               } 
                temp="";
            }
            else {
                temp+=tolower(paragraph[i]);
            }
        }
        if(temp.size() > 0){
            m[temp]++;
        }
        int temp1=0;
        string res="";
        for(auto i : m){
            if(i.second > temp1){
                temp1=i.second;
                res=i.first;
            }
        }
        return res;
    }
};