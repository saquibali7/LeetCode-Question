class Solution {
public:
    bool helper(int i,int j, int k, string& s1, string& s2, string& s3,vector<vector<int>>& v){
        if(v[i][j]!=-1){
            return v[i][j];
        }
        if(i==s1.length() && j==s2.length() && k==s3.length()){
            return true;
        }
        if(i<s1.length() && s1[i]==s3[k] && j<s2.length() && s2[j]==s3[k]){            
            return v[i][j]= helper(i+1,j,k+1,s1,s2,s3,v) || helper(i,j+1,k+1,s1,s2,s3,v);                              
        } else if(i<s1.length() && s1[i]==s3[k]){
            return v[i][j]= helper(i+1,j,k+1,s1,s2,s3,v);
        } else if(j<s2.length() && s2[j]==s3[k]){
            return v[i][j]= helper(i,j+1,k+1,s1,s2,s3,v);
        }                   
        return false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length()+s2.length()!=s3.length()){
            return false;
        }
        vector<vector<int>> dp(s1.length()+1,vector<int>(s2.length()+1,-1));
        return helper(0,0,0,s1,s2,s3,dp);
        
    }
};