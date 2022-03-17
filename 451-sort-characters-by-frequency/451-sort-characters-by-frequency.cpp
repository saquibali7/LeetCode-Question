class Solution {
public:
    string frequencySort(string s) {
        int n=s.length();
        int count[256]={0};
        bool visited[256] ={false};
        for(int i=0;i<s.length();i++){
            count[s[i]]++;
        }
        string res="";
        for(int i=0;i<n;i++){
            int max=count[0],max_id=0;
            bool flag=false;
            for(int i=0;i<256;i++){
                if(count[i] > max){
                    flag=true;
                    max=count[i];
                     max_id = i;
                 }
            }
            if(flag){
                for(int i=0;i<max;i++){
                    res += max_id;
                }
            }
            count[max_id]=-1;
            
        }
        return res;
    }
};