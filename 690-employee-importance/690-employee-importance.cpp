/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    void helper(int id, unordered_map<int,int>& m, int& res,
               unordered_map<int, vector<int>>& m1){
        res+=m[id]; 
        for(int i=0;i<m1[id].size();i++){
            helper(m1[id][i],m,res,m1);
        }
    }
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, int> m;
        unordered_map<int, vector<int>> m1;
        for(auto i : employees){
            m[i->id]=i->importance;
            m1[i->id] = i->subordinates;
        }
        int res=0;
        helper(id, m, res, m1);
        return res;

    }
};