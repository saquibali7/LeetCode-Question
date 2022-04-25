class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        int n=dictionary.size(),m=sentence.length();
        unordered_set<string> s;
        for(int i=0;i<n;i++){
            s.insert(dictionary[i]);
        }
        string res="";
        string temp;
        for(int i=0;i<m;i++){
            if(sentence[i]==' '){
                res+=' ';
                continue;
            }
            temp+=sentence[i];
            if(s.find(temp)!=s.end()){
                while(sentence[i]!=' ' && i!=m-1){
                    i++;
                }
                res+=temp;
                if(i!=m-1){
                    res+=' ';
                }
                temp="";
            }
            if(i==m-1){
                res+=temp;
            }
            else if(sentence[i+1]==' ' && i!=m-1){
                res+=temp;
                temp="";
            }
        }
        return res;
        
        
    }
};