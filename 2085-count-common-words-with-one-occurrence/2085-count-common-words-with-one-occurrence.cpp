class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        int n=words1.size(),p=words2.size();
        unordered_map<string,int> m1;
        unordered_map<string,int> m2;
        for(int i=0;i<n;i++){
            m1[words1[i]]++;
        }
        for(int i=0;i<p;i++){
            m2[words2[i]]++;
        }
        int count=0;
        for(auto it : m1){
            if(it.second == 1 && m2[it.first]==1){
                count++;
            }
        }
        return count;
        
    }
};