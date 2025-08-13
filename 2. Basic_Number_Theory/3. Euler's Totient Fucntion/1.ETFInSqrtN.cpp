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
/*

## **Big Idea**

We start with the assumption that **all numbers ≤ n** are coprime to n,
then we **remove** the ones that share any prime factor with n.

---

## **Why result starts as `n`**

Initially, if n were prime, φ(n) would be **n − 1** (all except n itself),
but instead of checking each number, we begin with the **total count** and subtract in bulk.

---

## **Why loop over p from 2 to √n**

Any composite factor of n must have a prime factor ≤ √n.
So we only check primes up to √n.
If `p` divides n, it’s a **prime factor**.

---

## **Key logic: `result -= result / p`**

If `p` divides n:

* All multiples of p ≤ n are **not coprime** to n.
* Fraction of numbers to remove = $\frac{1}{p}$ of the total.

Example for n = 36:

* p = 2 → remove **1/2** of all numbers.
* p = 3 → remove **1/3** of the remaining numbers.

---

## **Why `while (n % p == 0) n /= p;`**

We want **distinct prime factors** only.
If n has $p^a$, we divide it out completely so we don’t process p multiple times.

---

## **Why `if (n > 1)` at the end**

After the loop, if n > 1, that leftover n is a prime factor **larger than √n**,
so we still need to subtract its multiples.

---

## **Dry Run (n = 36)**

* result = 36
* p = 2 divides 36 → divide out all 2’s → n = 9
  result -= result / 2 → result = 36 − 18 = 18
* p = 3 divides 9 → divide out all 3’s → n = 1
  result -= result / 3 → result = 18 − 6 = 12
* n = 1 → loop ends → final result = 12 ✅

---

So in short:

1. Start with all numbers.
2. For each prime factor p of n → remove all multiples of p.
3. Done.

---

*/
/*
Java Implementation:
int GCD(int a, int b){
    if(b == 0) return a;
    return GCD(b, a % b);
}
public ETF(int n){
    Integer result = new Integer(0);

    for(int i = 1 ; i <= n ; i++){
    if(GCD(i,n) == 1) {result++;}
    
    }
}
*/