#include<bits/stdc++.h>
#include<iostream> 
using namespace std;

bool checkOdd(int n){
    return n%2 != 0;
}

bool checkEven(int n){
    return n%2 == 0;
}
void pattern11(int n){
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1 ; j <= i-1; j++)
        {
            cout << " " ;
        }
        for (int l = n-i ; l >= 0 ; l--)
        {
            if(i%2 != 0 && l%2 == 0){
                cout << "*";
            }
            else if(i%2 != 0 && l%2 != 0){
                cout << " ";
            }
            else if(i%2 == 0 && l%2 != 0){
                cout << "*";
            }
            else{
                cout << " ";
            }
        }
        for(int k = n - i ; k >= 0 ; k--){
            if(i%2 != 0 && k%2 == 0){//odd & Even
                cout << " ";
            }
            else if(i%2 != 0 && k%2 != 0){//odd & odd
                cout << "*";
            }
            else if(i%2 == 0 && k%2 != 0){//Even & odd
                cout << "*";
            }
            else{//Even & Even
                cout << " ";
            }
        }
        cout << endl;
        
    }
}

void pattern12(int n){
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1 ; j <= i-1; j++)
        {
            cout << " " ;
        }
        for (int l = n-i ; l >= 0 ; l--)
        {
            if(i%2 != 0 && l%2 == 0){
                cout << "*";
            }
            else if(i%2 != 0 && l%2 != 0){
                cout << " ";
            }
            else if(i%2 == 0 && l%2 != 0){
                cout << "*";
            }
            else{
                cout << " ";
            }
        }
        for(int k = n - i ; k >= 0 ; k--){
            if(i%2 != 0 && k%2 == 0){//odd & Even
                cout << " ";
            }
            else if(i%2 != 0 && k%2 != 0){//odd & odd
                cout << "*";
            }
            else if(i%2 == 0 && k%2 != 0){//Even & odd
                cout << "*";
            }
            else{//Even & Even
                cout << " ";
            }
        }
        cout << endl;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n-i; j++) {
            cout << " ";
        }
        for (int k =  1; k <= i ; k++)
        {
            bool flag = false;
            if(!flag && (k%2 != 0 || k == 1)){
                cout << "*";
                flag = true;
            }
            else{
                cout << " ";
                flag = false;
            }
        }
        for (int l = 1; l <= i ; l++)
        {
            if(i%2 != 0 && l%2 == 0){
                cout << "*";
            }
            else if(i%2 != 0 && l%2 != 0){
                cout << " ";
            }
            else if(i%2 == 0 && l%2 != 0){
                cout << "*";
            }
            else{
                cout << " ";
            }
        }
        
        cout << endl;
    }
}

void pattern13(int n){
    for (int i = 1; i <= n ; i++)
    {
        for (int j = 1 ; j <= n-i ; j++)
        {
            cout << " ";
        }
        bool flag = false;
        for (int k = 1; k <= i ; k++)
        {
            if((!flag) || i == n){
                cout << "*";
                flag = true;
            }   
            else
                cout << " ";
        }
        for (int l = 1; l <= i-1  ; l++)
        {
            if(i == n || i-1 == 1){
                break;
            }
            cout << " ";
        }
        for (int m = 1; m <= i ; m++)
        {
            if(i == n){
                cout << "*";
            }else if(i == 1){
                break;
            }
            else if(i != n){
                cout << "*";
                break;
            }
        }
        cout << endl;
    }
}

void pattern14(int n){
    for (int i = 1; i <= n ; i++)
    {
        for (int j = 1 ; j <= i-1 ; j++)
        {
            cout << " ";
        }
        bool flag = false;
        for(int k =  1; k <= n-i+1 ;  k++)
        {
            if(i == 1){
                cout << "*";
            }else if(!flag){
                cout << "*";
                flag = true;
            }else if(flag){
                cout << " ";
            }
        }
        for (int m =  n - i - 1; m > 0; m--)
        {
            if(i == 1){
                break;
            }
            cout << " ";
        }
        flag = false;
        for (int l =  n - i  ; l > 0; l--)
        {
            
            if(i == 1){
                cout << "*";
            }else if(!flag){
                cout << "*";
                flag = true;
            }
        }
        cout << endl;
    }
    
}

void pattern18(int n){
    for (int i =  1; i <= n; i++)
    {
        for (int j = n - i + 1 ; j >= 1; j--)
        {
            cout << "*";
        }
        for (int k = 1 ; k <= i - 1 ; k++)
        {
            cout << " ";
        }
        for (int l = 1 ; l <= i-1; l++)
        {
            cout << " ";
        }
        for (int m = n-i+1; m >= 1 ; m--)
        {
            cout << "*";
        }
        cout << endl;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1 ; j <= i; j++)
        {
            cout << "*";
        }
        for (int k = n - i + 1; k > 1; k--)
        {
            cout << " ";
        }
        for (int l = n - i + 1; l > 1; l--)
        {
            cout << " ";
        }
        for (int m = 1; m <= i; m++)
        {
            cout << "*";
        }
        
        cout << endl;
    }
}


int main(int argc, char const *argv[])
{
    int n = 5 ;
    pattern18(n);
    return 0;
}
