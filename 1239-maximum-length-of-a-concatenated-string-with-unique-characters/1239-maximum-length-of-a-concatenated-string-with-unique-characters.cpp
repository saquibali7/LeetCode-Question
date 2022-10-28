class Solution {
public:
    int res;
    void helper(int idx,vector<string>& arr,vector<int> vis,int curr){
        if(idx<0){
            res=max(res,curr);
            return;
        }
        bool flag=false;
        int n=arr[idx].length();
        vector<int> t=vis;
        for(int i=0;i<n;i++){
            if(t[arr[idx][i]-'a']==1){
                flag=true;
                break;
            }
            t[arr[idx][i]-'a']=1;
        }
        if(!flag){
            helper(idx-1,arr,t,curr+n);
        }
        helper(idx-1,arr,vis,curr);
        
    }
    int maxLength(vector<string>& arr) {
        int curr=0,n=arr.size();
        vector<int> vis(26,0);
        helper(n-1,arr,vis,curr);
        return res;
    }
};