#include<bits/stdc++.h>
using namespace std;
/*
Theory: https://www.geeksforgeeks.org/introduction-to-recursion-data-structure-and-algorithm-tutorials/
*/
//Problem 1 : Print name n times using recursion 
void printName(int n){
    
    if(n == 0) 
        return ;
    cout<<"Siddhant"<<endl;
    printName(n-1);

}

//Summation of first n natural numbers using recursion
int sumationOFFirstNNum(int n){
    if(n == 0) return 0;
    if(n == 1) return 1;
    return (n+sumationOFFirstNNum(n-1));
}
//Given a string check if it's palindrome or not using recursion
bool isPalindrome(string s,int start,int end){
    if(start >= end) return true;
    if(s[start] != s[end]) return false;
    return isPalindrome(s,start+1,end-1);
}
//Reverse a array or string using recursion
void reverseTheArray(int arr[],int start,int end){
    if(start >= end) return ;
    swap(arr[start],arr[end]);
    reverseTheArray(arr,start+1,end-1);
}
//Fibonacci series using recursion
int fibonacci(int n){
    if(n == 0) return 0;
    if(n == 1) return 1;
    return fibonacci(n-1) + fibonacci(n-2);
}
int main(){
    int n = 10;
    // printName(n);
    cout<<sumationOFFirstNNum(n)<<endl;
    // string s = "abba";
    // cout<<isPalindrome(s,0,s.length()-1)<<endl;
    // int arr[] = {1,2,3,4,5};
    // reverseTheArray(arr,0,4);
    // for(int i = 0 ; i < 5 ; i++){
    //     cout<<arr[i]<<" ";
    // }
    
    return 0;
}