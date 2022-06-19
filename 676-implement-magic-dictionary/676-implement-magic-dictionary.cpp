class MagicDictionary {
public:
    unordered_set<string> m;
    unordered_map<int,vector<string>> s;
    MagicDictionary() {
        
    }
    
    void buildDict(vector<string> dictionary) {
        for(int i=0;i<dictionary.size();i++){
            s[dictionary[i].length()].push_back(dictionary[i]);
        }
    }
    
    bool search(string searchWord) {
        if(s.find(searchWord.length())==s.end()){
            return false;
        } 
        else {
            for(int i=0;i<s[searchWord.length()].size();i++){
                int temp=0;
                for(int j=0;j<searchWord.length();j++){
                    if(searchWord[j]!=s[searchWord.length()][i][j]){
                        temp++;
                    }
                }
                if(temp==1){
                    return true;
                }
            } 
            
        }
        return false;
        
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */