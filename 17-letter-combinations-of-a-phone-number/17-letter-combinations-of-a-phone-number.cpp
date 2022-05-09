class Solution {
public: 
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.size() == 0) {
            return res;
        }
        else if(digits.size() == 1){
            if(digits[0] == '2'){
                return {"a", "b", "c"};
            }
            else if(digits[0] == '3'){
                return {"d", "e", "f"};
            }
            else if(digits[0] == '4'){
                return {"g", "h", "i"};
            }
            else if(digits[0] == '5'){
                return {"j", "k", "l"};
            }
            else if(digits[0] == '6'){
                return {"m", "n", "o"};
            }
            else if(digits[0] == '7'){
                return {"p", "q", "r", "s"};
            }
            else if(digits[0] == '8'){
                return {"t", "u", "v"};
            }
            else if(digits[0] == '9'){
                return {"w", "x", "y", "z"};
            }
        }
        else if(digits.size() > 1){
            vector<string> temp1 = letterCombinations(digits.substr(0, 1));
            vector<string> temp2 = letterCombinations(digits.substr(1, digits.size()-1));
            for(int i = 0; i < temp1.size(); i++)
                for(int j = 0; j < temp2.size(); j++)
                    res.push_back(temp1[i] + temp2[j]);
        }
        return res;
        
    }
};