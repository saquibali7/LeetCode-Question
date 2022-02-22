class Solution {
public:
    int titleToNumber(string columnTitle) {
        long long int count=0;
        int n = columnTitle.length();
        for(int i=0;i<n;i++){
            count = count+(int)columnTitle[i]-64;
            if(columnTitle[i+1]!='\0'){
                count=count*26;
             }
        }
        
        return count;
    }
};