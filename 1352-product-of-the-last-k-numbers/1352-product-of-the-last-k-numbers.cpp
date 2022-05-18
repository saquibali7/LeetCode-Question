class ProductOfNumbers {
public:
    vector<int> temp;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if(num==0){
            temp.clear();
        } else if(temp.size()==0){
            temp.push_back(num);
        } else {
            temp.push_back(temp[temp.size()-1]*num);
        }
    }
    
    int getProduct(int k) {
        int res;
        if(temp.size()<k){
            return 0;
        } else if(k==temp.size()){
            return temp[temp.size()-1];
        }
        else {
            res=temp[temp.size()-1]/temp[temp.size()-k-1];
        }
        return res;
        
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */