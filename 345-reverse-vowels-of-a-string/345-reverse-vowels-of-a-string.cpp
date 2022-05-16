class Solution {
public:
    string reverseVowels(string s) {
        vector<char> temp;
        for(int i=0;i<s.length();i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'){
                temp.push_back(s[i]);
            } else if(s[i]=='o' || s[i]=='u'){
                temp.push_back(s[i]);
            }
            else if(s[i]=='A'||s[i]=='E'||s[i]=='I'){
                temp.push_back(s[i]);
            } else if(s[i]=='O' || s[i]=='U'){
                temp.push_back(s[i]);
            }
        }
        string res="";
        int m=temp.size(),count=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'){
                res+=temp[m-count-1];
                count++;
            } else if(s[i]=='o' || s[i]=='u'){
                res+=temp[m-count-1];
                count++;
            } else if(s[i]=='A'||s[i]=='E'||s[i]=='I'){
                res+=temp[m-count-1];
                count++;
            } else if(s[i]=='O' || s[i]=='U'){
                res+=temp[m-count-1];
                count++;
            } else {
                res+=s[i];
            }
        }
        return res;
    }
};