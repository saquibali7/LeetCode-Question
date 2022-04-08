class Solution {
public:
    string longestWord(vector<string>& words) {
        int n=words.size();
        unordered_map<string,int> m;
        for(int i=0;i<n;i++){
            m.insert({words[i],words[i].length()});
        }
        string res="";
        int size=-1;
        for(auto it : m){
            bool flag=false;
            string temp="";
            for(int j=0;j<it.second;j++){
                temp+=it.first[j];
                if(m.find(temp)==m.end()){
                    flag=true;
                    break;
                }
            }
            if(!flag && it.second > size){
                size=it.second;
                res=it.first;
            } 
            else if(!flag && it.second == size && it.first < res){
                size=it.second;
                res=it.first;
            } else {
                continue;
            }
        }
        return res;
    }
};