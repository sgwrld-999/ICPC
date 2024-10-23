#include<bits/stdc++.h>
using namespace std;
/*
GCD of two numbers is the largest number that divides both of them.
A simple way to find GCD of two numbers is to first find divisors of both numbers and then find the common divisors.

Euclidean algorithm is the efficient way to find GCD of two numbers.
The idea is, GCD of two numbers doesn’t change if smaller number is subtracted from a bigger number.

GCD(a, b) = GCD(b, a%b) = GCD(b, a-b) == GCD(b-a,a)

*/ 
int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a%b);
}

int lcm(int a,int b){
    return (a / gcd(a,b)) * b ;
}
int main(int argc, char const *argv[])
{
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << endl;
    return 0;
}
