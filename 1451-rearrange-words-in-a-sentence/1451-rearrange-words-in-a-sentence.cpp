class Solution {
public:
    string arrangeWords(string text) {
        map<int,string> m;
        string s="";
        int n=text.length();
        s+=tolower(text[0]);
        for(int i=1;i<n;i++){
            if(text[i]==' ') {
                if(m.find(s.size())==m.end())
                    m[s.size()]=s;
                else{
                    m[s.size()]+=' ';
                    m[s.size()]+=s;
                }
                s="";
            }
            else
                s+=text[i];
        }
        if(m.find(s.size())==m.end())
            m[s.size()]=s;
        else{
            m[s.size()]+=' ';
            m[s.size()]+=s;
        }
        string res="";
        bool flag=false;
        for(auto it:m){
            if(!flag){
                it.second[0]=toupper(it.second[0]);
                flag=true;
            }
            else{
                res+=" ";
            }
            res+=it.second;
        }
        return res;
    }
};