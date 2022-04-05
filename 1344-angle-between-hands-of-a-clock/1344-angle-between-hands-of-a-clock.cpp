class Solution {
public:
    double angleClock(int hour, int minutes) {
        double minangle = 6*min(minutes, 60-minutes);
        double hourangle;
        if(hour<6){
            hourangle=30*min(hour,12-hour)+minutes*0.5;
        } else {
            hourangle=30*min(hour,12-hour)-minutes*0.5;
        }
        double res;
        if(hour < 6 && minutes <= 30){
            res= abs(minangle-hourangle);
        } else if(hour >= 6 && minutes > 30){
            res= abs(minangle-hourangle);
        } else {
            res= abs(minangle+hourangle);
        }
        res = min(res,360-res);
        return res;
        
    }
};