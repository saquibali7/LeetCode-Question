class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n=tokens.size();
        stack<int> s;
        int temp1,temp2;
        for(int i=0;i<n;i++){
            if(tokens[i]=="+"){
                temp1=s.top();
                s.pop();
                temp2=s.top();
                s.pop();
                s.push(temp1+temp2);
            }else if(tokens[i]=="-"){
                temp1=s.top();
                s.pop();
                temp2=s.top();
                s.pop();
                s.push(temp2-temp1);
                
            } else if(tokens[i]=="*"){
                temp1=s.top();
                s.pop();
                temp2=s.top();
                s.pop();
                s.push(temp1*temp2);
                
            } else if(tokens[i]=="/"){
                temp1=s.top();
                s.pop();
                temp2=s.top();
                s.pop();
                s.push(temp2/temp1);
                
            } else {
                s.push(stoi(tokens[i]));
            }
        }
        return s.top();
        
    }
};