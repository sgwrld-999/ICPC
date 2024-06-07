#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void swapTwoNumber(int &a, int &b) {
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
    }

    bool isIthBitSet(int num, int i) {
        return (num & (1 << i)) != 0;
    }

    bool isIthBitSet2(int num, int i) {
        return (num & (1 << i)) != 0;
    }

    int setTheIthBit(int num, int i) {
        return num | (1 << i);
    }

    int cleanTheIthBit(int num,int n){
        return num & ~(1 << n);
    }

    int toggleTheIthBit(int num, int n) {
        return num ^ (1 << n);
    } 

    int removeTheLastSet(int num){
        return num & (num - 1);
    }

    bool checkIfItsAPowerOfTwo(int num){
        return (num & (num - 1) == 0);
    }

    int countSetBitsUsingUniaryOperatos(int num){
        int count = 0 ;
        while(num > 1){
            if(num % 2 == 1) count++;
            num = num / 2 ;
        }
        if(num == 1) count++;
    }
    //Dividing the number in half wiht right shift operator is faster than dividing by modulo operator
    int countSetBitsUsingBitOperators1(int num){
        int count = 0 ;
        while(num > 1){
            if(num&1) count++;
            num = num >> 1 ;
        }
        if(num == 1) count++;
    }
    int countSetBitsUsingBitOperators2(int num){
        int count = 0 ;
        while(num > 0){
            count++;
            num = num & (num - 1);
        }
    } 
};

int main() {
    Solution obj;
    int x = 5, y = 10;
    cout << "Before Swapping: x = " << x << " y = " << y << endl;
    obj.swapTwoNumber(x, y);
    cout << "After Swapping: x = " << x << " y = " << y << endl;

    cout << "Is 1st bit set in 5: " << obj.isIthBitSet(5, 1) << endl;
    cout << "Is 2nd bit set in 5: " << obj.isIthBitSet(5, 2) << endl;

    cout << "Is 1st bit set in 5: " << obj.isIthBitSet2(5, 1) << endl;
    cout << "Is 2nd bit set in 5: " << obj.isIthBitSet2(5, 2) << endl;

    cout << "Setting 2nd bit in 5: " << obj.setTheIthBit(5, 2) << endl;

    cout << "Cleaning 2nd bit in 5: " << obj.cleanTheIthBit(5, 2) << endl;

    return 0;
}
