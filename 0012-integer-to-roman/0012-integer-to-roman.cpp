class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int, string>> temp;
        temp.push_back({1000, "M"});
        temp.push_back({900, "CM"});
        temp.push_back({500, "D"});
        temp.push_back({400, "CD"});
        temp.push_back({100, "C"});
        temp.push_back({90, "XC"});
        temp.push_back({50, "L"});
        temp.push_back({40, "XL"});
        temp.push_back({10, "X"});
        temp.push_back({9, "IX"});
        temp.push_back({5, "V"});
        temp.push_back({4, "IV"});
        temp.push_back({1, "I"});
        string res="";
        while(num > 0){
            for(int i=0;i<temp.size();i++){
                int d = num/temp[i].first;
                for(int j=0;j<d;j++){
                    res+=temp[i].second;
                }
                num = num%temp[i].first;
            }
        }
        
        return res;
        
    }
};