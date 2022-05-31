class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> temp;
        temp.push_back({1});
        temp.push_back({1,1});
        for(int i=2;i<=rowIndex;i++){
            vector<int> temp1;
            temp1.push_back(1);
            for(int j=1;j<i;j++){
                temp1.push_back(temp[i-1][j-1]+temp[i-1][j]);
            }
            temp1.push_back(1);
            temp.push_back(temp1);
        }
        return temp[rowIndex];
    }
};