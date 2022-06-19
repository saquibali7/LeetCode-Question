class Trie {
public:
    unordered_set<string> s;
    unordered_map<string,vector<string>> m;
    Trie() {
        
    }
    
    void insert(string word) {
        s.insert(word);
        string temp="";
        for(int i=0;i<word.length();i++){
            temp+=word[i];
            m[temp].push_back(word);
        }
    }
    
    bool search(string word) {
        if(s.find(word)!=s.end()){
            return true;
        }
        return false;
        
    }
    
    bool startsWith(string prefix) {
        if(m[prefix].size()>0){
            return true;
        }
        return false;
        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */