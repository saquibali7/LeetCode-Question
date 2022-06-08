class Solution {
public:
    void helper(string &s,vector<string> &res, int idx ){
        if(idx == s.length()){
            res.push_back(s);
            return;
        }
        if(s[idx]>=48 && s[idx]<=57){
            helper(s,res,idx+1);
            return;
        }
        s[idx]= toupper(s[idx]);
        helper(s,res,idx+1);
        s[idx]=tolower(s[idx]);
        helper(s,res,idx+1);
    }
    vector<string> letterCasePermutation(string s) {
        vector<string> res;
        int n=s.length();
        helper(s,res,0);
        return res;
        
    }
};