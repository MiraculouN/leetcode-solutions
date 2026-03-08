/*
 * @lc app=leetcode id=1942277592 lang=cpp
 *
 * DesignParkingSystem
 * 
 * Difficulty: Easy
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class ParkingSystem {
public:
    int big , medium , small;
    ParkingSystem(int big, int medium, int small) {
        this->big= big;
        this->medium = medium;
        this->small= small;
    }
    
    bool addCar(int carType) {
        if(carType==1){
            if(big){
                big--;
                return 1;
            }
            else return 0;
        }
        else if(carType==2){
            if(medium){
                medium--;
                return 1;
            }
            else return 0;
        }
        else if(carType==3){
            if(small){
                small--;
                return 1;
            }
            else return 0;
        }
        else return 0;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */