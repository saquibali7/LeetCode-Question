class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int> m;
        int n=arr.size();
        for(int i=0;i<n;i++){
            m[arr[i]]++;
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(m[arr[i]] > 1){
                continue;
            }
            else {
                if(count==k-1){
                    return arr[i];
                }
                count++;
            }
        }
        string res="";
        return res;
        
    }
};