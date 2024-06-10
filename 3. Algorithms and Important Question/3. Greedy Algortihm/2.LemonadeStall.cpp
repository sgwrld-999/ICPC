#include<bits/stdc++.h>
using namespace std;
/*
Problem name : Lemonade Stall
Problem link: https://leetcode.com/problems/lemonade-change/
Explanation:
We've given an array of bills. We have to find whether we can provide the change to the customers or not.
We have 3 types of bills 5, 10, 20.
We can provide the change in the following ways:
1. If the customer gives 5 then we don't have to provide the change.
2. If the customer gives 10 then we have provide the change of 5.
3. If the customer gives 20 then we have to provide the change of 15 which is 1 five and 1 ten or 3 fives.
If we can provide the change to all the customers then return true otherwise return false.

*/
class Solution {
public:
    bool lemonadeChangeCode1(vector<int>& bills) {
        int five = 0, ten = 0;

        for (int bill : bills) {
            switch (bill) {
                case 5:
                    five++;
                    break;
                case 10:
                    if (five == 0) return false;
                    five--;
                    ten++;
                    break;
                case 20:
                    if (ten > 0 && five > 0) {
                        ten--;
                        five--;
                    } else if (five >= 3) {
                        five -= 3;
                    } else {
                        return false;
                    }
                    break;
                default:
                    return false;
            }
        }

        return true;
    }

    
};

class Solution1 {
public:
    bool lemonadeChangeCode2(vector<int>& bills) {
        int n = bills.size() ;
        int five = 0 ;
        int ten = 0 ;
        int twenty = 0 ;


        for(int i = 0 ; i < n ; i++)
        {
            if(bills[i] == 5) five++;
            else if(bills[i] == 10){
                if(five)
                {
                    five--;
                    ten++;
                }
                else return false;
            }
            else{
                if(ten && five){
                    five--;
                    ten--;
                    twenty++;
                }else if(five >= 3){
                    five -= 3 ;
                    twenty++;
                }
                else return false;
            }
        }

        return true;

    }
};