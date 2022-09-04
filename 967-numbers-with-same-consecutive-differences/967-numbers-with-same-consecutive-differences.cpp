class Solution {
public:
    vector<int> res;
    unordered_set<int> s;
    void helper(int k,int n, string temp){
        if(temp.size() == n){
            if(s.find(stoi(temp))==s.end()){
                res.push_back(stoi(temp));
                s.insert(stoi(temp));
            }
            return;
        }
        string temp1=temp;
        string temp2=temp;
        if((temp1[temp1.size()-1] - '0')+k <=9 &&
          (temp1[temp1.size()-1] - '0')+k >=0){
            temp1+=to_string((temp1[temp1.size()-1] - '0')+k);
            helper(k,n,temp1);
        }
        if((temp2[temp2.size()-1] - '0')-k <=9 &&
          (temp2[temp2.size()-1] - '0')-k >=0 ){
            temp2+=to_string((temp2[temp2.size()-1] - '0')-k);
            helper(k,n,temp2);
        }    
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        for(int i=1;i<=9;i++){
            string temp="";
            temp+=to_string(i);
            helper(k,n,temp);
        }
        return res;
        
    }
};