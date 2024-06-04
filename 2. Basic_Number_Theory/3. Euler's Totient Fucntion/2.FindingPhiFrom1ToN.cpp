#include<bits/stdc++.h>
using namespace std;
/*
Problem : Find the all phi number in the range 1 to n
*/
class solution{

//Brute force approach
/*
Time complexity : O(n * log(log(n)))
Space comlexity : O(n)
*/

int phiFunction(int n){
    int ctr = 0 ;
    for(int i = 1 ; i <= n ; i++){
        if(__gcd(i , n) == 1){
            ctr++;
        }
    }

    return ctr;
}
    int phiInNLogLogN(int n){
        vector<int> phi(n + 1);
        phi[0] = 0;
        phi[1] = 1;

        for(int i = 2 ; i <= n ; i++){
            phi[i] = phiFunction(i);
        }
    }

//Optimized approach
    int phiInSqrtN(int n){
        vector<int> phi(n + 1);
        phi[0] = 0;
        phi[1] = 1;

        for(int i = 2 ; i <= n ; i++){
            phi[i] = i;
        }

        for(int i = 2 ; i <= n ; i++){
            if(phi[i] == i){
                for(int j = i ; j <= n ; j += i){
                    phi[j] = phi[j] / i;
                    phi[j] *= (i - 1);
                }
            }
        }
    }
};
