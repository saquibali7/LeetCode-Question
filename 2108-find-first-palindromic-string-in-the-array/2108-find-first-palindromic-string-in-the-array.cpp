class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        int n=words.size();
        for(int i=0;i<n;i++){
            int low=0,high=words[i].length()-1;
            bool flag=false;
            while(low<=high){
                if(words[i][low] != words[i][high]){
                    flag=true;
                    break;
                }
                high--;
                low++;
            }
            if(!flag){
                return words[i];
            }
        }
        string temp="";
        return temp;
    }
};