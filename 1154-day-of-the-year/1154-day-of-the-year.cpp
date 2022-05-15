class Solution {
public:
    int dayOfYear(string date) {
        int  month[12]= {31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
        int dt=stoi(date.substr(8,2));
        int mt=stoi(date.substr(5,2));
        int yr=stoi(date.substr(0,4));
        int res=0;
        if(mt-2>=0){
            res = month[mt-2]+dt;
        } else {
            res=dt;
        }
        if(yr%400==0 && mt>2){
            res++;
        }
        if(yr%4==0 && mt>2 && yr%100!=0){
            res++;
        }
        return res;
        
        
        
    }
};