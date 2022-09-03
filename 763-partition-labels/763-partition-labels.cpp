class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> m;
        for(int i=0;i<s.length();i++){
            m[s[i]]++;
        }
        vector<int> res;
        int temp1=0,idx=0;
        for(int i=0;i<s.length();i++){
            m[s[i]]--;
            if(m[s[i]]!=0){
                continue;
            }
            bool flag=false;
            for(int j=i;j>=0;j--){
                if(m[s[j]]!=0){
                    flag=true;
                    break;
                }
            }
            if(!flag){
                res.push_back(i-idx+1);
                idx = i+1;
            }
        }
        return res;
    }
};