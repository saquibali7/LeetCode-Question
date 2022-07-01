class Solution {
public:
    static bool mycmp(vector<int> a, vector<int> b){
        return a[1] >  b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),mycmp);
        int n=boxTypes.size();
        int countBox=0,res=0;
        for(int i=0;i<n;i++){
            if(countBox+boxTypes[i][0]<=truckSize){
                countBox+=boxTypes[i][0];
                res+=(boxTypes[i][0]*boxTypes[i][1]);
            } else if(countBox<truckSize){
                res+=((truckSize-countBox)*boxTypes[i][1]);
                countBox+=(truckSize-countBox);
            } 
            if(countBox>=truckSize){
                break;
            }
        }
        return res;
    }
};