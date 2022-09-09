class Solution {
public:
    static bool mycmp(vector<int> &a, vector<int> &b){
        if(a[0]==b[0]){
            return a[1]>b[1]; 
        }
        return a[0]<b[0];
    }
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(),properties.end(),mycmp);
        int temp=INT_MIN;
        int count=0,n=properties.size();
        for(int i=n-1;i>=0;i--){
            if(properties[i][1] < temp){
                count++;
            }
            temp = max(temp, properties[i][1]);
        }
        return count;
    }
};