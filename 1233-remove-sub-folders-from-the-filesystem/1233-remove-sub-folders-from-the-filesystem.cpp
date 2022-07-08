class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        unordered_set<string> s;
        sort(folder.begin(),folder.end());
        vector<string> res;
        for(int i=0;i<folder.size();i++){
            string temp="";
            bool flag=false;
            int m=folder[i].length();
            for(int j=0;j<m;j++){
                if(folder[i][j]!='/'){
                    temp+=folder[i][j];
                }
                if((folder[i][j]=='/' || j==m-1)&&s.find(temp)!=s.end()){
                    flag=true;
                    break;
                }
            }
            if(!flag){
                s.insert(temp);
                res.push_back(folder[i]);
            }
        }
        return res;
        
    }
};