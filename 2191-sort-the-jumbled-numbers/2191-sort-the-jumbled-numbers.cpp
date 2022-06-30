class Solution {
public:
    static bool mycmp(pair<int,int> a, pair<int, int> b){
        return a.first<b.first;
    }
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        unordered_map<int,int> m;
        for(int i=0;i<mapping.size();i++){
            m[i]=mapping[i];
        }
        vector<pair<int,int>> temp;
        for(int i=0;i<nums.size();i++){
            string temp1=to_string(nums[i]);
            string temp2="";
            for(int j=0;j<temp1.length();j++){
                temp2 += to_string(m[temp1[j]-'0']);
            }
            int temp3 = stoi(temp2);
            temp.push_back({temp3,i});
        }
        sort(temp.begin(),temp.end(),mycmp);
        vector<int> res;
        for(int i=0;i<temp.size();i++){
            res.push_back(nums[temp[i].second]);
        }
        return res;
    }
};