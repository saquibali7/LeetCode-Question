class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> res;
        int n=ops.size(),count=0;
        for(int i=0;i<n;i++){
            if(ops[i] == "+"){
                res.push_back(res[res.size()-2]+res[res.size()-1]);
            }
            else if(ops[i]=="D"){
                res.push_back(2*res[res.size()-1]);
            } else if(ops[i]=="C"){
                res.pop_back();
                count--;
            } else {
                res.push_back(stoi(ops[i]));
                count++;
            }
        }
        int result=0;
        for(int i=0;i<res.size();i++){
            result+=res[i];
        }
        return result;
    }
};