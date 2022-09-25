class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_set<int> s;
        int n=arr.size();
        for(int i=0;i<n;i++){
            s.insert(arr[i]);
        }
        int res=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int a = arr[i];
                int b = arr[j];
                int count=0;
                while(s.find(a+b)!=s.end()){
                    if(count==0){
                        count=2;
                    }
                    int temp=a;
                    a=b;
                    b=temp+b;
                    count++;
                }
                res = max(res,count);
            }
        }
        return res;
        
    }
};