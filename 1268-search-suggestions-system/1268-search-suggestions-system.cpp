class Solution {
public:
    
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        unordered_map<string,priority_queue<string>> m;
        vector<vector<string>> res;
        for(int i=0;i<products.size();i++){
            string temp="";
            for(int j=0;j<products[i].length();j++){
                temp+=products[i][j];
                if(m[temp].size()==3){
                    if(products[i]<m[temp].top()){
                        m[temp].pop();
                        m[temp].push(products[i]);   
                    }
                } else {
                    m[temp].push(products[i]);
                }
            }
        }
        string temp1="";
        for(int i=0;i<searchWord.length();i++){
            temp1+=searchWord[i];
            vector<string> temp3;
            while(!m[temp1].empty()){
                temp3.push_back(m[temp1].top());
                m[temp1].pop();
            }
            reverse(temp3.begin(),temp3.end());
            res.push_back(temp3);
        }
        return res;
        
        
    }
};