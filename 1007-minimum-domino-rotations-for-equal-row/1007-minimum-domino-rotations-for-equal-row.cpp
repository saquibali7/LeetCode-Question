class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n=tops.size();
        int temp1 = tops[0];
        int temp2 = bottoms[0];
        bool flag1 = false, flag2=false;
        int count1=0,count2=0;
        int c1=0,c2=0;
        for(int i=0;i<n;i++){
            if(tops[i]!=temp1 && bottoms[i]!=temp1){
                flag1=true;
            }
            if(tops[i]!=temp2 && bottoms[i]!=temp2){
                flag2=true;
            }
            if(tops[i]==temp1){
                count1++;
            }
            if(bottoms[i]==temp1){
                count2++;
            }
            if(tops[i]==temp2){
                c1++;
            }
            if(bottoms[i]==temp2){
                c2++;
            }
        }
        int res;
        if(flag1 && flag2){
            return -1;
        }
        if(flag1){
            res = n- max(c1,c2);
            return res;
        }
        if(flag2){
            res = n- max(count1,count2);
        }
        res = min((n-max(c1,c2)), (n- max(count1,count2)));
        return res;
        
    }
};