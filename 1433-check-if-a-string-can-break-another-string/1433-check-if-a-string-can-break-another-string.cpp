class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        int n=s1.length();
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        bool flag1=false;
        bool flag2=false;
        for(int i=0;i<n;i++){
            if(s2[i]<s1[i]){
                flag1=true;
            }
        }
        for(int i=0;i<n;i++){
            if(s1[i]<s2[i]){
                flag2=true;
            }
        }
        if(!flag1 || !flag2){
            return true;
        }
        return  false;
    }
};