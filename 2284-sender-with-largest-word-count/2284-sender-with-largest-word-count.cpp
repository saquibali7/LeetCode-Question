class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        unordered_map<string, int> m;
        int n = messages.size();
        for(int i=0;i<n;i++){
            int count=1;
            for(int j=0;j<messages[i].size();j++){
                if(messages[i][j]==' '){
                    count++;
                }
            }
            m[senders[i]]+=count;
        }
        string res="";
        int mx=0;
        for(auto i : m){
            if(i.second > mx){
                mx=i.second;
                res=i.first;
            }
            if(i.second == mx && i.first > res){
                mx=i.second;
                res=i.first;
            }
        }
        return res;
        
    }
};