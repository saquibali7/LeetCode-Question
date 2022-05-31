class Solution {
public:
    bool divisorGame(int n) {
        int temp=n;
        bool flag=false;
        while(temp>1){
            for(int i=1;i<temp;i++){
                if(temp%i==0){
                    temp=temp-i;
                    break;
                }
            }
            flag=!flag;
        }
        return flag;
        
    }
};