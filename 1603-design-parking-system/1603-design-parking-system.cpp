class ParkingSystem {
public:
    unordered_map<int,int> m;
    ParkingSystem(int big, int medium, int small) {
        m[1]=big;
        m[2]=medium;
        m[3]=small;
    }
    
    bool addCar(int carType) {
        if(m[carType]>0){
            m[carType]--;
            return true;
        }
        return false;
        
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */