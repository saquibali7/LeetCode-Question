class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        sort(aliceSizes.begin(),aliceSizes.end());
        sort(bobSizes.begin(),bobSizes.end());
        int n=aliceSizes.size(),m=bobSizes.size();
        int a=0,b=0;
        for(int i=0;i<n;i++){
            a+=aliceSizes[i];
        }
        for(int j=0;j<m;j++){
            b+=bobSizes[j];
        }
        int i=0,j=0;
        vector<int> res;
        while(i<n && j<m){
            if(a+2*bobSizes[j]==b+2*aliceSizes[i]){
                res.push_back(aliceSizes[i]);
                res.push_back(bobSizes[j]);
                break;
            } else if(a+2*bobSizes[j]>b+2*aliceSizes[i]){
                i++;
            } else {
                j++;
            }
        }
        return res;
        
    }
};