class FindSumPairs {
public:
    vector<int> temp1, temp2;
    unordered_map<int, int> m;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        temp1=nums1;
        temp2=nums2;
        for(auto i : nums2){
            m[i]++;
        }
    }
    
    void add(int index, int val) {
        m[temp2[index]]--;
        temp2[index]+=val;
        m[temp2[index]]++;
    }
    
    int count(int tot) {
        int count=0;
        for(auto i : temp1){
            if(m.find(tot-i)!=m.end()){
                count+=m[tot-i];
            }
        }
        return count;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */