#include<bits/stdc++.h>
using namespace std;

/*
Bit Manipulation is the act of algorithmically manipulating bits or binary digits.
It is a fast and efficient way to perform operations such as addition, subtraction, multiplication, and division.
Bit manipulation is used in a variety of algorithms and applications, including cryptography, data compression, and computer graphics.
Topics:
 1. Conversion of decimal to binary and vice versa
 2. 1's and 2's complement : 1's complement is the bitwise NOT of a binary number, and 2's complement is the 1's complement plus 1.
 3. Bitwise AND, OR, XOR, NOT , Right Shift, Left Shift
*/

class Solution{
    public:
    // Function to convert decimal to binary
    int decimalToBinary(int n){
        int binary = 0 ;
        int base = 1;
        while(n >0){
            int rem = n % 2 ;
            binary += rem * base;
            n /= 2;
            base *= 10;
        }
        return binary;
    }

    // Function to convert binary to decimal
    int binaryToDecimal(int n){
        int decimal = 0 ;
        int base = 1 ;
        while(n>0)
        {
            int rem = n % 10;
            decimal += rem * base ;
            n /= 10;
            base *= 2;
        }

        return decimal;
    }

    // Function to find the 1's complement of a binary number
    int onesComplement(int n) {
        int temp = n;
        int mask = 0;

        // Create a mask of all 1's with the same number of bits as n
        while (temp) {
            mask = (mask << 1) | 1;
            temp = temp >> 1;
        }

        // XOR n with the mask to flip all bits
        return n ^ mask;
    }

    int twoComplement(int n){
        return onesComplement(n) + 1;
    }

    //BitWise operator and their use and working
    int bitwiseOperator(int n)
    {
        // Bitwise AND
        cout << "Bitwise AND: " << (n & 1) << endl;

        // Bitwise OR
        cout << "Bitwise OR: " << (n | 1) << endl;

        // Bitwise XOR
        cout << "Bitwise XOR: " << (n ^ 1) << endl;

        // Bitwise NOT
        cout << "Bitwise NOT: " << (~n) << endl;
        
        // Right Shift
        cout << "Right Shift: " << (n >> 1) << endl;

        // Left Shift
        cout << "Left Shift: " << (n << 1) << endl;
        
        return 0;
    }
};

int main(){
    Solution obj;
    int n = 10;
    cout << obj.bitwiseOperator(n) << endl;
    return 0;
}