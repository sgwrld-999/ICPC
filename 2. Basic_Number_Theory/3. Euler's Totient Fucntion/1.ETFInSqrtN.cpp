#include<bits/stdc++.h>
using namespace std;

class solution{
    int phiInN(int n){
        int ctr = 0 ;
        for(int i = 1 ; i <= n ; i++){
            if(__gcd(i , n) == 1){
                ctr++;
            }
        }
    }
    int phiInSqrtN(int n){
        int result = n ;

        for(int i = 2 ; i * i <= n ; i++){
            if(n % i == 0){
                while(n % i == 0){
                    n /= i;
                }
                result -= result / i;
            }
        }
    }
};
