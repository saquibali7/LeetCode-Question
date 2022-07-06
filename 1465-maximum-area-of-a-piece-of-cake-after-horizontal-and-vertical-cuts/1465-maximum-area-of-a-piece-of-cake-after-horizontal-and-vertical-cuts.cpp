class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        int md = pow(10,9)+7;
        horizontalCuts.push_back(h);
        verticalCuts.push_back(w);
        int n=horizontalCuts.size(),m=verticalCuts.size();
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        long long int maxV=verticalCuts[0],maxH=horizontalCuts[0];
        for(int i=1;i<n;i++){
            if(maxH < horizontalCuts[i]-horizontalCuts[i-1]){
                maxH = horizontalCuts[i]-horizontalCuts[i-1];
            }
            
        }
        for(int i=1;i<m;i++){
            if(maxV < verticalCuts[i]-verticalCuts[i-1]){
                maxV = verticalCuts[i]-verticalCuts[i-1];
            }
            
        }
        return (maxV*maxH)%md;
       
        
        
        
    }
};